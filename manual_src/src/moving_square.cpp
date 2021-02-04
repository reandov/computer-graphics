#include <windows.h>
#include <stdio.h>
#include "GL/glut.h"

void init();
void draw();
void keyboard(unsigned char key, int x, int y);

float p1[2] = {-5,  5};
float p2[2] = { 5,  5};
float p3[2] = { 5, -5};
float p4[2] = {-5, -5};

int main(int argc, char** argv) {
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA | GLUT_ALPHA);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 600) / 2,
                           (glutGet(GLUT_SCREEN_HEIGHT) - 600) / 2);
    glutCreateWindow("Moving Square");

    init();
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(draw);

    glutMainLoop();

    return 0;
}

void init() {
    glClearColor(0, 0, 0, 0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'w':
            p1[1] += 1;
            p2[1] += 1;
            p3[1] += 1;
            p4[1] += 1;
            glutPostRedisplay();
            break;
        case 'd':
            p1[0] += 1;
            p2[0] += 1;
            p3[0] += 1;
            p4[0] += 1;
            glutPostRedisplay();
            break;
        case 's':
            p1[1] -= 1;
            p2[1] -= 1;
            p3[1] -= 1;
            p4[1] -= 1;
            glutPostRedisplay();
            break;
        case 'a':
            p1[0] -= 1;
            p2[0] -= 1;
            p3[0] -= 1;
            p4[0] -= 1;
            glutPostRedisplay();
            break;
        default:
            break;
    }
}

void draw_square() {
    glColor3f(1.0, 0.0, 0.0);
    glVertex2fv(p1);
    glVertex2fv(p2); 
    glVertex2fv(p3);
    glVertex2fv(p4);
}

void draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-25, 25, -25, 25, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBegin(GL_QUADS);
        draw_square();
    glEnd();

    glutSwapBuffers(); 
}