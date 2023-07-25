#include"main.h"




int main(int argc,char ** argv)
{


glutInit(&argc,argv);//initilisation de glut
glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
glutInitWindowSize(960,540);// taille de la fenetre
glutCreateWindow("Scene Graphique OpenGL 2.0");// titre de l'application
glutReshapeFunc(reshape);// configuration du mode de projection du pixel à l'ecran
glutSpecialFunc(specialKey);
glutSpecialUpFunc(specialKeyUP);
glutKeyboardFunc(keyboardInput);
glutKeyboardUpFunc(passiveKeyboard);
glutMotionFunc(mouseMotion);
glutPassiveMotionFunc(passiveMouse);
glutDisplayFunc(show);// fonction d'affichage du dessin à l'ecran
g.init();
glutMainLoop();// fonction d'appel en continue d'affichage dans main()

return 0;
}
void reshape(int width,int height)
{
	
	g.reshape(width,height); 
}
void show()
{
	g.show();
}


void keyboardInput(unsigned char key,int x,int y)
{
g.controlKeyboard(key,x,y);
}
void passiveKeyboard(unsigned char key,int x,int y)
{
g.passiveKeyboard(key,x,y);
}
void passiveMouse(int x,int y)
{
	g.passiveMotion(x,y);
}
void mouseMotion(int x, int y)
{
	g.mouseMotion(x,y);
}
void specialKey(int key,int x, int y)
{
	g.controlSpecialKeyboard( key, x,  y);
}
void specialKeyUP(int key, int x, int y)
{
	g.controlSpecialPassiveKeyboard(key,x,y);
}

