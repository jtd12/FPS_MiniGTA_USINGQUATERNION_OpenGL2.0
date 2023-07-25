#ifndef DEF_SETUP_H
#define DEF_SETUP_H
#include <windows.h>
#include <gl/gl.h>
#include<gl/glu.h>
#include<stdio.h>
#include"collisionplane.h"
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include<cstdlib>
#include"vector3.h"
#include"player.h"
#include"objloader.h"
#include"level.h"
#include<time.h>
#include"playerCam.h"
#include"car.h"
#include"ennemy.h"
#include"sound.h"
#include <iostream>
#include <conio.h>
#include <mmsystem.h>
#include <sstream>
using namespace std;

class setup
{
public:
	setup();
	~setup();
 void update();
 void passiveMotion(int x, int y);
 void show();
void reshape(int width,int height);
 void passiveKeyboard(char key,int x,int y);
void clavierActif();
void init();
void controlKeyboard(char key,int x, int y);
void controlCamera();
void drawFloor();
void drawElement();
void cameraFollowCar();
void changerDriver(char key,int x,int y);
void mouseMotion(int x,int y);
void controlSpecialKeyboard(int key,int x, int y);
void controlSpecialPassiveKeyboard(int key,int x, int y);
void lighting();
std::string int2str(int x);
std::string float2str(float x);
void  drawText(float x, float y, std::string text);
void enable2D(int width, int height);
float float_rand( float min, float max );
void fireWeapon(char key, int x, int y);
void changeWeapon_(char key, int x, int y);
void stopFire(char key, int x, int y);
void changeWeaponUp(char key, int x, int y);
void changeWeaponDown(char key, int x, int y);
void fog();
void cameraInsideCar();
void changeCamera(char key, int x, int y);

  
private:

   	objloader obj;
   	sound* audio;
   	std::vector<car*> vehicule;
  	std::vector<level*> levels;
  	std::vector<arme*> weapons;
  	std::vector<ennemy*> zombies;
  	playerCam *playerCam_;
	vector3d direction; 
	bool changeWeapon;
	bool changeVehicule;
	bool dist;
	int changeCam;


};


#endif


