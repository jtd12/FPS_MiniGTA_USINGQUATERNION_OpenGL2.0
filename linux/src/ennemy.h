#ifndef DEF_ENNEMY_H
#define DEF_ENNEMY_H
#include <GL/gl.h>
#include <GL/glu.h>
#include<vector>
#include"vector3.h"
#include"collision.h"
#include"collisionsphere.h"
#include"collisionplane.h"
#include<cmath>
#include<iostream>
#include"sound.h"
#include"quaternion.h"
#include<GL/glut.h>
#define pi 3.14159265359 // on definit un nombre pi

class ennemy
{
	std::vector<unsigned int > frames;
	unsigned int walk,attack,die;
	int health;
	unsigned int curFrame;
	int strength;
	float speed;
	vector3d direction,rotation;
	bool isWalk,isAttack,isDead;
	collisionsphere cs;
    unsigned int normalSound,attackSound,mortSound;
    float delay;
	
	public:
		
		ennemy(std::vector<unsigned int>& anim, unsigned int w, unsigned int a, unsigned int d, int h, int str, float sp,collisionsphere css,
		unsigned int normalSound,unsigned int attackSound,unsigned int mortSound);
		~ennemy();
		bool update(std::vector<collisionplane>& collplane,vector3d playerLoc,sound* audio);
		bool follow(vector3d playerLoc);
		void show();
		bool setAttack(collisionsphere player);
		collisionsphere  getCollisionSphere();
		void setLocation(vector3d newLoc);
		void setLocation2(vector3d newLoc);
		void decreaseHealth(int num);
		int getHealth();
		int getStrength();
		bool isDead_();
		vector3d getLocation();
		unsigned int getMortSound();
	
		
};
#endif
