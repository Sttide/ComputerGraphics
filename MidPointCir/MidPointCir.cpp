#include <gl/glut.h>
#include <math.h>
#include <stdio.h>
typedef struct {
	float x,y;
}point;
void init()
{
	glClearColor(0.0f,0.0f,0.0f,1.0f);
}
void swap(int *x0,int *y0,int *x1,int *y1)
{    
    int x,y;
    x = *x1;
    *x1 = *x0;
    *x0 = x;
        
    y = *y1;
    *y1 = *y0;
    *y0 = y;    
}
void MidPointCir(int r)
 {
	int x,y;
	float d;
	x=0; y=r;
	d=1-r;
	glBegin(GL_POINTS);
	glVertex2f(x, y);

	while(x<y)
	{
		if(d<0)
		{
			d += 2*x+3; x++;
		}
		else
		{
			d += 2*(x-y) + 5; x++;y--;
		}

		glVertex2f(x, y);
		glVertex2f(x, y);
		glVertex2f(y, x);
		glVertex2f(y, -x);
		glVertex2f(x, -y);
		glVertex2f(-x, -y);
		glVertex2f(-y, -x);
		glVertex2f(-y, x);
		glVertex2f(-x, y);

	}
	glEnd();

 }


void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f,1.0f,1.0f);
	MidPointCir(20);
	glFlush();
}
void ChangeSize(GLsizei w,GLsizei h)
{
	GLfloat aspectRatio;
	if(h==0)
		h = 1;
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	aspectRatio = (GLfloat)w/(GLfloat)h;
	if(w<=h)
		glOrtho(-100.0,100.0,-100.0/aspectRatio,100.0/aspectRatio,1.0,-1.0);
	else
		glOrtho(-100.0*aspectRatio,100.0*aspectRatio,-100.0,100.0,1.0,-1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void main()
{
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutCreateWindow("MidPointCir");

	init();

	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);

	glutMainLoop();
}