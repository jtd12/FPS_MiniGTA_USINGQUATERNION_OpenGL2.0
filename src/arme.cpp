#include"arme.h"
#include"quaternion.h"

arme::arme(std::vector<unsigned int> & anim,unsigned int ol,unsigned int na,unsigned int fa,unsigned int ra,vector3d pos,vector3d rot,vector3d apos,vector3d arot,float prec,float aprec,int str,int maxB,int allB,int sp,
		const char * nam,bool isA)
		{
			frames=anim;
			outerview=ol;
			normalAnimation=na;
			reloadAnimation=ra;
			fireAnimation=fa;
			precision=(prec!=0 ? prec: 0.000001);
			aimPrecision=(aprec!=0 ? prec: 0.000001);
			position=pos;
			rotation=rot;
			aimPosition=apos;
			aimRotation=arot;
			strength=str;
			allBullets=allB;
			maxBulletsInMag=maxB;
			speed=sp;
			name=nam;
			position_expected=position;
			rotation_expected=rotation;
			curPos=position;
			curRot=rotation;
			isAim=false;
			isReloading=false;
			isAutomatic=isA;
			isFired=false;
			isTest=true;
			bulletsInMag=maxBulletsInMag;
			lastShot=1000;
			curFrame=0;
			curMode=1;
			
			
			
		}
	arme::~arme()
		{
			
		}
		void arme::update()
		{
	//test();
	lastShot++;
	curFrame++;
	std::cout << curFrame << std::endl;
	if(curMode==1)
	{
		if(curFrame>normalAnimation)
			curFrame=1;
	}else if(curMode==2)
	{
		if(curFrame>normalAnimation+fireAnimation)
		{
			if(isAutomatic && isFired)
			{
				curFrame=normalAnimation;
			}else{
				curMode=1;
				curFrame=2;
			}
		}
	}else if(curMode==3)
	{
		if(curFrame>=normalAnimation+fireAnimation+reloadAnimation-1)
		{
			curMode=1;
			curFrame=2;
			isReloading=false;
		}
	}
	vector3d tmpVec(position_expected-curPos);
	tmpVec.normalize();
//		std::cout << "tmpVec: " << tmpVec;
	tmpVec*=0.3;
	curPos+=tmpVec;
	if(std::labs(position_expected.x-curPos.x)<0.3 && std::labs(position_expected.y-curPos.y)<0.3 && std::labs(position_expected.z-curPos.z)<0.3)
		position_expected=curPos;

	tmpVec.change(rotation_expected-curRot);
	tmpVec.normalize();
	tmpVec*=0.3;
	curRot+=tmpVec;	
	if(std::labs(rotation_expected.x-curRot.x)<0.3 && std::labs(rotation_expected.y-curRot.y)<0.3 && std::labs(rotation_expected.z-curRot.z)<0.3)
		rotation_expected=curRot; 
		}
		
		void arme::show()
		{
			glPushMatrix();
			glTranslatef(curPos.x,curPos.y,curPos.z);
			//glRotatef(curRot.x,1,0,0);
			//glRotatef(curRot.y,0,1,0);
			//glRotatef(curRot.z,0,0,1);
			GLfloat m_RotationMatrix[16]= {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
			quaternion rotQuat = quaternion(curRot.x,0,0);// * m_qRotation;
		    rotQuat.RotationMatrix(m_RotationMatrix);
		    
		    GLfloat m_RotationMatrix2[16]= {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
			quaternion rotQuat2 = quaternion(0,curRot.y,0);// * m_qRotation;
		    rotQuat2.RotationMatrix(m_RotationMatrix2);
		    
		    GLfloat m_RotationMatrix3[16]= {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
			quaternion rotQuat3 = quaternion(0,0,curRot.z);// * m_qRotation;
		    rotQuat3.RotationMatrix(m_RotationMatrix3);
		    
		    glMultMatrixf(m_RotationMatrix);
			glMultMatrixf(m_RotationMatrix2);
			glMultMatrixf(m_RotationMatrix3);
			glCallList(frames[curFrame]);
			glPopMatrix();
		}
		
		bool arme::fire(vector3d & direction,vector3d camDirection)
		{
		if(isReloading)
		return 0;
	if((!isAutomatic && !isFired) || isAutomatic)
	{
		
		if(lastShot>=speed)
		{
			
			if(bulletsInMag>0)
			{
				/*
				if(isAim)
				{
			
					direction.x=camDirection.x+((float)(rand()%2-1)/aimPrecision);
					direction.y=camDirection.y+((float)(rand()%2-1)/aimPrecision);
					direction.z=camDirection.z+((float)(rand()%2-1)/aimPrecision);
				}else{
					direction.x=camDirection.x+((float)(rand()%2-1)/precision);
					direction.y=camDirection.y+((float)(rand()%2-1)/precision);
					direction.z=camDirection.z+((float)(rand()%2-1)/precision);	
				
				}
				*/
				isFired=true;
				lastShot=0;
				bulletsInMag--;
				curFrame=normalAnimation;
				curMode=2;
				return 1;
			}else{
				reload();
				return 0;
			}
		}
	}
	return 0;
		}
		
		void arme::stopFire()
		{
			isFired=false;
		}
		void arme::reload()
		{
			if(!isReloading && maxBulletsInMag!=bulletsInMag)
			{
				isReloading=true;
				if(allBullets>maxBulletsInMag-bulletsInMag)
				{
					allBullets-=maxBulletsInMag-bulletsInMag;
					bulletsInMag=maxBulletsInMag;
				}
				else
				{
					bulletsInMag=allBullets+bulletsInMag;
					allBullets=0;
				}
				curFrame=normalAnimation+fireAnimation;
				curMode=3;
			}
		}
		void arme::test(char key, int x, int y)
		{
			if(isTest)
			{
				switch(key)
				{
					case 'j':
						curPos.x-=(float)0.1f;
						break;
					case 'h':
						curPos.x+=(float)0.1f;
						break;
					case  'g':
						curPos.z-=(float)0.1f;
						break;
					case 'i':
						curPos.z+=(float)0.1f;
						break;
						
					case 'u':
						curRot.y-=0.05f;
						glutPostRedisplay();
						break;
					case 'o':
						curRot.y+=0.05f;
						glutPostRedisplay();
						break;
				}
			}
		}
		void arme::addBullets(unsigned int num)
		{
			allBullets+=num;
		}
		void arme::setBullets(unsigned int num)
		{
			allBullets=num;
		}
		int arme::getStrength()
		{
			return strength;
		}
		int arme::getAmmo()
		{
			return bulletsInMag;
		}
		int arme::getAllAmmo()
		{
			return allBullets;
		}
		void arme::aim()
		{
			isAim=!isAim;
			if(isAim)
			{
				rotation_expected=aimRotation;
				position_expected=aimPosition;
			}
			else
			{
				rotation_expected=rotation;
				position_expected=position;
			}
		}
		std::string arme::getName()
		{
			return name;
		}
		std::vector<unsigned int>& arme::getAnimation()
		{
			return frames;
		}
		bool arme::isAimed()
		{
			return isAim;
		}
		unsigned int arme::getOuterView()
		 {
		 	return outerview;
		 }
		 
		 
		float arme::rot_()
		{
		return axisRot2.y;
		}
		float arme::rot2_()
		{
		return axisRot.z;
		}
		void arme::setRot(float r)
		{
			axisRot2.y=r;
		}
		void arme::setRot2(float r)
		{
			axisRot.z=r;
		}
		vector3d arme::getRotation()
		{
			return curRot;
		}
		vector3d arme::getLocation()
		{
			return curPos;
		}
