#include<gl/glut.h>
typedef struct{
	float x,y,z;
}Point;
Point ctrlpoints[4]= {{0.0,1.0},{3.0,0.0},{0.0,3.0},{0.0,-3.0}};
void init()
{
	glClearColor(1.0,1.0,1.0,1.0);
}
void DrawCurve(int n)
{
	Point p;
	double t,deltat,t2,t3,bxP1,bxP4,bxR1,bxR4;
	int i;
	deltat = 1.0/(n-1);
	glBegin(GL_LINE_STRIP);
		for(i=0;i<100;i++)
		{
			t = i*deltat;
			t2 = t*t;
			t3 = t*t2;
			bxP1 = 2*t3-3*t2+1;
			bxP4 = -2*t3+3*t2;
			bxR1 = t3-2*t2+t;
			bxR4 = t3-t2;
			p.x = bxP1 * ctrlpoints[0].x + bxP4 * ctrlpoints[1].x + bxR1 * ctrlpoints[2].x + bxR4 * ctrlpoints[3].x;
			p.y = bxP1 * ctrlpoints[0].y + bxP4 * ctrlpoints[1].y + bxR1 * ctrlpoints[2].y + bxR4 * ctrlpoints[3].y;
			glVertex2f(p.x,p.y);
		}
	glEnd();
	
	glPointSize(5.0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	for (i = 0; i < 4; i++)
		glVertex2f(ctrlpoints[i].x,ctrlpoints[i].y);
	glEnd();
}
void RenderScence()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	DrawCurve(100);
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
		glOrtho(-4.0,5.0,-4.0/aspectRatio,5.0/aspectRatio,1.0,-1.0);
	else
		glOrtho(-4.0*aspectRatio,5.0*aspectRatio,-4.0,5.0,1.0,-1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
}
int main()
{
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("Hermite");
	
	init();
	glutDisplayFunc(RenderScence);
	glutReshapeFunc(ChangeSize);

	glutMainLoop();
	return 0;
}