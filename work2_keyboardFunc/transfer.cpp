#include <gl/glut.h>
#include <math.h>  
#define DEG_TO_RAD 0.017453  //角度转弧度
//设置渲染状态
GLfloat size=1.0;
void init()
{
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glColor3f(1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

GLfloat theta = 0.0;  
void display()  
{  
    glClear(GL_COLOR_BUFFER_BIT);  
    glBegin(GL_POLYGON);  
        glVertex2f(sin(DEG_TO_RAD*theta),-cos(DEG_TO_RAD*theta));  
        glVertex2f(-cos(DEG_TO_RAD*theta),-sin(DEG_TO_RAD*theta));  
        glVertex2f(-sin(DEG_TO_RAD*theta),cos(DEG_TO_RAD*theta));  
        glVertex2f(cos(DEG_TO_RAD*theta),sin(DEG_TO_RAD*theta));  
    glEnd();  
    glFlush();  
}   

void myidle()  
{  
    theta += 0.2;  
    if(theta>360.0)  
            theta -= 360.0;  
    glutPostRedisplay();  
}  

void drawpoint()
{
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
	glVertex3f(-100.0,0.0,0.0);
	glVertex3f(100.0,0.0,0.0);
	glVertex3f(0.0,-100.0,0.0);
	glVertex3f(0.0,100.0,0.0);
	glEnd();
	glColor3f(1.0,0.0,0.0);//把绘图颜色设置为红色
	glRectf(-10.0f,-10.0,10.0,20.0f);
}


//绘制场景
void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT);//用当前清除颜色清除窗口
	drawpoint();
	glFlush();//刷新绘图命令
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

void main( )
{
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(500,500);  
	glutInitWindowPosition(0,0);  
	glutCreateWindow("Rolte");  
	glutDisplayFunc(display); 
	init();

	glutIdleFunc(myidle);
	//glutDisplayFunc( RenderScene );
	//glutReshapeFunc(ChangeSize);
	glutMainLoop();
}