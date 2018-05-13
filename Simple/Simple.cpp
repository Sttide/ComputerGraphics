#include <gl/glut.h>

//设置渲染状态
void init()
{
	glClearColor(0.0f,0.0f,0.0f,1.0f);
}

void drawpoint()
{
	glBegin(GL_POINTS); //选择点作为图元
	glColor3f(1.0,0.0,0.0);//把绘图颜色设置为红色
	glVertex3f(-10.0,11.0,0.0);//指定一个点
	glColor3f(1.0,1.0,0.0);//把绘图颜色设置为黄色
	glVertex3f(-9.0,10.0,0.0);//指定另外一个点
	glEnd();//完成画点
}

void drawline()
{
	glBegin(GL_LINES);
	glColor3f(1.0,0.0,0.0);
	glVertex3f(10.0,20.0,0.0);
	glVertex3f(20.0,80.0,0.0);
	glEnd();
}

void drawlinestep()
{
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0,0.0,0.0);
	glVertex3f(10.0,60.0,0.0);
	glVertex3f(20.0,80.0,0.0);
	glVertex3f(30.0,20.0,0.0);
	glVertex3f(-20.0,10.0,0.0);
	glEnd();
}

void drawpolygon()
{
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.0,0.0);
	glVertex3f(-10.0,-60.0,0.0);
	glVertex3f(-20.0,-80.0,0.0);
	glVertex3f(-30.0,-20.0,0.0);
	glVertex3f(-20.0,-10.0,0.0);
	glEnd();
}

void drawtristrip()
{
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.0,0.0,1.0);
	glVertex3f(-30.0,-30.0,0.0);
	glVertex3f(-30.0,-40.0,0.0);
	glVertex3f(-40.0,-40.0,0.0);
	glVertex3f(-50.0,-50.0,0.0);
	glVertex3f(-60.0,-70.0,0.0);
	glVertex3f(-70.0,-80.0,0.0);
	glEnd();
}

//绘制场景
void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT);//用当前清除颜色清除窗口
	drawpoint();
	drawline();
	drawlinestep();
	drawpolygon();
	drawtristrip();
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
  glutCreateWindow("Simple");

  init();

  glutDisplayFunc( RenderScene );
  glutReshapeFunc(ChangeSize);

  glutMainLoop();
}