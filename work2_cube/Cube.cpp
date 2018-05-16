#include <GL/glut.h>
#include <stdio.h>
// ��������İ˸����㱣�浽һ����������   
  
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
  
// ��Ҫʹ�õĶ������ű��浽һ����������   
  
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
  
// ����������  
  
void DrawCube(void)  
{  
    int i,j;  
      
    glBegin(GL_LINES);   
    for(i=0; i<12; ++i) // 12 ���߶�  
  
    {  
        for(j=0; j<2; ++j) // ÿ���߶� 2������  
  
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
	glRotatef(45.0,0.0,1.0,1.0);//����������1,1,1����ָ��������ת45��,ʹ��ʾ������
	glPushMatrix();//�������״̬
	glutWireCube(10.0);
	glPopMatrix();//�ָ�����״̬
	glTranslatef(-10.0,-20.0,-10.0); //���ο���ƽ����ԭ��
	glPushMatrix();//�������״̬
	glScalef(2.0,1.0,0.5);
	glPushMatrix();//�������״̬
	glTranslatef(10.0,20.0,10.0); //�ָ���ʼ״̬
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