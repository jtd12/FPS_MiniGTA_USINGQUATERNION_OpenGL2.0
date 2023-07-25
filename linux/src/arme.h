#ifndef DEF_ARME_H
#define DEF_ARME_H
#include <GL/gl.h>
#include<GL/glu.h>
#include<stdio.h>
#include<cstdlib>
#include<iostream>
#include"collisionsphere.h"

using namespace std;

class arme
{
	public:
		arme(std::vector<unsigned int> & anim,unsigned int ol,unsigned int na,unsigned int fa,unsigned int ra,vector3d pos,vector3d rot,vector3d apos,vector3d arot,float prec,float aprec,int str,int maxB,int allB,int sp,
		const char * nam,bool isA);
		~arme();
		void update();
		void show();
		bool fire(vector3d & direction,vector3d camDirection);
		void stopFire();
		void reload();
		void test(char key, int x, int y);
		void addBullets(unsigned int num);
		void setBullets(unsigned int num);
		int getStrength();
		int getAmmo();
		int getAllAmmo();
		void aim();
		std::string getName();
		std::vector<unsigned int>& getAnimation();
		bool isAimed();
		unsigned int getOuterView();
		float rot_();
		float rot2_();
		void setRot(float r);
		void setRot2(float r);
		vector3d getLocation();
		vector3d getRotation();
		//void setLocation(vector3d newLoc);
		//vector3d getLocation();
		//void setLocationinc(vector3d newLoc);
		//collisionsphere getCollissionSphere();
		
		private:
			
				std::vector<unsigned int> frames;
				unsigned int outerview;
				unsigned int normalAnimation;
				unsigned int fireAnimation;
				unsigned int reloadAnimation;
				vector3d position_expected;
				vector3d rotation_expected;
				vector3d  axisRot2;
				vector3d  axisRot3;
				vector3d  axisRot;
				collisionsphere cs;
				vector3d position;
				vector3d aimPosition;
				vector3d aimRotation;
				vector3d rotation;
				vector3d curPos;
				vector3d curRot;
				float precision,aimPrecision;
				int strength;
				bool isAim,isReloading,isAutomatic,isFired,isTest;
				unsigned int maxBulletsInMag;
				unsigned int bulletsInMag;
				unsigned int allBullets;
				unsigned int lastShot;
				unsigned int speed;
				unsigned int curFrame;
				unsigned int curMode;
				std::string name;
				
				
				
};
#endif
