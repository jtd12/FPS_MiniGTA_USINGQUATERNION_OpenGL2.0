#ifndef CAR_H
#define CAR_H
#include<GL/gl.h>
#include<GL/glu.h>
#include"vector3.h"
#include"collisionplane.h"
#include"collisionsphere.h"
#include"camera.h"
#include<string>
#include<vector>
#include<math.h>
#include"collision.h"
#include"quaternion.h"
#include"sound.h"
#define ni 8
#define SPACEBAR 32



class car
{
	int mesh2;
	int mesh3;
	int mesh;
	std::string name;
	collisionsphere cs;
	vector3d force;
	vector3d direction;
	bool isground,iscollision, issprint;
	float sprintspeed,normalspeed;
	float lookspeed;
	vector3d pos;
	float acc, dec,dec2;
	float s;
	vector3d a;
	vector3d loc;
	vector3d rot_roue;
	vector3d rot_volant;
	int up,down,left,right,clavierAct,a_touch;
 	float angle;
	float turnSpeed;
	float speed;
	float maxSpeed;	
float rr,rr2;

unsigned int sound_40;
unsigned int sound_60;
unsigned int sound_100;
unsigned int sound_250;
unsigned int frein_sound;

	public:

car(unsigned int name,unsigned int name2_, unsigned int name3_,const char* n,collisionsphere ccs, float sprints,float normals,float looks,
unsigned int sound_40,unsigned int sound_60 , unsigned int sound_100,unsigned int sound_250,unsigned int frein_sound);
		~car();
		void update(std::vector<collisionplane>& collplane);
		void  ecraserEnnemy( sound * audio,bool dead,unsigned int mSound);
		void show();
		void drawRoue();
		void setPosition(vector3d pos);
			void setLocation(vector3d vec);
			vector3d getLocation();
			void control(sound * audio);
			void move();
			void setRotation(vector3d r);
			vector3d getRotation();
			int getUP();
			int getDOWN();
			int getRIGHT();
			int getLEFT();
			int getClavierAct();
			void setUP(int num);
			void setDOWN(int num);
			void setRIGHT(int num);
			void setLEFT(int num);
			void setA(int A);
			int getA();
			void moveai();
			void initialiseai();
		float setSpeed(float num);
		void setSpeed(float s,float speedJoy);
		void moveAI();
		float getSpeed();
		float getMaxSpeed();
		void setjoy(float j);
		void setJoyTurnSpeed(bool a);
		void setTurn(bool a);
		bool getTurn();
		float getJoy();
		void keyboard(char key, int x, int y);
		void keyboardUP(char key, int x, int y);
		void inputSpecial(char key,int x, int y);
		void inputSpecialUP(char key,int x, int y);
		collisionsphere getCollissionSphere();
		void drawVolant();
	     
	};
	#endif
