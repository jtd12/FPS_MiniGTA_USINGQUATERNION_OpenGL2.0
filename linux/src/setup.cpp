#include"setup.h"




setup::setup()
{
	
}
setup::~setup()
{
	delete playerCam_;
	for(int i=0;i<levels.size();i++)
	  delete levels[i];
	for(int i=0;i<vehicule.size();i++)
	  delete vehicule[i];
	for(int i=0;i<zombies.size();i++)
	  delete zombies[i];
	delete audio;
	
}
void setup::init()
{
    glEnable( GL_TEXTURE_2D );
    glEnable(GL_DEPTH_TEST);

std::vector<collisionplane> mapcp;

std::vector<vector3d> mapsp;

mapsp.push_back(vector3d(0.1,0.2,0.1));

unsigned int map=obj.load("data/map.obj",&mapcp);
unsigned int map2=obj.load("data/map2.obj",&mapcp);
unsigned int map3=obj.load("data/map3.obj",&mapcp);
unsigned int map4=obj.load("data/lampadaire.obj",&mapcp);
unsigned int map5=obj.load("data/panneau.obj",&mapcp);
unsigned int map6=obj.load("data/carAI.obj",&mapcp);

unsigned int map7=obj.load("data/tree.obj",&mapcp);
unsigned int map8=obj.load("data/tree2.obj",&mapcp);
unsigned int map9=obj.load("data/tree3.obj",&mapcp);
unsigned int map10=obj.load("data/tree4.obj",&mapcp);
unsigned int map11=obj.load("data/carAI2.obj",&mapcp);
unsigned int map12=obj.load("data/carAI3.obj",&mapcp);
unsigned int map13=obj.load("data/carAI4.obj",&mapcp);
unsigned int map14=obj.load("data/carAI5.obj",&mapcp);
unsigned int map15=obj.load("data/carAI6.obj",&mapcp);
unsigned int map16=obj.load("data/carAI7.obj",&mapcp);
unsigned int map17=obj.load("data/carAI8.obj",&mapcp);
unsigned int map18=obj.load("data/carAI9.obj",&mapcp);
unsigned int map19=obj.load("data/carAI10.obj",&mapcp);
unsigned int map20=obj.load("data/lampadaire2.obj",&mapcp);
unsigned int map21=obj.load("data/lampadaire3.obj",&mapcp);
unsigned int map22=obj.load("data/lampadaire4.obj",&mapcp);
unsigned int map23=obj.load("data/collisionCarAI.obj",&mapcp);

levels.push_back(new level("name",map,mapcp,mapsp));
levels.push_back(new level("name",map2,mapcp,mapsp));
levels.push_back(new level("name",map3,mapcp,mapsp));
levels.push_back(new level("name",map4,mapcp,mapsp));
levels.push_back(new level("name",map5,mapcp,mapsp));
levels.push_back(new level("name",map6,mapcp,mapsp));

levels.push_back(new level("name",map7,mapcp,mapsp));
levels.push_back(new level("name",map8,mapcp,mapsp));
levels.push_back(new level("name",map9,mapcp,mapsp));
levels.push_back(new level("name",map10,mapcp,mapsp));
levels.push_back(new level("name",map11,mapcp,mapsp));
levels.push_back(new level("name",map12,mapcp,mapsp));
levels.push_back(new level("name",map13,mapcp,mapsp));
levels.push_back(new level("name",map14,mapcp,mapsp));
levels.push_back(new level("name",map15,mapcp,mapsp));
levels.push_back(new level("name",map16,mapcp,mapsp));
levels.push_back(new level("name",map17,mapcp,mapsp));
levels.push_back(new level("name",map18,mapcp,mapsp));
levels.push_back(new level("name",map19,mapcp,mapsp));
levels.push_back(new level("name",map20,mapcp,mapsp));
levels.push_back(new level("name",map21,mapcp,mapsp));
levels.push_back(new level("name",map22,mapcp,mapsp));

levels.push_back(new level("name",map23,mapcp,mapsp));

unsigned int mesh=obj.load("data/vehicule.obj",&mapcp);
unsigned int mesh3=obj.load("data/weapon.obj",&mapcp);
unsigned int mesh2=obj.load("data/roue.obj",&mapcp);
unsigned int mesh4=obj.load("data/volant.obj",&mapcp);
audio=new sound;
vehicule.push_back(new car(mesh,mesh2,mesh4,"voiture",collisionsphere(vector3d(30,18,280),15.0),0.02,0.0,0.2,audio->loadSound("data/audio/sound_40.wav"),audio->loadSound("data/audio/sound_60.wav"),
audio->loadSound("data/audio/sound_100.wav"),audio->loadSound("data/audio/sound_250.wav"),audio->loadSound("data/audio/frein2.wav")));
std::vector<unsigned int> anim;
obj.loadAnimation(anim,"data/pistol/pistol",38);
weapons.push_back(new arme(anim,anim[0],1,16,19,vector3d(0.5,0,-1.1),vector3d(0,-50,0),vector3d(-0.2,0,-1.1),vector3d(0,0,0),100,1000,10,30,300,20,"weapon1",1));
playerCam_=new playerCam("player1",collisionsphere(vector3d(0,12.0,250),10.0),15.2,4.0,0.8,weapons[0],audio->loadSound("data/audio/zombieAttack.wav"));
anim.clear();
obj.loadAnimation(anim,"data/zombie_anim/zombie",85);
zombies.push_back(new ennemy(anim,30,30,25,70,5,0.12,collisionsphere(vector3d(0,12.0,400),4.0),audio->loadSound("data/audio/pas.wav"),audio->loadSound("data/audio/hit.wav"),audio->loadSound("data/audio/mort.wav")));
zombies.push_back(new ennemy(anim,30,30,25,50,5,0.12,collisionsphere(vector3d(0,12.0,700),4.0),audio->loadSound("data/audio/pas.wav"),audio->loadSound("data/audio/hit.wav"),audio->loadSound("data/audio/mort.wav")));
zombies.push_back(new ennemy(anim,30,30,25,40,5,0.12,collisionsphere(vector3d(10,12.0,800),4.0),audio->loadSound("data/audio/pas.wav"),audio->loadSound("data/audio/hit.wav"),audio->loadSound("data/audio/mort.wav")));
changeVehicule=false;
changeWeapon=true;
//PlaySound("data/audio/ambiance.wav", NULL, SND_LOOP |SND_ASYNC);

}

