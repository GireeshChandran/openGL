extern double queuedMilliseconds,prev0,fps,responseTime;
extern float lx,lz,x,z,angle;
extern GLuint dlist;
extern int imageNo,opt2,toggle;
extern GLfloat angleR,angleZ;
extern float sun_x;
extern float red, green, blue, val, matSine, dim;
extern float sLx, sLy, sLz, sint;

// Camera
extern int fov, asp;

void clearp_data();
void mixedStepLoop();
void processSpecialKeys(int , int , int );
void draw();
void initialOBJ();
void objDraw();
void optimisationList();
void project();


class data
{
public:
float v[3];
float vn[3];
//float tex[3];

data()
	{
		v[0]=0;v[1]=0;v[2]=0;vn[0]=0;vn[1]=0;vn[2]=0;//tex[0]=0;tex[1]=0;tex[2]=0;
	}
};
