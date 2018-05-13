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
void MidPoint(int x0,int y0,int x1,int y1)
{
	int a, b, d1, d2, d, x, y;
	if( x0 > x1)              
    {
        swap(&x0,&y0,&x1,&y1);  
    }
    a=y0-y1, b=x1-x0;  // a=-dy,b=dx, d��һ����
    x=x0, y=y0;


	glBegin(GL_POINTS);

	if(b==0) //��ֱ��
	{
		glVertex2i(x, y);
		for(y=y0;y<=y1;y++)
		{
			glVertex2i(x,y);
		}
		glEnd();
	}
	else if(a==0) //ˮƽ��
	{
		glVertex2i(x, y);
		for(x=x0;x<=x1;x++)
		{
			glVertex2i(x,y);
		}
		glEnd();
	}
	//�ߵ��Ϸ�<0���·�>0����<0���ҷ�>0

	else if((-a)>=b && a<0)	//k>1 ��x��x++
	{	
		d = a + 2*b;
		d1=2*b, d2=2 * (a+b);   

		glVertex2f(x, y);
		while (x<x1)
		{
			if (d<0)
				{y++; d+=d1; }
			else
				{y++; x++; d+=d2;}
			glVertex2i(x, y);
		 }

		glEnd();
	}
	else if((-a)<b && a<0) //0<k<=1 ��y++��
	{
		d = 2+a + b;
		d1=2*a, d2=2 * (a+b);   
		
		glVertex2i(x, y);
		while (x<x1)
		{
			if (d<0)
				{x++; y++; d+=d2; }
			else
				{x++; d+=d1;}
			glVertex2i(x, y);
		 }

		glEnd();
	}
	else if((-a)<=b && a>0)	//-1<=k<0������y--
	{
		d = 2*a - b;
		d1=2*a, d2=2 * (a-b);   
		glVertex2f(x, y);
		while (x<x1)
		{
			if (d>0)
				{x++; y--; d+=d2; }
			else
				{x++; d+=d1;}
			glVertex2i(x, y);
		 }
		glEnd();
	}
	else if((-a>b) && a>0)	//k<-1����x++��
	{
		d = 2*a - b;
		d1=2*(-b), d2=2 * (a-b);   
		glVertex2f(x, y);
		while (x<x1)
		{
			if (d<0)
				{y--; x++; d+=d2; }
			else
				{y--; d+=d1;}
			glVertex2i(x, y);
		 }
		glEnd();
	}

}

void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f,0.0f,0.f);
	MidPoint(10,10,80,60);
	glFlush();
	MidPoint( 0, 0, 0,100);
	glFlush();
	MidPoint( 0, 0, 100, 0);
	glFlush();
	MidPoint( 20, 80, 70, 50);
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
	glutCreateWindow("MidPoint");

	init();

	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);

	glutMainLoop();
}