float setup::float_rand( float min, float max )
{
    float scale = rand() / (float) RAND_MAX; /* [0, 1.0] */
    return min + scale * ( max - min );      /* [min, max] */
}
void setup::fog()
{
	
glEnable(GL_FOG) ;
GLfloat fogcolor[4] = {0.6, 0.7, 0.8, 1} ;
GLint fogmode = GL_EXP ;
glFogi (GL_FOG_MODE, fogmode) ;
glFogfv(GL_FOG_COLOR, fogcolor) ;
glFogf(GL_FOG_DENSITY, 0.0012) ;
glFogf(GL_FOG_START, 800.0) ;
glFogf(GL_FOG_END, 18500.0) ;

}
void setup::lighting()
{
	GLfloat ambient[] = {0.4f,0.5f,0.8f,0.6f};
            GLfloat diffuse[] = {0.8f,0.8f,0.5f,0.5f};
            GLfloat light0_position [] = {0.0f, 0.0f, 60.0f, 0.0f};
            GLfloat specular_reflexion[] = {0.8f,0.8f,0.8f,1.0f};
            GLubyte shiny_obj = 128;

                        //positionnement de la lumière avec les différents paramètres
            glEnable(GL_LIGHTING);
            glLightfv(GL_LIGHT0,GL_AMBIENT,ambient);
            glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuse);
            glLightfv(GL_LIGHT0,GL_POSITION,light0_position);
            glEnable(GL_LIGHT0);

                         //spécification de la réflexion sur les matériaux
            glEnable(GL_COLOR_MATERIAL);
            glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);
            glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,ambient);
            glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diffuse);
            glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,specular_reflexion);
            glMateriali(GL_FRONT_AND_BACK,GL_SHININESS,shiny_obj);
}
std::string setup::int2str(int x) {
    // converts int to string
    std::stringstream ss;
    ss << x;
    return ss.str( );
}
std::string setup::float2str(float x) {
    // converts int to string
    std::stringstream ss;
    ss << x;
    return ss.str( );
}
void setup:: drawText(float x, float y, std::string text) {
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_8_BY_13, (const unsigned char*)text.c_str());
}
void setup::enable2D(int width, int height) {
  	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(1,1,1,1);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glPushMatrix();
	glColor3d(1,0.1,0.2);
	drawText(-0.8 , 0.9, "Pour jouer: fleche directionnelle pour deplacer le vehicule,\n"  "freiner=Press spacebar \n"
	"changerMode= Press K, et L pour sortir du vehicule,\n" "tirer=press v et \n" "deplacer personnage = press Z avancer press W reculer press A deplacer gauche\n" 
	"press D deplacer droit\n" );
	glPopMatrix();
	glPushMatrix();
	glColor3d(0.1,0.2,0.4);
	drawText(-0.8 , 0.5,"km/h: " +float2str(vehicule[0]->getSpeed()*100));
	glPushMatrix();
	glColor3d(0.1,0.5,0.2);
	drawText(-0.8 , 0.2,"Health Ennemy: " +int2str(zombies[0]->getHealth()));
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
  
}
void setup::changerDriver(char key,int x,int y)
{
	switch(key)
	{
		case 'k':
			 changeWeapon=true;
			 changeVehicule=false;
			  break;
		case 'l':
			 
			  changeVehicule=true;
			  break;
			
	}
	
}
void setup::update()
{
		audio->setListener(playerCam_->cam.getLocation(),playerCam_->cam.getVector());
	
		for(int i=0;i<zombies.size();i++)
			{
			
			if(collision::raysphere(vehicule[0]->getCollissionSphere().center.x,vehicule[0]->getCollissionSphere().center.y,
			    vehicule[0]->getCollissionSphere().center.z,direction.x,direction.y,
			direction.z,zombies[i]->getCollisionSphere().center.x,zombies[i]->getCollisionSphere().center.y,
				zombies[i]->getCollisionSphere().center.z,30.0f))
				{
					vehicule[0]->ecraserEnnemy(audio,zombies[i]->isDead_(),zombies[i]->getMortSound());
					zombies[i]->decreaseHealth(playerCam_->getCurWeapon()->getStrength());
				}
			
			}

	 for(int i=0;i<levels.size();i++)
      
      	levels[i]->update();
      	
     for(int i=0;i<zombies.size();i++)
      {
      	if(zombies[i]->update(levels[0]->getCollisionPlanes(),playerCam_->getCollissionSphere().center,audio))
      	{
      		
		  }
		  
	  }
	   for(int i=0;i<zombies.size();i++)
      {
      	if(zombies[i]->setAttack(playerCam_->getCollissionSphere()))
      	{
      		playerCam_->setHealth(playerCam_->getHealth()-zombies[i]->getStrength());
		  }
      }
      /*
	  	for(int i=0;i<zombies.size();i++)
			{
			if(collision::raysphere(zombies[i]->getCollisionSphere()->center.x,zombies[i]->getCollisionSphere()->center.y,
				zombies[i]->getCollisionSphere()->center.z,direction.x,direction.y,
			direction.z,playerCam_->getCollissionSphere().center.x,playerCam_->getCollissionSphere().center.y,
			    playerCam_->getCollissionSphere().center.z,zombies[i]->getCollisionSphere()->r))
				{
					zombies[i]->decreaseHealth(playerCam_->getCurWeapon()->getStrength());
				}
			}
			*/
			
      if(changeWeapon)
      {
	  
     	playerCam_->update(levels[0]->getCollisionPlanes());
     		playerCam_->updateArme();
    
    	playerCam_->updateBalle(); 
    	
    		if(collision::raysphere(vehicule[0]->getCollissionSphere().center.x+5,vehicule[0]->getCollissionSphere().center.y,vehicule[0]->getCollissionSphere().center.z,direction.x,direction.y,direction.z,
			playerCam_->getCollissionSphere().center.x,playerCam_->getCollissionSphere().center.y,playerCam_->getCollissionSphere().center.z,20.9f))
			{
	
		// Remove elements while iterating
		// erase() makes the passed iterator invalid
			// But returns the iterator to the next of deleted element
 playerCam_->setLocation(vector3d(2.0f,0,0));
}
			else if(collision::raysphere(vehicule[0]->getCollissionSphere().center.x-5,vehicule[0]->getCollissionSphere().center.y,vehicule[0]->getCollissionSphere().center.z,direction.x,direction.y,direction.z,
			playerCam_->getCollissionSphere().center.x,playerCam_->getCollissionSphere().center.y,playerCam_->getCollissionSphere().center.z,20.9f))
			{
	
		// Remove elements while iterating
		// erase() makes the passed iterator invalid
			// But returns the iterator to the next of deleted element
 playerCam_->setLocation(vector3d(-2.0f,0,0));
}

     }
     

    	
    	if(changeVehicule && collision::raysphere(vehicule[0]->getCollissionSphere().center.x,vehicule[0]->getCollissionSphere().center.y,vehicule[0]->getCollissionSphere().center.z,direction.x,direction.y,direction.z,
			playerCam_->getCollissionSphere().center.x,playerCam_->getCollissionSphere().center.y,playerCam_->getCollissionSphere().center.z,30.9f))
  {
  	dist=true;
  }
if(changeVehicule==false)
{
	dist=false;
}
  if(dist )
  {
  
    	vehicule[0]->control(audio);
    
    	playerCam_->setLocation2(vector3d(vehicule[0]->getLocation().x,vehicule[0]->getLocation().y,vehicule[0]->getLocation().z));
    }

    
    	

		for(int i=0;i<vehicule.size();i++)
      	  vehicule[i]->update(levels[0]->getCollisionPlanes());
	/*		
				
      	for(int i=0;i<zombies.size();i++)
			{
			if( collision::raysphere(zombies[i]->getCollisionSphere()->center.x,zombies[i]->getCollisionSphere()->center.y,
				zombies[i]->getCollisionSphere()->center.z,vehicule[0]->getLocation().x,vehicule[0]->getLocation().y,
				vehicule[0]->getLocation().z,vehicule[0]->getCollissionSphere().center.x,vehicule[0]->getCollissionSphere().center.y,
			    vehicule[0]->getCollissionSphere().center.z,zombies[i]->getCollisionSphere()->r))
				{
					zombies[i]->decreaseHealth(playerCam_->getCurWeapon()->getStrength());
				}
			}*/

	/*	else if(collision::raysphere(vehicule[0]->getCollissionSphere().center.x-5,vehicule[0]->getCollissionSphere().center.y,vehicule[0]->getCollissionSphere().center.z,direction.x,direction.y,direction.z,
			playerCam_->getCollissionSphere().center.x,playerCam_->getCollissionSphere().center.y,playerCam_->getCollissionSphere().center.z,5.0f))
			{
	
		// Remove elements while iterating
		// erase() makes the passed iterator invalid
			// But returns the iterator to the next of deleted element
 playerCam_->setLocation(vector3d(playerCam_->getLocation().x-15.0f,vehicule[0]->getLocation().y,vehicule[0]->getLocation().z));
}
	else if(collision::raysphere(vehicule[0]->getCollissionSphere().center.x,vehicule[0]->getCollissionSphere().center.y,vehicule[0]->getCollissionSphere().center.z+5,direction.x,direction.y,direction.z,
			playerCam_->getCollissionSphere().center.x,playerCam_->getCollissionSphere().center.y,playerCam_->getCollissionSphere().center.z,5.0f))
			{
	
		// Remove elements while iterating
		// erase() makes the passed iterator invalid
			// But returns the iterator to the next of deleted element
 playerCam_->setLocation(vector3d(vehicule[0]->getLocation().x,vehicule[0]->getLocation().y,15.0f));
}
      //playerCam_->setJump();
 	else if(collision::raysphere(vehicule[0]->getCollissionSphere().center.x,vehicule[0]->getCollissionSphere().center.y,vehicule[0]->getCollissionSphere().center.z-5,direction.x,direction.y,direction.z,
			playerCam_->getCollissionSphere().center.x,playerCam_->getCollissionSphere().center.y,playerCam_->getCollissionSphere().center.z,5.0f))
			{
	
		// Remove elements while iterating
		// erase() makes the passed iterator invalid
			// But returns the iterator to the next of deleted element
 playerCam_->setLocation(vector3d(vehicule[0]->getLocation().x,vehicule[0]->getLocation().y,-15.0f));
}
*/
}
void setup::cameraFollowCar()
{
	if(changeCam<2)
	{
	
		if(vehicule[0]->getSpeed()>0.01f)
		{
		
	vector3d camPos=vector3d(vehicule[0]->getLocation().x+sin(vehicule[0]->getRotation().y*M_PI/180.0f)*40,15,vehicule[0]->getLocation().z+cos(vehicule[0]->getRotation().y*M_PI/180.0f)*55);
	vector3d target=vehicule[0]->getLocation();
	vector3d camUp=vector3d(0,1,0);

	 gluLookAt(camPos.x,camPos.y,camPos.z,target.x,target.y,target.z,camUp.x,camUp.y,camUp.z);
}

	if(vehicule[0]->getSpeed()<-0.01f)
		
	{
	
		vector3d camPos=vector3d(vehicule[0]->getLocation().x+sin(vehicule[0]->getRotation().y*M_PI/180.0f)*-40,15,vehicule[0]->getLocation().z+cos(vehicule[0]->getRotation().y*M_PI/180.0f)*-35);
	vector3d target=vehicule[0]->getLocation();
	vector3d camUp=vector3d(0,1,0);
	 gluLookAt(camPos.x,camPos.y,camPos.z,target.x,target.y,target.z,camUp.x,camUp.y,camUp.z);
}
	if(vehicule[0]->getSpeed()==0.0f)
	{
		vector3d camPos=vector3d(vehicule[0]->getLocation().x+sin(vehicule[0]->getRotation().y*M_PI/180.0f)*40,15,vehicule[0]->getLocation().z+cos(vehicule[0]->getRotation().y*M_PI/180.0f)*55);
	vector3d target=vehicule[0]->getLocation();
	vector3d camUp=vector3d(0,1,0);
	 gluLookAt(camPos.x,camPos.y,camPos.z,target.x,target.y,target.z,camUp.x,camUp.y,camUp.z);	
	}
}
}
void setup::cameraInsideCar()
{
	if(changeCam>=2)
	{
	
		vector3d camPos=vector3d(vehicule[0]->getLocation().x+sin(vehicule[0]->getRotation().y*M_PI/180.0f)*1.0,6,vehicule[0]->getLocation().z+cos(vehicule[0]->getRotation().y*M_PI/180.0f)*1.0);
		vector3d target=vehicule[0]->getLocation();
		vector3d camUp=vector3d(0,1,0);
		gluLookAt(camPos.x,camPos.y,camPos.z,target.x,target.y-6,target.z,camUp.x,camUp.y,camUp.z);	
	
}
	
}
void setup::changeCamera(char key, int x, int y)
{
	switch(key)
	{
		case 'c':
			changeCam+=1;
			if(changeCam>3)
			{
				changeCam=0;
			}
			break;
	}
}
void setup::show()
{
//clavierActif(); 

int LightPos[4] = {0,100,-100,1};
GLfloat shininess = 10.0F ;
int MatSpec [4] = {1,1,1,1};
glMaterialiv(GL_FRONT_AND_BACK,GL_SPECULAR,MatSpec);//fonction d'affichage d'un materiau qui gere la specularite
glMateriali(GL_FRONT_AND_BACK,GL_SHININESS,10);//fonction 
glMaterialf(GL_FRONT,GL_SHININESS,shininess);


update();  


glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);// effacement de la fenetre et vidage des tampons 
glLoadIdentity();// initialisation de la matrice

