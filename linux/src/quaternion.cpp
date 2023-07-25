#include"quaternion.h"

quaternion::quaternion(float us,vector3d& uv):s(us),vec(uv)
{
	
}
quaternion::~quaternion()
{
	
}
quaternion::quaternion(const quaternion& value)
{
	s=value.s;
	vec=value.vec;
}
quaternion::quaternion(float Pitch, float Yaw, float Roll)
{
    float Pi = 4 * atan(1);

    //Set the values, which came in degrees, to radians for C++ trig functions
    float rYaw = Yaw * Pi / 180;
    float rPitch = Pitch * Pi / 180;
    float rRoll = Roll * Pi / 180;

    //Components
    float C1 = cos(rYaw / 2);
    float C2 = cos(rPitch / 2);
    float C3 = cos(rRoll / 2);
    float S1 = sin(rYaw / 2);
    float S2 = sin(rPitch / 2);
    float S3 = sin(rRoll / 2);

    //Create the final values
    a = ((C1 * C2 * C3) - (S1 * S2 * S3));
    x = (S1 * S2 * C3) + (C1 * C2 * S3);
    y = (S1 * C2 * C3) + (C1 * S2 * S3);
    z = (C1 * S2 * C3) - (S1 * C2 * S3);
}

quaternion& quaternion::operator=(const quaternion& value)
{
	s=value.s;
	vec=value.vec;
	return *this;
	
}
void quaternion::operator+=(const quaternion& q)
{
	s+=q.s;
	vec+=q.vec;
	
}
quaternion quaternion::operator+(const quaternion& q)const
{
	float scalar=s+q.s;
	vector3d imaginary=vec+q.vec;
	return quaternion(scalar,imaginary);
	
	
}
void quaternion::operator-=(const quaternion& q)
{
	
		s-=q.s;
		vec-=q.vec;
	
}
quaternion quaternion::operator-(const quaternion& q)const
{
	float scalar=s-q.s;
	vector3d imaginary=vec-q.vec;
	return quaternion(scalar,imaginary);
	
	
}
void quaternion::operator*=(const quaternion& q)
{
	(*this)=multiply(q);
}
quaternion quaternion::operator*(  quaternion q)const
{
	float scalar=s*q.s-vec.dotProduct(q.vec);
	vector3d imaginary=q.vec*s + vec*q.s+vec.crossProduct(q.vec);
	return quaternion(scalar,imaginary);
	
}
quaternion quaternion::operator* (quaternion OtherQuat)
{
    float A = (OtherQuat.a * a) - (OtherQuat.x * x) - (OtherQuat.y * y) - (OtherQuat.z * z);
    float X = (OtherQuat.a * x) + (OtherQuat.x * a) + (OtherQuat.y * z) - (OtherQuat.z * y);
    float Y = (OtherQuat.a * y) - (OtherQuat.x * z) - (OtherQuat.y * a) - (OtherQuat.z * x);
    float Z = (OtherQuat.a * z) - (OtherQuat.x * y) - (OtherQuat.y * x) - (OtherQuat.z * a);
    quaternion NewQuat = quaternion(0, 0, 0);
    NewQuat.a = A;
    NewQuat.x = X;
    NewQuat.y = Y;
    NewQuat.z = Z;
    return NewQuat;
}
void quaternion::operator*=(const float value)
{
	s*=value;
	vec*=value;
}
quaternion quaternion::operator*(const float value)const
{
	float scalar=s*value;
	vector3d imaginary=vec*value;
	return quaternion(scalar,imaginary);
}
quaternion quaternion::multiply(  const quaternion& q)const
{
	float scalar=s*q.s-vec.dotProduct(q.vec);
	vector3d imaginary=q.vec*s +vec*q.s+vec.crossProduct(q.vec);
	return quaternion(scalar,imaginary);
}
float quaternion::norm()
{
float scalar=s*s;
float imaginary=(vec.x*vec.x)+(vec.y*vec.y)+(vec.z*vec.z);
return sqrt(scalar+imaginary);
}
void quaternion::normalize()
{
	if(norm()!=0)
	{
		float normValue=1/norm();
	
	s*=normValue;
	vec*=normValue;
}
}
double quaternion::convertToRad(double degree)
 {
 	double pi=3.14159265359;
 	return (degree*(pi/180));
 }
void quaternion::convertToQuaternion()
{
	float angle=convertToRad(s);
	vec.normalize();
	s=cosf(angle*0.5);
	vec=vec*sinf(angle*0.5);
	
}
quaternion  quaternion::conjugate()
{
	float scalar=s;
	vector3d imaginary=vec*(-1);
	return quaternion(scalar,imaginary);
}
quaternion quaternion::inverse()
{
	float absoluteValue=norm();
	absoluteValue*=absoluteValue;
	absoluteValue=1/absoluteValue;
	quaternion conjugateValue=conjugate();
	float scalar=conjugateValue.s*absoluteValue;
	vector3d imaginary=conjugateValue.vec*absoluteValue;
	return quaternion(scalar,imaginary);
}
void quaternion::RotationMatrix(GLfloat* Matrix)
{
    //Column 1
    Matrix[0] = (a*a) + (x*x) - (y*y) - (z*z);
    Matrix[1] = (2*x*y) + (2*a*z);
    Matrix[2] = (2*x*z) - (2*a*y);
    Matrix[3] = 0;
    //Column 2
    Matrix[4] = (2*x*y) - (2*a*z);
    Matrix[5] = (a*a) - (x*x) + (y*y) - (z*z);
    Matrix[6] = (2*y*z) + (2*a*x);
    Matrix[7] = 0;
    //Column 3
    Matrix[8] = (2*x*z) + (2*a*y);
    Matrix[9] = (2*y*z) - (2*a*x);
    Matrix[10] = (a*a) - (x*x) - (y*y) + (z*z);
    Matrix[11] = 0;
    //Column 4
    Matrix[12] = 0;
    Matrix[13] = 0;
    Matrix[14] = 0;
    Matrix[15] = 1;
}

