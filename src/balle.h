#ifndef DEF_BALLE_H
#define DEF_BALLE_H
#include <gl/gl.h>
#include<gl/glu.h>
#include<stdio.h>
#include<C:\library\freeglut\include\GL\freeglut.h>
#include"collisionsphere.h"
class balle
{
	public:
		balle(collisionsphere ccs,float rotYaw,float rotPitch);
		~balle();
		void draw();
		
		float rot_();
		float rot2_();
		void setRot(float r);
		void setRot2(float r);
		float speed_();
		vector3d getLocation();
		void setLocation(vector3d newLoc);
		void setLocationinc(vector3d newLoc);
		collisionsphere getCollissionSphere();
		vector3d getRotation();
	
		
		private:
		
					float x,y,z;
				float speed;
				float rot;
				float rot2;
			    vector3d rotated;
			    
				collisionsphere cs;
					vector3d  axisRot2;
				vector3d  axisRot;
				
};
#endif