//gluLookAt(camX,8,camZ,r.avancerX,3,r.avancerZ,0,1,0);// afichage de la camera à lecran qui suit le robot
lighting();
if(dist &&  changeVehicule)
{
		cameraFollowCar();
		cameraInsideCar();
}
 if (changeVehicule==false &&  dist==false)
 {
 
 playerCam_->showArme();


 playerCam_->cam.Control();
 
 playerCam_->cam.UpdateCamera();
}
playerCam_->showBalle();
vehicule[0]->show();
for(int i=0;i<zombies.size();i++)
 zombies[i]->show();
for(int i=0;i<levels.size();i++)
   levels[i]->show();




enable2D(960,540);
//clavier();


glFlush();
glutPostRedisplay();// reafraichissement automatique de la scene à chaque image calculées
glutSwapBuffers();// echange de tampons pour ahever laffichage glut glutPostRedisplay();// rafraichissement de la scene en continue
}
void setup::reshape(int width,int height)
{

glClearColor(.2,.6,.8,0.9);	//Change la couleur du fond
glEnable(GL_DEPTH_TEST);	//Active le depth test
glEnable( GL_TEXTURE_2D );
glEnable(GL_LIGHTING);	// Active l'éclairage
glEnable(GL_LIGHT0);
glEnable(GL_COLOR_MATERIAL);

glViewport(0,0,width,height);// definition de la taille d'affichage de l'angle de la camera
glMatrixMode(GL_PROJECTION);// on chosit le mode projection de la matrice 
glLoadIdentity();// on initialise la matrice
gluPerspective(70,float (width)/float (height),0.1f,15000.0f); // on dit qu'on travaille en mode perspective avec une focale et un point de vue
glMatrixMode(GL_MODELVIEW);// on change de mode d'affichage, on reload une nouvelle matrice de transformation de modelisation
fog();
 
    
}
void setup::fireWeapon(char key, int x, int y)
{

	switch(key)
	{
		case 'v':
			playerCam_->getCurWeapon()->fire(direction,playerCam_->cam.getVector());
			for(int i=0;i<zombies.size();i++)
			{
				for(int j=0;j<playerCam_->ball.size();j++)
				{
				
			if(collision::raysphere(playerCam_->ball[j]->getCollissionSphere().center.x,playerCam_->ball[j]->getCollissionSphere().center.y,
			    playerCam_->ball[j]->getCollissionSphere().center.z,direction.x,direction.y,
			direction.z,zombies[i]->getCollisionSphere().center.x,zombies[i]->getCollisionSphere().center.y,
				zombies[i]->getCollisionSphere().center.z,10.0f))
				{
					zombies[i]->decreaseHealth(playerCam_->getCurWeapon()->getStrength());
				}
			}
			}
			//playerCam_->tirer(direction);
			break;
		case 'r':
	        playerCam_->getCurWeapon()->reload();
			break;
		case 'c':
			playerCam_->setSprint();
		
			break;
	}
}
void setup::stopFire(char key, int x , int y)
{
	switch(key)
	{
		case 'v':
			playerCam_->getCurWeapon()->stopFire();
			break;
	
	case 'c':
		playerCam_->stopSprint();
		break;
	}
}
void setup::changeWeapon_(char key, int x, int y)
{
	switch(key)
	{
	case 'u':
	 playerCam_->changeWeapon(0);
	 break;
	 case 'o':
	 	 playerCam_->changeWeapon(1);
	 	 break;
	case 'i':
		playerCam_->changeWeapon(2);
		break;
}
}
void setup::changeWeaponUp(char key, int x, int y)
{
	switch(key)
	{
		case 'b':
			playerCam_->changeWeaponUp();
			break;
	}
}

