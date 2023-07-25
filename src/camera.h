#ifndef CAMERA_H
#define CAMERA_H
#include <cmath>
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include "vector3.h"
#include"quaternion.h"

class camera{

	vector3d  axisRot;
	vector3d  axisRot2;
	float movevel;
	float mousevel;
	bool mi,ismoved;
	void lockCamera();
	void moveCamera(float dir);
	void moveCameraUp(float dir);
	bool up,down,right,left;

  
				
	public:
	
		camera();
		camera(vector3d loc);
		camera(vector3d loc,float yaw,float pitch);
		camera(vector3d loc,float yaw,float pitch,float mv,float mov);

		void Control();
		void UpdateCamera();
		vector3d getVector();
		vector3d getLocation();
		float getPitch();
		float getYaw();
		float getMovevel();
		float getMousevel();
		bool isMouseIn();
		vector3d loc;
		void setLocation(vector3d vec);
				void setLocation2(vector3d vec);
		void lookAt(float pitch,float yaw);
		void mouseIn(bool b);
		void setSpeed(float mv,float mov);
			float camPitch,camYaw;
		bool isMoved();
		void ControlKeyboard(char key,int x, int y);
		void passiveKeyboard(char key,int x, int y);
		void motion(int x, int y);
		void passiveMotion(int x,int y);
		void controlSpecialKeyboard(int key,int x, int y);
	
};

#endif
