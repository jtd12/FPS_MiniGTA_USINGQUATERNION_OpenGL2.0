#include"balle.h"
#include"quaternion.h"

balle::balle(collisionsphere  ccs,float rotYaw,float rotPitch)
{

	speed=2.0f;
	cs=ccs;
	axisRot=vector3d(0,0,0);
	axisRot2=vector3d(0,0,0);
	rotated.y=rotYaw;
	rotated.x=rotPitch;
}
	balle::~balle()
		{
			
		}
float balle::speed_()
{
	return speed;
}

float balle::rot_()
{
return axisRot2.y;
}
float balle::rot2_()
{
return axisRot.z;
}
void balle::setRot(float r)
{
	axisRot2.y=r;
}
void balle::setRot2(float r)
{
	axisRot.z=r;
}
void balle::draw()
{ 
/*
 	GLfloat m_RotationMatrix[16]= {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
			 	quaternion rotQuat = quaternion(0, 0,axisRot.z);// * m_qRotation;
       rotQuat.RotationMatrix(m_RotationMatrix);
       
       GLfloat m_RotationMatrix2[16]= {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
			 	quaternion rotQuat2 = quaternion(0, axisRot2.y,0);// * m_qRotation;
       rotQuat2.RotationMatrix(m_RotationMatrix2);
       
    glPushMatrix();
	glTranslated(cs.center.x,cs.center.y,cs.center.z);
		glMultMatrixf(m_RotationMatrix2);	  
        glMultMatrixf(m_RotationMatrix);
        */
    glPushMatrix();
    glTranslated(0.0,1.0,2.0);
    glTranslated(cs.center.x,cs.center.y,cs.center.z);
    GLfloat m_RotationMatrix[16]= {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
	quaternion rotQuat = quaternion(rotated.x,0,0);// * m_qRotation;
	rotQuat.RotationMatrix(m_RotationMatrix);
		    
	GLfloat m_RotationMatrix2[16]= {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
	quaternion rotQuat2 = quaternion(0,rotated.y,0);// * m_qRotation;
	rotQuat2.RotationMatrix(m_RotationMatrix2);
		    
	GLfloat m_RotationMatrix3[16]= {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
	quaternion rotQuat3 = quaternion(0,0,rotated.z);// * m_qRotation;
	rotQuat3.RotationMatrix(m_RotationMatrix3);
		    
	glMultMatrixf(m_RotationMatrix);
	glMultMatrixf(m_RotationMatrix2);
	glMultMatrixf(m_RotationMatrix3);
    //glRotatef(rotated.x,1,0,0);
	//glRotatef(rotated.y,0,1,0);
	//glRotatef(rotated.z,0,0,1);
	glColor3d(0.4,0.4,0.6);
	glutSolidCube(0.4f);
	glPopMatrix();
}
collisionsphere balle::getCollissionSphere()
	 	{
	 		return cs;
		 }
		 
		void balle::setLocation(vector3d newLoc)
		{
			cs.center=newLoc;
		}
		void balle::setLocationinc(vector3d newLoc)
		{
			cs.center+=newLoc;
		}
		vector3d balle::getLocation()
		{
			return cs.center;
		}
		vector3d balle::getRotation()
		{
			return rotated;
		}
	
