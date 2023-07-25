#include"ennemy.h"

	ennemy::ennemy(std::vector<unsigned int>& anim, unsigned int w, unsigned int a, unsigned int d, int h, int str, float sp,collisionsphere css,unsigned int normalSound,unsigned int attackSound,unsigned int mortSound)
	{
	
	curFrame=1;
	frames=anim;
	walk=w;
	attack=a;
	die=d;
	strength=str;
	health=h;
	cs=css;
	speed=sp;
	isWalk=true;
	isAttack=isDead=false;
	this->normalSound=normalSound;
	this->attackSound=attackSound;
	this->mortSound=mortSound;
		
	}
		ennemy::~ennemy()
		{
			
		}
	
	

		bool ennemy::update(std::vector<collisionplane>& collplane,vector3d playerLoc,sound* audio)
		{
	
			 if(!isDead)
			 {
			 	
			 

	     	direction.change(playerLoc-cs.center);


			direction.normalize();
	
			vector3d newPos(cs.center);
			
				newPos.y-=0.1;
				if(!isAttack)
			      newPos+=direction*speed;
		
				for(int i=0;i<collplane.size();i++)
				collision::sphereplane(newPos,collplane[i].normal,collplane[i].p[0],collplane[i].p[1],collplane[i].p[2],collplane[i].p[3],cs.r);
	 				setLocation(newPos);
	 				rotation.y=std::acos(direction.z);
	 				if(direction.x>0)
	 				{
	 					rotation.y=-rotation.y;
					 }
			}
				if(health<=0 && !isDead)
				{
					isDead=true;
					isWalk=isAttack=false;
					curFrame=walk+attack;
			        
					return 1;
				}
					curFrame++;
				
					if(isWalk && (rand()%90)==0)
						audio->playSound(normalSound,cs.center);
						
				    if(isAttack && (rand()%100)==0)
						audio->playSound(attackSound,cs.center);
				
				    
					if(isWalk && curFrame>=walk)
					{
				
						curFrame=0;
					}
					else if(isAttack && curFrame>=walk+attack)
					{
					 
						curFrame=walk;
					}
					else if(isDead && curFrame>=walk+attack+die)
					{
					
						curFrame=walk+attack+die-1;
					}
					
				
			/*	setLocation(newPos);
				
				vector3d newPos(cs.center);
			    newPos.y-=0.08f;
			    */
				return 0;
	 				
	 				
	 	
		}
		void ennemy::show()
		{
		
			
		
			
	glPushMatrix();
	glTranslated(cs.center.x,cs.center.y,cs.center.z);
	//glRotated(-rotation.x*(180/M_PI),1.0,0,0);
	//glRotated(-rotation.y*(180/M_PI),0.0,1.0,0);
	//glRotated(-rotation.z*(180/M_PI),0.0,0,1.0);
	GLfloat m_RotationMatrix[16]= {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
	quaternion rotQuat = quaternion(-rotation.x*(180/M_PI),0,0);// * m_qRotation;
	rotQuat.RotationMatrix(m_RotationMatrix);
		    
	GLfloat m_RotationMatrix2[16]= {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
	quaternion rotQuat2 = quaternion(0,-rotation.y*(180/M_PI),0);// * m_qRotation;
	rotQuat2.RotationMatrix(m_RotationMatrix2);
		    
	GLfloat m_RotationMatrix3[16]= {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
	quaternion rotQuat3 = quaternion(0,0,-rotation.z*(180/M_PI));// * m_qRotation;
	rotQuat3.RotationMatrix(m_RotationMatrix3);
		    
	glMultMatrixf(m_RotationMatrix);
	glMultMatrixf(m_RotationMatrix2);
	glMultMatrixf(m_RotationMatrix3);
	glScaled(1.0,1.0,1.0);
	glCallList(frames[curFrame]);
	glPopMatrix();
		}
		bool ennemy::setAttack(collisionsphere player)
		{
			if( !isDead && collision::spheresphere(player.center,player.r,cs.center,cs.r))
			{
				isAttack=true;
				isWalk=false;
				return 1;
				
				
			}
			else
			{
				isAttack=false;
				if(!isDead)
				  isWalk=true;
				return 0;
			}
		}
		collisionsphere  ennemy::getCollisionSphere()
		{
				return cs;
		}
		void ennemy::setLocation(vector3d newLoc)
		{
			cs.center=newLoc;
		}
		 	void ennemy::setLocation2(vector3d newLoc)
	 	{
	 		cs.center+=newLoc;
	 	
		 }
		vector3d ennemy::getLocation()
		{
			return cs.center;
		}
		
	 void ennemy::decreaseHealth(int num)
	 {
	 	health-=num;
	 }
	 bool ennemy::isDead_()
	 {
	 	return isDead;
	 }
	int ennemy::getStrength()
		{
			return strength;
		}
		int ennemy::getHealth()
		{
			return health;
		}
	unsigned int ennemy:: getMortSound()
	{
		return mortSound;
	}
