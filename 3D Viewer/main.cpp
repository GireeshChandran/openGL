
#include <GL/glut.h>
#include <stdio.h>
#include <myheader.h>
#include "iostream"
#include<vector>
#include<string>

using namespace std;
GLfloat angleR = 0,angleZ = 0;
int opt2;
class data p;
double queuedMilliseconds,prev0,fps,responseTime;
GLuint dlist;
int imageNo,elements;
float sun_x = 0;
float red = 1;
float green = 1;
float blue = 1;
float val, dim = 4;
int chanel = 0, toggle = 1;
int fov = 60, asp = 1;

float sLx = 1.0, sLy = 1.0, sLz = 1.0, sint = 0.0;

float matSine = 50.0;

void initialSetup()
{
	elements=0;
	FILE *filename;
	char temp[50];
	vector<string> name;

	system("(ls | grep .obj)>filelist");
	filename=fopen("filelist","r");

	while(!(feof(filename)))
	{	
		elements++;
		fscanf(filename,"%s",temp);
		name.push_back(temp);
	}

	string systemtext = "cp " + name[imageNo] + " temp.obj";
	system(systemtext.c_str());
	fclose(filename);
	system("rm filelist");
}

void project()
{
    glMatrixMode(GL_PROJECTION);  
	glLoadIdentity();  
	if(toggle)
		gluPerspective (fov, 1, 1, 1000.0);
	else
		glOrtho(-dim*asp, +dim*asp, -dim, +dim, -10000, 10000.0);
	glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity();
}

void handleResize(int w,int h)
{
	asp = (GLfloat)w / (GLfloat)h;
	glViewport(0,0,w,h);
	project();
}

float change_color(unsigned char key, float val)
{

	
if(key == 60 || key == 44)
{
	val += 0.2;
	if(val >= 1)
	{
		val = 1;
	}
}
if(key == 62 || key == 46)
{
	val -= 0.2;
	if(val <= 0)
	{
		val = 0;
	}

}

return val;
}

int imgchange;
void processKeyboard(unsigned char key,int x,int y)
{

/* // material shininess
if(key == 43)
{
	matSine += 5;
	if(matSine >= 100)
		matSine = 100;
}
else if(key == 45)
{
	matSine -= 5;
	if(matSine <= 0)
		matSine = 0;
}*/


// Light position change

if(key == 52)
{
	sLx -= 1;
}
else if(key == 54)
{
	sLx += 1;
}
else if(key == 50)
{
	sLy -= 1;
}
else if(key == 56)
{
	sLy += 1;
}

// Light intensity change

if(key == 49)
{
	sint -= 1;
}
else if(key == 51)
{
	sint += 1;
	if(sint <= 0.0)
	{
		sint = 0;
	}
}

// Toggle btwn perspective and orthorombic

if(key == 111 || key == 79)
{
	toggle = 0;
	glShadeModel(GL_SMOOTH);
	project();
glutPostRedisplay();
}
if(key == 112 || key == 80)
{
	toggle = 1;
	project();
glutPostRedisplay();
}

// Zoom

if(key == 43)
{
	dim -= 0.1;
		project();
glutPostRedisplay();
}
else if(key == 45)
{
	dim += 0.1;
		project();
glutPostRedisplay();
}


if(key == 27)
{
	exit(0);
}

if(key==65||key==97)
{
	if(imageNo!=0)
	imageNo--;
imgchange=1;
}
if(key==68||key==100)
{	
	if(imageNo<(elements-2))
	imageNo++;
imgchange=1;
}

switch(key)
{
	case 'r':{chanel = 1;printf("chanel%i enabled\n",chanel);}break;
	case 'g':{chanel = 2;printf("chanel%i enabled\n",chanel);}break;
	case 'b':{chanel = 3;printf("chanel%i enabled\n",chanel);}break;
}



//printf("red %f | green %f | blue %f : Roughness %f | L(%f , %f) | sint : %f |\n", red, green, blue, matSine, sLx, sLy, sint);

if(chanel == 1)
{
	red = change_color(key, red);
}
if(chanel == 2)
{
	green = change_color(key, green);
}
if(chanel == 3)
{
	blue = change_color(key, blue);
}


if(imgchange==1)
{
opt2=0;
clearp_data();
angleR=0;angleZ=0;
initialSetup();
imgchange=0;
}
}

void mainMenu(int value)
{
	switch(value)
	{
		
		case 0:
		{
			if(imageNo!=0)
				imageNo--;
			imgchange=1;break;
		}
		case 1:
		{
				if(imageNo<(elements-2))
					imageNo++;
				imgchange=1;break;
		}
		case 2: exit(0);break;
	}

project();
glutPostRedisplay();
}

int main(int argc, char** argv)
{
	//..gameLoop setup
	queuedMilliseconds=0;
	prev0=0;
	fps=60;
	responseTime=(1/fps)*1000;

initialSetup();
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH|GLUT_RGBA);
glutInitWindowSize(800,800);
glutInitWindowPosition(100,100);
glutCreateWindow("3D Model Viewer");
glutReshapeFunc(handleResize);
glutDisplayFunc(draw);
glutIdleFunc(mixedStepLoop);
glutSpecialFunc(processSpecialKeys);
glutKeyboardFunc(processKeyboard);
glEnable(GL_DEPTH_TEST);

// Menu
glutCreateMenu(mainMenu);
//glutAddMenuEntry("Next", 0);
//glutAddMenuEntry("Prev", 1);
glutAddMenuEntry("Exit", 2);
glutAttachMenu(GLUT_RIGHT_BUTTON);


glutMainLoop();
}

