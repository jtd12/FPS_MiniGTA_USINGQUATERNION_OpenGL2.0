#ifndef DEF_PLAYER_H
#define DEF_PLAYER_H
#include <GL/gl.h>
#include <GL/glu.h>
#include<vector>
#include"vector3.h"
#include"collision.h"
#include"collisionsphere.h"
#include"collisionplane.h"
#include"camera.h"
#include<cmath>
#include<iostream>
#include<C:/library/freeglut/include/GL/glut.h>
#define pi 3.14159265359 // on definit un nombre pi

class player
{
	public:
		player();
player(std::vector<unsigned int>& anim,unsigned int a, float sp, collisionsphere ccs);
		~player();

	void update(std::vector<collisionplane>& collplane);
	void show();
	 	collisionsphere getCollissionSphere();
	 		void setPosition(vector3d pos);
			void setSpeed(float mv,float gv);
		void setLocation(vector3d  loc);
			vector3d getLocation();
	float setLocationX();
	float setLocationZ();
		float setLocationY();
			void setTranslationForward();
	 	void setTranslationBack();
	 	void setRotationRight();
	 	void setRotationLeft();
	 	bool getRot();
		vector3d direction,rotation;
	 	collisionsphere cs;
	 	bool getUP();
	 	bool getDown();
	 	bool getLeft();
	 	bool getRight();
	 	void setUP(bool);
	 	void setDown(bool);
	 	void setRight(bool);
	 	void setLeft(bool);
	 		float getRotation();
	 		void setJump();
	 			bool anim1;
	private:
		unsigned int w;
		float speed;
	std::vector<unsigned int> frames;
	unsigned int a_;
	bool up,down,right,left;
	float curFrame;

	int mesh;
	std::string file_;
		vector3d force;
	bool isground,iscollision, issprint;
		vector3d loc;
		float rot;
		
		
};
#endif
