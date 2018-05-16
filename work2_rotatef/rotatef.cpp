#include <gl/glut.h>
#include <stdio.h>
void init()
{
	glClearColor(0.0,0.0,0.0,1.0);
}
int martix[3][3] = {{0,1,-5},{1,0,5},{0,0,1}};
double calx(double x0, double y0)
{
	double res=0.0;
	res = martix[0][0]*x0;
	res = res+martix[0][1]*y0;
	res = res+martix[0][2]*1;
	printf("%lf ",res);
	return res;
}

double caly(double x0, double y0)
{
	double res=0.0;
	res = martix[1][0]*x0;
	res = res+martix[1][1]*y0;
	res = res+martix[1][2]*1;
	printf("%lf ",res);
	return res;
}

void RenderScene()
{
	int x1,x2,x3,x4,y1,y2,y3,y4;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
/*	glBegin(GL_LINES);  
		glVertex2f(-45.0,-40.0);  
		glVertex2f(100.0,105.0); 
		glVertex2f(-45.0,0.0);  
		glVertex2f(100.0,0.0); 
		glVertex2f(0.0,-100.0);  
		glVertex2f(0.0,100.0); 
	glEnd();  */
	glColor3f(1.0,1.0,0.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();	
	glRectf(0.0,-10.0,10.0,0.0);
	glColor3f(1.0,1.0,0.0);
	glRectf(0.0,-10.0,10.0,0.0);
		glBegin(GL_LINES);  
		glVertex2f(-45.0,-40.0);  
		glVertex2f(100.0,105.0); 
		glVertex2f(-45.0,0.0);  
		glVertex2f(100.0,0.0); 
		glVertex2f(0.0,-100.0);  
		glVertex2f(0.0,100.0); 
	glEnd(); 
	x1 = calx(0.0,-10.0);
	y1 = caly(0.0,-10.0);
	x2 = calx(0.0,0.0);
	y2 = caly(0.0,0.0);
	x3 = calx(10.0,0.0);
	y3 = caly(10.0,0.0);
	x4 = calx(10.0,-10.0);
	y4 = caly(10.0,-10.0);
	glColor3f(0.0,1.0,0.0);
	glBegin (GL_QUADS);  
		glVertex2f (x1,y1);  
		glVertex2f (x2,y2);  
		glVertex2f (x3,y3);  
		glVertex2f (x4,y4);  
	glEnd(); 

/*	glColor3f(0.0,1.0,0.0);
	glRotatef(-45.0,0.0,0.0,1.0); 
	glPushMatrix(); 
	glTranslatef(20.0,20.0,0.0);
	glPushMatrix();
	glRectf(0.0,-10.0,10.0,0.0);
	glRotatef(45.0,0.0,0.0,1.0);
	glPushMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glColor3f(0.0,0.0,1.0);
	glRectf(0.0,-10.0,10.0,0.0);
	glBegin(GL_LINES);  
		glVertex2f(-45.0,-45.0);  
		glVertex2f(100.0,100.0);
	glEnd();  
*/
//	glScalef(2.0,1.0,0.5);  //在x、y和z轴放大2倍
//	glTranslatef(10.0,20.0,10.0); //再平移回参考点

//	glutWireCube(10.0);

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
		glOrtho(-50.0,50.0,-50.0/aspectRatio,50.0/aspectRatio,-50.0,50.0);
	else
		glOrtho(-50.0*aspectRatio,50.0*aspectRatio,-50.0,50.0,-50.0,50.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void main()
{
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutCreateWindow("Rotatef");

	init();
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);

	glutMainLoop();
}