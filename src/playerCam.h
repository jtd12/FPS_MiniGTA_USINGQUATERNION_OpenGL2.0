#ifndef DEF_PLAYERCAM_H
#define DEF_PLAYERCAM_H
#include <GL/gl.h>
#include <GL/glu.h>
#include<vector>
#include"vector3.h"
#include"collision.h"
#include"collisionsphere.h"
#include"collisionplane.h"
#include"objloader.h"
#include"camera.h"
#include<cmath>
#include<iostream>
#include"arme.h"
#include"balle.h"
#include"sound.h"
#include<C:\library\freeglut\include\GL\freeglut.h>
#define pi 3.14159265359 // on definit un nombre pi

class playerCam
{
public:
	playerCam(const char * n,collisionsphere ccs,float sprints,float normals,float looks,arme* wep,int attackSound);
	~playerCam();
	camera cam;
void showBalle();
void updateBalle();
void tirer();
	void update(std::vector<collisionplane>& collplane);
	void updateArme();
	void showArme();
	 	collisionsphere getCollissionSphere();
	 		void setPosition(vector3d pos);
	 		void setLocation(vector3d  loc);
	 		void setLocation2(vector3d newLoc);
			vector3d getLocation();
			void inputSpecial(char key,int x, int y,sound* audio,bool dead, unsigned int mSound);
			void setJump();
			void setSprint();
			void stopSprint();
			void relacherSpecial(char key,int x, int y);
			int getPoints();
			int getHealth();
			void setHealth(int h);
			void addPoints(int p);
			void addWeapon(arme* wep);
			void changeWeapon(int num);
			void changeWeaponDown();
			void changeWeaponUp();
			arme * getCurWeapon();
			void haveWeapon(bool b);
			std::vector<balle*> ball;
			bool isVisible();
			std::vector<arme*> weapons;
			int getCurrentWeapon();
	    	vector3d dir;
			
private:
		unsigned int w;
		float speed;
		int points;
		std::vector<unsigned int> frames;
		unsigned int a_;
		bool up,down,right,left;
		float curFrame;
		std::string name;
		int mesh;
		std::string file_;
		vector3d force;
		bool isground,iscollision, issprint;
		int headPosition;
		bool headUp;
		vector3d loc;
		float rot;
		float rot2;
		float energy;
		float 	sprintspeed;
		float normalspeed,lookSpeed;
		vector3d rotation;
  		bool balleVisible;
		float bulletDelay;
		int curWep;
		int health;
		//arme *arm;
		bool isWeapon;
		collisionsphere cs;
		vector3d direction;
		unsigned int attackSound;
};
#endif
