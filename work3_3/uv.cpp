#include<gl/glut.h>
#include <stdlib.h>
float X=0;
void init(){
    glClearColor(1.0,1.0,1.0,1.0);
}
void RenderScene() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    if(X>=5.0) X=-5.0f;
    glTranslatef(X,-X,0);
    glColor3f(0.5f,0.5f,0.5f);
    glutWireCube(1);
    glTranslatef(-X,X,0);
    glutSwapBuffers();
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
        glOrtho(-5.0,5.0,-5.0/aspectRatio,5.0/aspectRatio,2.0,-2.0);
    else
        glOrtho(-5.0*aspectRatio,5.0*aspectRatio,-5.0,5.0,2.0,-2.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}
void Timer(int value){
    X+=0.002;
    glutPostRedisplay();
    glutTimerFunc(1,Timer,1);
}
int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
    glutCreateWindow("uv");
    init();
    glutDisplayFunc(&RenderScene);
    glutReshapeFunc(&ChangeSize);
    glutTimerFunc(20,&Timer,1);
    glutMainLoop();
    return 0;
}