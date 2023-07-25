#ifndef DEF_MAIN_H
#define DEF_MAIN_H
#include"setup.h"



void show();
void reshape(int,int);
void keyboardInput(unsigned char,int,int);
void input(int,int,int);
void relacher(int,int,int);
void passiveKeyboard(unsigned char key,int x,int y);
void mouseMotion(int x, int y);
void passiveMouse(int x,int y);
void specialKey(int key,int x, int y);
void specialKeyUP(int key, int x, int y);
setup g;



#endif
