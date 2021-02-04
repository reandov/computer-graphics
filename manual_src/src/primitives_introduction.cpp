#include <windows.h>
#include <math.h>
#include "GL/glut.h"

void init();
void draw();
void idle();
void keyboard(unsigned char key, int x, int y);

float initial_angle = M_PI / 6.0;
float velocity = 1;

int main(int argc, char** argv) {
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA | GLUT_ALPHA);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 600) / 2,
                           (glutGet(GLUT_SCREEN_HEIGHT) - 600) / 2);
    glutCreateWindow("Primitives");

    init();
    glutKeyboardFunc(keyboard);
    glutIdleFunc(idle);
    glutDisplayFunc(draw);

    glutMainLoop();

    return 0;
}

void init() {
    glClearColor(0, 0, 0, 0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'v':
            velocity = velocity - 0.1;
            break;
        
        case 'V':
            velocity = velocity + 0.1;
            break;

        case 'I':
            velocity = velocity * (-1);
            break;
            
        default:
            break;
    }
}

void idle() {
    initial_angle += velocity * ((2.0 * M_PI) / 360.0);

    if (initial_angle > 2 * M_PI) initial_angle -= 2 * M_PI;

    glutPostRedisplay();
}

void draw_circulo(int n, float radius) {
    
    float delta = (2.0 * M_PI) / n;

    for (int i = 0; i < n; i++) {
        float angulo = initial_angle + i * delta;
        float x = radius * cos(angulo);
        float y = radius * sin(angulo);

        glVertex2f(x, y);
    }
}

void draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-25, 25, -25, 25, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // GL_POINTS            = pontos
    // GL_LINES             = segmentos de reta de dois em dois
    // GL_LINE_STRIP        = uma linha conectada
    // GL_LINE_LOOP         = uma linha conectada fechada
    // GL_TRIANGLES         = triangulos
    // GL_TRIANGLE_STRIP    = triangulos alternados fechando outros
    // GL_TRIANGLE_FAN      = leque de triangulos
    // GL_POLYGON           = polígono CONVEXO

    glBegin(GL_POLYGON);
        draw_circulo(4, 10);
    glEnd();

    //glFlush(); // DESENHA UM BUFFER
    glutSwapBuffers(); // ALTERNA ENTRE DOIS BUFFERS
}