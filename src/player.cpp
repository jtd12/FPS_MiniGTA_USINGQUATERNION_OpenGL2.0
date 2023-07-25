#include"player.h"
player::player()
{
	
}
player::player(std::vector<unsigned int>& anim,unsigned int a, float sp, collisionsphere ccs)
{

		speed=sp;
		cs=ccs;
		frames=anim;
		w=a;
		up=false;
		down=false;
		right=false;
		left=false;
		rot=0;
		anim1=false;
}
player::~player()
{
	
}
void player::show()
{
	glPushMatrix();
	glTranslatef(cs.center.x,cs.center.y,cs.center.z);
	glRotatef(rot,0,0.5f,0);

	glCallList(frames[curFrame]);
	glPopMatrix();
}


void player::update(std::vector<collisionplane>& collplane)
{
		 	
		 		if(anim1)
	 		{
	 			
	 				curFrame++;
	 				
			if(curFrame>=25)
			{
				curFrame=0;
			}
			 }
	if(anim1==false)
	{
		curFrame=1;
	}
					vector3d newPos(cs.center);
	 			newPos.y-=0.1f;
	 			
	 		for(int i=0;i<collplane.size();i++)
				collision::sphereplane(newPos,collplane[i].normal,collplane[i].p[0],collplane[i].p[1],collplane[i].p[2],collplane[i].p[3],cs.r);
	 				setLocation(newPos);
	 			
}

	collisionsphere player::getCollissionSphere()
	 	{
	 		return cs;
		 }
		 	void player::setLocation(vector3d newLoc)
	 	{
	 		cs.center=newLoc;
		 }
	 	void player::setTranslationForward()
	 	{
	 		anim1=true;
	 	

	
	 		cs.center.x-=0.09*cos(rot*pi/180);
	 		cs.center.z+=0.09*sin(rot*pi/180);
		 }
		void player::setTranslationBack()
	 	{
	 			anim1=true;
	 	
	 		cs.center.x+=0.09*cos(rot*pi/180);
	 		cs.center.z-=0.09*sin(rot*pi/180);
		 }
		 void player::setRotationRight()
		 {
		 	rot-=4.5;
		 }
		  void player::setRotationLeft()
		 {
		 	rot+=4.5;
		 }
   		void player::setSpeed(float mv,float gv)
		{
			
		}
		void player::setPosition(vector3d pos)
		{
			cs.center=pos;
			setLocation(pos);
		}
	
		vector3d player::getLocation()
{
	return loc;
}
void player::setUP(bool up_)
{
	up=up_;
}
bool player::getUP()
{
return up;
}
void player::setDown(bool down_)
{
	down=down_;
}
bool player::getDown()
{
return down;
}
void player::setLeft(bool left_)
{
	left=left_;
}
bool player::getLeft()
{
return left;
}
void player::setRight(bool right_)
{
	right=right_;
}
bool player::getRight()
{
return right;
}
float player::getRotation()
{
	return rot;
}
float player::setLocationX()
{
	return cs.center.x;
}
float player::setLocationZ()
{
	return cs.center.z;
}
float player::setLocationY()
{
	return cs.center.y;
}
void player::setJump()
{
	if(isGround)
	{
		direction.y=5.0f;
		isground=false;
	}
}
