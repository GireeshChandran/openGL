#include <GL/glut.h>
#include <GL/glu.h>
#include <myheader.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "iostream"

#define PI 3.1415926535898
#define Cos(angleR) cos(PI/180*(angleR))
#define Sin(angleR) sin(PI/180*(angleR))

using namespace std;


//float matSine = 50.0;


//GLfloat angleR;

void update()
{
  angleR=angleR+0.5;
    if(angleR>360)
      angleR=0;
}


GLfloat objcolor[] = {0.5f,0.5f,0.5f,1.f}; 
GLfloat white[] = {1.0f,1.0f,1.0f,1.f};
//GLfloat redColor[] = {red, green, blue, 1.0f};


 void deleteInitial()
{
system("rm temp.obj");
}

GLfloat light0_position[] = {0.0,1.0,1.0, 0.0};
GLfloat sunLightPosition[] = {sLx, sLy, sLz, sint};

GLfloat mat_shininess[] = {matSine};

void draw()
{
  double Ex;
  double Ey;
  double Ez;
  // Perspective set eye position
  
  Ex = -2*dim*Sin(angleR)*Cos(angleZ);
  Ey = +2*dim*Sin(angleZ);
  Ez = +2*dim*Cos(angleR)*Cos(angleZ);
  
  // Default
  GLfloat redColor[] = {red, green, blue, 1.0f};
  glLightfv(GL_LIGHT1, GL_DIFFUSE,  redColor);

	if(opt2!=1)
  {

 // --------------- LIGHTING 
glEnable(GL_NORMALIZE);
glEnable(GL_LIGHTING);
//glEnable(GL_LIGHT0);	
glEnable(GL_LIGHT1);

// shading
glShadeModel(GL_SMOOTH); 

//glLightfv(GL_LIGHT0, GL_DIFFUSE,  redColor);
glLightfv(GL_LIGHT0, GL_POSITION, light0_position); 
glLightfv(GL_LIGHT1, GL_DIFFUSE,  redColor);
glLightfv(GL_LIGHT1, GL_POSITION, sunLightPosition);


// light 2
//glLightfv(GL_LIGHT0,GL_,white);


//glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, objcolor);
glMaterialfv(GL_FRONT, GL_SPECULAR, white);
glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
//---------------LIGHTING



   // OnInit();
    opt2=1;
    glClearColor (0.0,0.0,0.0,1.0); 
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    //gluLookAt(  x, 1.0f, z,x+lx, 1.0f, z+lz, 0.0f, 1.0f, 0.0f);
    if(toggle)
      gluLookAt(Ex, Ey, Ez, 0, 0, 0, 0, Cos(angleZ), 0);
    else
    {
      glRotatef(angleZ,1,0,0);
      glRotatef(angleR,0,1,0);
    }

   	glPushMatrix();
    //glTranslatef(0,0,-10);
    //glTranslatef(0,50,-2);
    //glScalef(0.1,0.1,0.1);
    	initialOBJ();
    	objDraw();
    	optimisationList();
    	deleteInitial();
   	glPopMatrix();
   	glutSwapBuffers();
 	}
  else
  {

  glLightfv(GL_LIGHT1, GL_DIFFUSE,  redColor);
  glLightfv(GL_LIGHT1, GL_POSITION, sunLightPosition);

    glClearColor (0.0,0.0,0.0,1.0); 
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    //gluLookAt(  x, 1.0f, z,x+lx, 1.0f, z+lz,0.0f, 1.0f, 0.0f);
    if(toggle)
      gluLookAt(Ex, Ey, Ez, 0, 0, 0, 0, Cos(angleZ), 0);
    else
    {
      glRotatef(angleZ,1,0,0);
      glRotatef(angleR,0,1,0);
    }
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
    glPushMatrix();
    //glColor3f(0.5,0.5,0.5);
    //glTranslatef(0,0,-10);
    //glTranslatef(0,50,-2);
    glScalef(0.4,0.4,0.4);
   // update();
    //glRotatef(angleR,0,1,0);
    //glRotatef(angleZ,1,0,0);
    glCallList(dlist);
    glPopMatrix();
    glutSwapBuffers();
  }

}

