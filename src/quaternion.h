#ifndef DEF_QUATERNION_H
#define DEF_QUATERNION_H
#include"vector3.h"
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include<cstdlib>

class quaternion
{

public:
		float s;
		vector3d vec;
		float a,x,y,z;
		quaternion();
		~quaternion();
		quaternion(float us,vector3d& uv);
		quaternion(const quaternion & value);
		quaternion(float Pitch, float Yaw, float Roll);
		quaternion& operator=(const quaternion& value);
		void operator+=(const quaternion& q);
		quaternion operator+(const quaternion& q)const;
		void operator-=(const quaternion& q);
		quaternion operator-(const quaternion& q)const;
		void operator*=(const quaternion& q);
		void operator*=(const float value);
		quaternion operator*(const float value)const;
		quaternion operator* (quaternion OtherQuat);
		quaternion operator*( quaternion q)const;
		quaternion multiply( const quaternion& q)const;
		float norm();
		void normalize();
		double convertToRad(double degree);		
		void convertToQuaternion();
		quaternion conjugate();
		quaternion inverse();
		void RotationMatrix(GLfloat* Matrix);



};
#endif
