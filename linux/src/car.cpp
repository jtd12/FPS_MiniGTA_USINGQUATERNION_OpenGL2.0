#include"car.h"


vitres::vitres()
{
	obj=new objloader();
	mesh=obj->load("data/vitres_vehicule.obj",NULL);
	activeMesh=true;
}
vitres::~vitres()
{
	delete obj;
}

void vitres::actif(bool t)
{
	activeMesh=t;
}
void vitres::draw()
{
	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_BLEND) ;
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA) ; 
	if(activeMesh)
	 glCallList(mesh);
	glDisable(GL_BLEND) ;
	glDisable(GL_COLOR_MATERIAL);

	glPopMatrix();
}

car::car(unsigned int name_,unsigned int name2_,unsigned int name3_, const char* n,collisionsphere ccs, float sprints,float normals,float looks,unsigned int sound_40,unsigned int sound_60 , unsigned int sound_100,unsigned int sound_250,
unsigned int frein_sound)
	{
		vv=new vitres();
		mesh=name_;
		mesh2=name2_;
		mesh3=name3_;
		name=n;
		cs=ccs;
		sprintspeed=sprints;
		normalspeed=normals;
		force.change(0.0,-0.5f,0.0);
		setPosition(vector3d(cs.center));
		setSpeed(normalspeed,looks);
		isground=iscollision=issprint=false;
		speed=normals;
		angle=90;
		maxSpeed=2.5f;
		acc=0.01f;
		dec=0.005f;
		turnSpeed=2.0f;
		up=0;
		down=0;
		left=0;
		right=0;
		clavierAct=0;
		s=0;
		a=vector3d(0.0,180.0,0);
		a_touch=0;
		dec2=0.09f;
	    rr=0.0f;
	    rr2=0.0f;
		rot_roue=vector3d(0,0,0);
		rot_volant=vector3d(0,0,0);
		this->sound_40=sound_40;
		this->sound_60=sound_60;
		this->sound_100=sound_100;
		this->sound_250=sound_250;
		this->frein_sound=frein_sound;
	
		//weapons.push_back(wep);
	//	curWeapon=0;
		//isWeapon=true;
		
	}
	
	car::~car()
	{
		delete vv;
		
	}
	void car::show()
	{
		GLfloat m_RotationMatrix[16]= {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
	 //m_RotationMatrix = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
	
	 
	quaternion rotQuat = quaternion(a.x, a.y, a.z);// * m_qRotation;
       rotQuat.RotationMatrix(m_RotationMatrix);
       glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	  glPushMatrix();
	
	  glTranslated(loc.x,loc.y,loc.z);
      glMultMatrixf(m_RotationMatrix);
			  

	  glCallList(mesh);
	  drawVolant();
	  vv->draw();
			
	  drawRoue();
	  glPopMatrix();
	}
	
	void car::drawVolant()
	{	GLfloat m_RotationMatrix[16]= {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
		quaternion rotQuat = quaternion(rot_volant.x, 0, 0);// * m_qRotation;
       rotQuat.RotationMatrix(m_RotationMatrix);
		glPushMatrix();
		glTranslated(-1,-8,0-4);
		glMultMatrixf(m_RotationMatrix);
		glCallList(mesh3);
		glPopMatrix();
	}
	
		void car::drawRoue()
		{
		
			 	GLfloat m_RotationMatrix[16]= {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
			 	quaternion rotQuat = quaternion(0, 0, rot_roue.z);// * m_qRotation;
       rotQuat.RotationMatrix(m_RotationMatrix);
       
       GLfloat m_RotationMatrix2[16]= {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
			 	quaternion rotQuat2 = quaternion(0, rot_roue.y,0);// * m_qRotation;
       rotQuat2.RotationMatrix(m_RotationMatrix2);
       
		   glPushMatrix();
			glTranslated(4.3,-12.1,6.2);
		    glRotated(180,0,0.5,0);
			 glMultMatrixf(m_RotationMatrix);
		
			glCallList(mesh2);
			glPopMatrix();
			glPushMatrix();
			glTranslated(-3.9,-12.1,6.2);
			glMultMatrixf(m_RotationMatrix);
			
			glCallList(mesh2);
			glPopMatrix();
			glPushMatrix();
			glTranslated(-4.1,-12.1,-8.2);
		    glMultMatrixf(m_RotationMatrix2);
			glMultMatrixf(m_RotationMatrix);
		
			glCallList(mesh2);
			glPopMatrix();
			glPushMatrix();
			glTranslated(4.3,-12.1,-8.2);
			glRotated(180,0,0.5,0);
			glMultMatrixf(m_RotationMatrix2);
		    glMultMatrixf(m_RotationMatrix);
			
			glCallList(mesh2);
			glPopMatrix();
		}
		void  car::ecraserEnnemy( sound * audio, bool dead,unsigned int mSound)
		{
			if(dead && (rand()%20)==0)
					  audio->playSound(mSound,cs.center);
		}
		void car::update(std::vector<collisionplane>& collplane)
		{
			
		if(direction.y>=force.y)
			
				direction+=force;
			//setPosition(cs.center+direction);	
			vector3d newPos(getLocation());
			newPos+=direction;
			for(int i=0;i<collplane.size();i++)
				collision::sphereplane(newPos,collplane[i].normal,collplane[i].p[0],collplane[i].p[1],collplane[i].p[2],collplane[i].p[3],cs.r);
				
				 if(getLocation().y<newPos.y)
				  isground=true;
				  else
				   isground=false;
		    	setPosition(newPos);
	
			//setPosition(cs.center+direction);	
		
		
		    /*	if(isWeapon)
		    	
		        	weapons[curWeapon]->update();
					*/
		}
	
		void car::setPosition(vector3d pos)
		{
			cs.center=pos;
			setLocation(pos);
		}
	
		vector3d car::getLocation()
{
	return loc;
}

vector3d car::getRotation()
 {
 	return vector3d(a.x,a.y,a.z);
 }
 void car::setRotation(vector3d r)
 {
 	a=r;
 }
void car::setLocation(vector3d vec)
{
	loc.change(vec);
}
   void car::move()
   {
    loc.x -= sin(a.y*M_PI/180) * s;
    loc.z -= cos(a.y*M_PI/180) * s;
  
   }
   void car::inputSpecial(char key,int x, int y)
{
	switch(key)
	{
		case GLUT_KEY_UP:
		 up=true;
	
		 glutPostRedisplay();
		 break;
		 case GLUT_KEY_DOWN:

		 down=true;	
		 glutPostRedisplay();
		 break;
		 case GLUT_KEY_RIGHT:
	
		 right=true;
		 glutPostRedisplay();
		 break;
		 case GLUT_KEY_LEFT:
		 	
		left=true;
		glutPostRedisplay();
	
	}
}
   void car::inputSpecialUP(char key,int x, int y)
{
	switch(key)
	{
		case GLUT_KEY_UP:
		 up=false;
		 glutPostRedisplay();
		 break;
		 case GLUT_KEY_DOWN:
		 down=false;
		 glutPostRedisplay();	
		 break;
		 case GLUT_KEY_RIGHT:
		 right=false;
		 glutPostRedisplay();
		 break;
		 case GLUT_KEY_LEFT:
		left=false;
		glutPostRedisplay();
		break;
	
	}
}
void car::keyboard(char key, int x, int y)
{
	switch(key)
	{
	
		case  SPACEBAR:
		a_touch=true;
		glutPostRedisplay();
		break;
	}
}
void car::keyboardUP(char key, int x, int y)
{
switch(key)
{

	case  SPACEBAR:
		a_touch=false;
		glutPostRedisplay();
		break;
	}
	}
	
void car::control(sound * audio)
{
	/*
	
			if(state[SDLK_m])
			{
					clavierAct++;
				
				}
				*/
			if(up==1 && speed<=40 && speed>1)
			{
				if(rand()%5==0)
				audio->playSound(sound_40,loc);
			}
				if(up==1 && speed<=60 && speed>40)
			{
				if(rand()%5==0)
				audio->playSound(sound_60,loc);
			}
			
				if(up==1 && speed<=100 && speed>60)
			{
				if(rand()%5==0)
				audio->playSound(sound_100,loc);
			}
				if(up==1 && speed<=250 && speed>100)
			{
				if(rand()%5==0)
				audio->playSound(sound_250,loc);
			}
			
					if(down==1 && speed>=-40 && speed<-1)
			{
				if(rand()%5==0)
				audio->playSound(sound_40,loc);
			}
				if(down==1 && speed>=-60 && speed<-40)
			{
				if(rand()%5==0)
				audio->playSound(sound_60,loc);
			}
			
				if(down==1 && speed>=-100 && speed<-60)
			{
				if(rand()%5==0)
				audio->playSound(sound_100,loc);
			}
				if(down==1 && speed>=-250 && speed<-100)
			{
				if(rand()%5==0)
				audio->playSound(sound_250,loc);
			}
			if(a_touch==1)
			{
					if(rand()%35==0)
				audio->playSound(frein_sound,loc);
			}
			
			
				if(up==1)
				{
					
					rot_roue.z+=4.5f;
				}
					if(down==1)
				{
					rot_roue.z-=4.5f;
				}
				if(right==1)
				{
					rot_roue.y-=1.0f;
					rot_volant.x-=1.0f;
					if(rot_roue.y<-50.0f)
					{
						rot_roue.y=-50.0f;
					}
					if(rot_volant.x<-50.0f)
					{
						rot_volant.x=-50.0f;
					}
				}
				if(right==0 && left==0)
				{
					rot_roue.y=0.0f;
					rot_volant.x=0.0f;
					
				}
			
				if(left==1)
				{
					rot_roue.y+=1.0f;
					rot_volant.x+=1.0f;
						if(rot_roue.y>50.0f)
					{
						rot_roue.y=50.0f;
					}
							if(rot_volant.x>50.0f)
					{
						rot_volant.x=50.0f;
					}
				}
					if(clavierAct>3)
					{
						clavierAct=0;
					}
					
	if(up==1 && speed<maxSpeed)
			{
			
				if(speed<0)
				{
					
					speed+=dec;
			 }
				else
				{
					speed+=acc;
				}
			}
			if(down==1 && speed>-maxSpeed)
			{
				 
				if(speed>0)
				{
				
					speed-=dec;
				}
				else
				{
					speed-=acc;
				}
				
			}
			
			if(up==0 && down==0)
			{
				if(speed-dec>0)
				{
					speed-=dec;
				}
				else if(speed+dec<0)
				{
					speed+=dec;
				}
				else
				{
					speed=0;
				}
			}
			
				if(a_touch==1)
			{
				if(speed-dec2>0)
				{
					speed-=dec2;
				}
				else if(speed+dec2<0)
				{
					speed+=dec2;
				}
				else
				{
					speed=0;
				}
			}

		if(right)
	{
		angle-=turnSpeed*(speed/maxSpeed);
	}
		if(left)
	{
		angle+=turnSpeed*(speed/maxSpeed);
	}
		s=speed;
		a.y=angle;
		
		//angle=turnSpeed;
		
	move();
	
	
	
		
	
}

int car::getUP()
{
	return up;
	
}
int car::getDOWN()
{
	return down;
	
}
int car::getRIGHT()
{
	return right;
	
}
int car::getLEFT()
{
	return left;
	
}
int car::getA()
{
	return a_touch;
}
void car::setA(int A)
{
	a_touch=A;
}
int car::getClavierAct()
{
	return clavierAct;
}
void car::setUP(int num)
{
	up=num;
}
void car::setDOWN(int num)
{
	down=num;
}
void car::setRIGHT(int num)
{
	right=num;
}
void car::setLEFT(int num)
{
	left=num;
}


 float car::getSpeed()
 {
 	return speed;
 }
void car::setSpeed(float s,float speedJoy)
{
	speed=s*speedJoy;
}

float car::getMaxSpeed()
{
	return maxSpeed;
}

collisionsphere car::getCollissionSphere()
	 	{
	 		return cs;
		 }

  
