#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
int currentMode = 0;
const int ModeNums = 6;
GLfloat angle = 0.0;
GLfloat omega = 0.10;	//旋转角速度
void init()
{
	glClearColor(1.0,1.0,1.0,1.0);
}
void myKey( unsigned char key, int x, int y) //响应ASCII对应键，鼠标的当前x和y位置也被返回。
{
	switch(key)
	{
		case ' ': currentMode = (currentMode+1)%ModeNums;
			      glutPostRedisplay();
				  break;
		//u,d控制旋转速度
		case 'u':  omega +=0.10;
			printf("%d\n",omega);
				  break;
		case 'd':  omega -=0.10;
				  break;
		case 27:  exit(0);
	}
}

void myidle()  
{  
    angle += omega;  
    if(angle > 360.0)
		angle -= 360.0;
    glutPostRedisplay();  
}  

void RenderScene()
{
	int i=0;
	glClear(GL_COLOR_BUFFER_BIT);
	switch(currentMode)	//根据模式选择当前的操作
	{
		case 0: glutIdleFunc(NULL);
				glPointSize(5);
				glBegin(GL_POINTS);
					glColor3f(1.0,0.0,0.0);
					glVertex2f( 3.0, 3.0 );
					glVertex2f( 9.0, 3.0 );
					glVertex2f( 6.0, 8.196 );
				glEnd();
				glFlush();
				glutSwapBuffers();
				break;
		case 1: glBegin(GL_LINE_LOOP);
			    glColor3f(0.0,1.0,0.0);
				glVertex2f( 3.0, 3.0 );
					glVertex2f( 9.0, 3.0 );
					glVertex2f( 6.0, 8.196 );
				glEnd();
				glFlush();
				glutSwapBuffers();
			    break;
		case 2: glBegin(GL_TRIANGLES);
			    glColor3f(0.5,0.5,0.0);
				glVertex2f( 3.0, 3.0 );
					glVertex2f( 9.0, 3.0 );
					glVertex2f( 6.0, 8.196 );
				glEnd();
				glFlush();
				glutSwapBuffers();
				break;
		case 3: glClear(GL_COLOR_BUFFER_BIT); 
				glLoadIdentity();
				glTranslatef(6.0f,0.0f, 0.0f);
				glBegin(GL_POLYGON);  
					glVertex2f(3.0, 3.0);  
					glVertex2f(9.0, 3.0);  
					glVertex2f(6.0, 8.196);  
				glEnd();
				glTranslatef(-6.0f, 0.0f, 0.0f);
				glFlush();
				glutSwapBuffers();
				break;
		case 4: glClear(GL_COLOR_BUFFER_BIT); 
				glLoadIdentity(); 
				glScalef(2.0f,2.0f, 0.0f);
				glBegin(GL_POLYGON);  
					glVertex2f(3.0, 3.0);  
					glVertex2f(9.0, 3.0);  
					glVertex2f(6.0, 8.196);  
				glEnd();
				glScalef(0.5f, 0.5f, 0.0f);
				glFlush();
				glutSwapBuffers();
				break;
		case 5: //glClear(GL_COLOR_BUFFER_BIT); 
				//glLoadIdentity();
				//angle += 0.0; 
				//while(currentMode==5)
				{
					glutIdleFunc(myidle);
					glClear(GL_COLOR_BUFFER_BIT); 
					glLoadIdentity();
					glColor3f(1.0,0.0,0.0);
					//angle += 10;
					//if(angle > 360.0)
						//angle -= 360.0;
					glPushMatrix();
					glTranslatef(6.0f, 4.732f, 0.0f);
					glPushMatrix();
					glRotatef(angle, 0.0, 0.0, 1.0);
					glPushMatrix();
					glBegin(GL_POLYGON);  
						glVertex2f(3.0-6.0, 3.0-4.732);  
						glVertex2f(9.0-6.0, 3.0-4.732);  
						glVertex2f(6.0-6.0, 8.196-4.732);  
					glEnd();
					glFlush();
					glutSwapBuffers();
					glTranslatef(-6.0f, -4.732f, 0.0f);
					glPopMatrix();
					glPopMatrix();
					glPopMatrix();
					//printf("%f	",angle);
					//Sleep(30);
				}
				break;
	}
}
void ChangeSize(GLsizei w,GLsizei h)
{
	float ratio;
	if(h==0)
		h = 1;
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	ratio = (float)w/(float)h;
	if(w<=h)
		gluOrtho2D(0.0,20.0,0.0/ratio,20.0/ratio);
	else
		gluOrtho2D(0.0*ratio,20.0*ratio,0.0,20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void main()
{
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(1000,1000);
	glutCreateWindow("KeyboardFunc");

	init();
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutKeyboardFunc(myKey);  //为当前窗口设置键盘回调函数。
	glutIdleFunc(myidle);

	printf("Press space to continue,press escape to exit!\n");
	glutMainLoop();
}