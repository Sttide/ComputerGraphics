#include<gl/glut.h>
#include <stdlib.h>
float R=0;
void init(){
    glClearColor(1.0,1.0,1.0,1.0);
}
void RenderScene() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    if(R>=360) R=0;
    glRotated(R,0,0,1);
    glColor3f(0.5f,0.5f,0.5f);
    glRotated(30,1,1,1);
    glRotated(R,1,1,0);
    glutWireTeapot(0.5);
    glRotated(-R,1,1,0);
    glRotated(-30,1,1,1);
    glRotated(-R,0,0,1);
    glutSwapBuffers();
}
void ChangeSize(GLsizei w,GLsizei h) {
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
    R-=1;
    glutPostRedisplay();
    glutTimerFunc(1,Timer,1);
}
int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
    glutCreateWindow("FOR");
    init();
    glutDisplayFunc(&RenderScene);
    glutReshapeFunc(&ChangeSize);
    glutTimerFunc(33,&Timer,1);
    glutMainLoop();
    return 0;
}