void setup::changeWeaponDown(char key, int x, int y)
{
	switch(key)
	{
		case 'b':
			playerCam_->changeWeaponDown();
			break;
	}
}

void setup::controlKeyboard(char key,int x, int y)
{
	changerDriver(key,x,y);
	  for(int i=0;i<zombies.size();i++)
		playerCam_->inputSpecial(key,x,y,audio,zombies[i]->isDead_(),zombies[i]->getMortSound());
	playerCam_->cam.ControlKeyboard(key,x,y);
	//playerCam_->weapons[playerCam_->getCurrentWeapon()]->test(key,x,y);
	vehicule[0]->keyboard(key,x,y);
	changeWeapon_(key,x,y);
	fireWeapon(key, x,  y);
	changeWeaponDown(key,x,y);
	changeCamera( key,  x,  y);
}
void setup::passiveKeyboard(char key,int x, int y)
{
	playerCam_->cam.passiveKeyboard(key,x,y);
	playerCam_->relacherSpecial( key, x,  y);
	vehicule[0]->keyboardUP(key,x,y);
	stopFire(key,x,y);
	changeWeaponUp(key,x,y);
}
void setup::controlSpecialKeyboard(int key,int x, int y)
{
	playerCam_->cam.controlSpecialKeyboard( key, x,  y);
	vehicule[0]->inputSpecial(key,x,y);
	

}
void setup::controlSpecialPassiveKeyboard(int key,int x, int y)
{
	vehicule[0]->inputSpecialUP(key,x,y);
}
void setup::mouseMotion(int x,int y)
{
	playerCam_->cam.motion(x,y);
}
void setup::passiveMotion(int x,int y)
{
//	playerCam_->cam.passiveMotion( x, y);
}

                                                                         

