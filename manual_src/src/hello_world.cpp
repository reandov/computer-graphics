#include <windows.h>
#include "GL/glut.h"

#define RESOLUTION_HEIGHT 640
#define RESOLUTION_WIDTH 480

void init();
void draw();

int main(int argc, char** argv) {
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_DEPTH | GLUT_RGBA | GLUT_ALPHA);
    glutInitWindowSize(RESOLUTION_HEIGHT, RESOLUTION_WIDTH);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - RESOLUTION_HEIGHT) / 2,
                           (glutGet(GLUT_SCREEN_HEIGHT) - RESOLUTION_WIDTH) / 2);
    glutCreateWindow("Hello, World!");

    init();
    glutDisplayFunc(draw);

    glutMainLoop();

    return 0;
}

void init() {
    glClearColor(0, 0, 0, 0);
}

void draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10, 10, -10, 10, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBegin(GL_TRIANGLES);
        glColor3f(1, 0, 0); glVertex2f(-7,-7 ); 
        glColor3f(0, 1, 0); glVertex2f( 0, 7 ); 
        glColor3f(0, 0, 1); glVertex2f( 7,-7 ); 
    glEnd();

    glFlush(); 
}