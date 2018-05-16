#include <GL/glut.h>
#include <stdio.h>
// 将立方体的八个顶点保存到一个数组里面   
  
static const float vertex_list[][3] =   
{   
    -50.0f, -50.0f, -50.0f,   
    50.0f, -50.0f, -50.0f,   
    -50.0f, 50.0f, -50.0f,   
    50.0f, 50.0f, -50.0f,   
    -50.0f, -50.0f, 50.0f,   
    50.0f, -50.0f, 50.0f,   
    -50.0f, 50.0f, 50.0f,   
    50.0f, 50.0f, 50.0f,   
};   
  
// 将要使用的顶点的序号保存到一个数组里面   
  
static const GLint index_list[][2] =   
{   
    {0, 1},      
    {2, 3},      
    {4, 5},      
    {6, 7},      
    {0, 2},      
    {1, 3},      
    {4, 6},      
    {5, 7},  
    {0, 4},  
    {1, 5},  
    {7, 3},  
    {2, 6},
};   
  
// 绘制立方体  
  
void DrawCube(void)  
{  
    int i,j;  
      
    glBegin(GL_LINES);   
    for(i=0; i<12; ++i) // 12 条线段  
  
    {  
        for(j=0; j<2; ++j) // 每条线段 2个顶点  
  
        {  
            glVertex3fv(vertex_list[index_list[i][j]]);       
        }  
    }  
    glEnd();  
}  

void init()
{
	glClearColor(1.0,1.0,1.0,1.0);
}
void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5,0.5,0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(45.0,0.0,1.0,1.0);//绕着向量（1,1,1）所指定的轴旋转45°,使显示立方体
	glPushMatrix();//保存矩阵状态
	glutWireCube(10.0);
	glPopMatrix();//恢复矩阵状态
	glTranslatef(-10.0,-20.0,-10.0); //将参考点平移至原点
	glPushMatrix();//保存矩阵状态
	glScalef(2.0,1.0,0.5);
	glPushMatrix();//保存矩阵状态
	glTranslatef(10.0,20.0,10.0); //恢复初始状态
	glutWireCube(10.0);
	glFlush();
}

void ChangeSize(GLsizei w, GLsizei h)
{
	GLfloat aspectRatio;
	if(h==0)
		h=1;
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	aspectRatio = (GLfloat)w/(GLfloat)h;
	if(w<=h)
		glOrtho(-30.0,30.0,-30.0/aspectRatio, 30.0/aspectRatio, -30.0, 30.0);
	else
		glOrtho(-30.0/aspectRatio, 30.0/aspectRatio, -30.0, 30.0,-30.0,30.0);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void main()
{
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutCreateWindow("Cube");

	init();
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	
	glutMainLoop();
}