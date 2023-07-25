#ifndef DEF_VECTOR3
#define DEF_VECTOR3
#include <GL/gl.h>
#include<GL/glu.h>
#include<stdio.h>
#include<GL/freeglut.h>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include<cstdlib>

using namespace std;

struct vector3d
{
	vector3d();
	vector3d(float a, float b);
	vector3d(float a,float b,float c);
	float dotProduct(const vector3d& vec2)const;
	vector3d crossProduct(const vector3d& vec2)const;
	float length();
	void change(float a,float b,float c);
	void change(vector3d vec);
	void changeX(float a);
	void changeY(float b);
	void changeZ(float c);
	void normalize();
	vector3d operator+(const vector3d& vec)const;
	vector3d operator-(const vector3d& vec)const;
	vector3d operator*(const float& num)const;
	vector3d operator+=(const vector3d& vec);
	vector3d operator-=(const vector3d& vec);
	vector3d operator*=(const float& num);
	vector3d operator/=(const float& num);
	bool operator==(const vector3d& vec);
	bool operator!=(const vector3d& num);
	void afficher(vector3d vec);
	void afficher2();
	void RotationMatrix(GLfloat* Matrix);
	vector3d rotateVectorAboutAngleAndAxis(float angle,vector3d axis);
	float x;
	float y;
	float z;
};
#endif
