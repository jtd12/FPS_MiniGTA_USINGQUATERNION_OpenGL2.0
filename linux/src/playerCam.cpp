#include"playerCam.h"

playerCam::playerCam(const char * n,collisionsphere ccs,float sprints,float normals,float looks,arme* wep,int attackSound)
{
	name=n;
	cs=ccs;
	sprintspeed=sprints;
	normalspeed=normals;
	force.change(0,-0.1f,0);
	setPosition(ccs.center);
	cam.setSpeed(normalspeed,looks);
	isground=iscollision=issprint=false;
	energy=20;
	bulletDelay=0.1f;
	rot=0.0f;
	rot2=0.0f;
	points=0;
	energy=10;
	health=100;
	///arm=new arme(collisionsphere(vector3d(0,0,0),2.0),mesh);
	balleVisible=false;
	weapons.push_back(wep);
	curWep=0;
	headPosition=0;
	dir=vector3d(0,0,0);
	headUp=false;
	this->attackSound=attackSound;	
 
}
playerCam::~playerCam()
{
	for(int i=0;i<weapons.size();i++)
	  delete weapons[i];
	for (int i=0;i<ball.size();i++)
	  delete ball[i];
	
}
void playerCam::updateArme()
{
/*
arm->setLocation(vector3d(cam.getLocation().x,cam.getLocation().y,cam.getLocation().z));
arm->setRot(cam.getYaw());
arm->setRot2(cam.getPitch());
*/
}
void playerCam::showArme()
{
	//arm->show();
 
	weapons[curWep]->show();
	 
}
void playerCam::showBalle()
{
	
	for(int i=0;i<ball.size();i++)
	 ball[i]->draw();
}
void playerCam::updateBalle()
{
	

	for(int i=0;i<ball.size();i++)
		{
    dir=vector3d(-0.9*sin(ball[i]->getRotation().y*pi/180),0.9*sin(ball[i]->getRotation().x*pi/180),-0.9*cos(ball[i]->getRotation().y*pi/180));

	 ball[i]->setLocationinc(vector3d(dir));
		//ball[i]->setLocationinc(vector3d(0,0,-0.1));
			//ball[i]->xpos(0.05f*sin(ball[i]->rot_()*pi/180));
			//ball[i]->ypos(0.05f*sin(ball[i]->rot2_()*pi/180));
			//ball[i]->zpos(0.05f*cos(ball[i]->rot_()*pi/180));
			
		}
		
		
	
}
void playerCam::tirer()
{
	
	
	ball.push_back(new balle(collisionsphere(vector3d(cam.getLocation().x,cam.getLocation().y,cam.getLocation().z),30.0f),cam.getYaw(),cam.getPitch())); 
	
	/*	for(int i=0;i<ball.size();i++)
				{
				
	//ball[i]->xpos2(cam.getLocation().x);
	//ball[i]->ypos2(cam.getLocation().y);
//	ball[i]->zpos2(cam.getLocation().z);

	ball[i]->setRot(arm->rot_());
	ball[i]->setRot2(arm->rot2_());
}
*/

balleVisible=true;

}
void playerCam::inputSpecial(char key,int x, int y,sound * audio, bool dead, unsigned int mSound)
{


	switch(key)
	{
		case 32:
			setJump();
			break;
		
	
	case 'q':
		setSprint();
		break;
		case 'v':
		  audio->playSound(attackSound,cs.center);
		  if(dead && (rand()%20)==0)
					  audio->playSound(mSound,cs.center);
	      tirer();
	      
			break;
				
}
}
void playerCam::relacherSpecial(char key,int x, int y)
{
	switch(key)
	{
		case 'q':
		stopSprint();
		break;	
		
	
}
}
void playerCam::setSprint()
{
	if(energy>30.0)
	{
		issprint=true;
		cam.setSpeed(sprintspeed,cam.getMousevel());
	}
	else
	{
		issprint=false;
	}
}
void playerCam::stopSprint()
{
	issprint=false;
		cam.setSpeed(normalspeed,cam.getMousevel());
}
void playerCam::setJump()
{
	if(isground)
	{
		direction.y=2.0f;
		isground=false;
	}
}
void playerCam::update(std::vector<collisionplane>& collplane)
{
		if(direction.y>=force.y)
			direction+=force;
			vector3d newPos(cam.getLocation());
	 		newPos+=direction;
	 			vector3d oldpos(newPos);
	 		for(int i=0;i<collplane.size();i++)
				collision::sphereplane(newPos,collplane[i].normal,collplane[i].p[0],collplane[i].p[1],collplane[i].p[2],collplane[i].p[3],cs.r);
	 				if(oldpos.y<newPos.y)
	 				{
					 isground=true;
				}
				else
				{
					isground=false;
				}
	 		setPosition(newPos);
	  
	 		weapons[curWep]->update();
	 		
	 	
	 			if(issprint)
	 			{
	 				energy-=1.5;
				 }
				 else if(energy<50)
				 {
				 	energy+=0.5;
				 }
				 if(issprint && energy<=0.0)
				 {
				 	stopSprint();
				 }
				 if(cam.isMoved())
				 {
				
				 	if(headUp)
				 	{
				 		headPosition+=10;
				 		if(headPosition>=50)
				 		{
				 			headUp=false;
						 }
					}
						 else
						 {
						 		headPosition-=10;
				 		if(headPosition<=-50)
				 		{
				 			headUp=true;
						 }
						 }
						  	cam.lookAt(cam.getPitch()+(float)headPosition/300.0,cam.getYaw());
						 
					 }
				 
}

void playerCam::setPosition(vector3d pos)
{
	cs.center=pos;
	cam.setLocation(pos);
}

		vector3d playerCam::getLocation()
{
	return loc;
}
	 	void playerCam::setLocation(vector3d newLoc)
	 	{
	 		cs.center+=newLoc;
	 		cam.setLocation2(newLoc);
		 }
		 void playerCam::setLocation2(vector3d newLoc)
		 {
		    cs.center=newLoc;
		 	cam.setLocation(newLoc);
		 }
		 
		
		
		
	collisionsphere playerCam::getCollissionSphere()
	 	{
	 		return cs;
		 }
		 bool playerCam::isVisible()
		 {
		 	return balleVisible;
		 }
		 
		 int playerCam::getCurrentWeapon()
		 {
		 	return curWep;
		 }
		 void playerCam::addWeapon(arme* wep)
		 {
		 	weapons.push_back(wep);
		 }
			void playerCam::changeWeapon(int num)
			 {
		 	if(weapons.size()>num)
		 	{
		 		curWep=num;
			 }
		 }
			void playerCam::changeWeaponDown()
			 {
		 	curWep--;
		 	if(curWep<0)
		 	{
		 		curWep=weapons.size()-1;
			 }
		 }
		 
			void playerCam::changeWeaponUp()
			 {
		 	curWep++;
		 	if(curWep>=weapons.size())
		 	{
		 		curWep=0;
			 }
		 }
			arme * playerCam::getCurWeapon()
			 {
		 	return weapons[curWep];
		 }
			void playerCam::haveWeapon(bool b)
			 {
		 	isWeapon=b;
		 }
		 int playerCam::getHealth()
		 {
		 	return health;
		 }
		 int playerCam::getPoints()
		 {
		 	return points;
		 }
		 void playerCam::setHealth(int h)
		 {
		 	health=h;
		 }
		 void playerCam::addPoints(int p)
		 {
		 	points+=p;
		 }
