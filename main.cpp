/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

GLdouble xRotated,yRotated,zRotated;
//torus
GLdouble innerRaduis = 0.5;
GLdouble outterRaduis = 1.5;
GLint side = 25;
GLint rings = 25;
/* GLUT callback Handlers */

void displayTorus(void){

glMatrixMode(GL_MODELVIEW);
glClear(GL_COLOR_BUFFER_BIT);

glLoadIdentity();

glTranslatef(0.0,0.0,-8);
glColor3f(0.8,0.2,0.6);

glRotated(xRotated,1.0,0.0,0.0);
glRotated(yRotated,0.0,1.0,0.0);

glScalef(1.0,1.0,1.0);
glutSolidTorus(innerRaduis,outterRaduis,side,rings);
glFlush();

}
void reshapeTorus(int x, int y){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
    glViewport(0,0,x,y);
}
void idleTorus(void){
yRotated += 0.01;
displayTorus();

}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB);

    glutInitWindowSize(400,400);

    glutCreateWindow("Torus Rotating");
    glPolygonMode(GL_FRONT_AND_BACK , GL_LINE);
    xRotated = yRotated = zRotated = 30.0;
    xRotated = 33;
    yRotated = 40;
    glClearColor(0.0,0.0,0.0,0.0);

    glutDisplayFunc(displayTorus);
    glutReshapeFunc(reshapeTorus);
    glutIdleFunc(idleTorus);
    glutMainLoop();

    return 0;
}
