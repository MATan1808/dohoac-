#include <GL/glut.h>
#include <cmath>

void initGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glOrtho(-2, 2, -2, 2, -1, 1);
}

void drawPentagon()
{
    GLfloat radius = 1.0f;
    GLfloat angle, x, y;

    glBegin(GL_LINE_LOOP);

    for (int i = 0; i < 5; i++)
    {
        angle = i * (2.0 * M_PI / 5);
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex2f(x, y);
    }

    glEnd();
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);
    glViewport(0, 0, 600, 600);
    drawPentagon();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Pentagon Demo");
    glutDisplayFunc(myDisplay);
    initGL();
    glutMainLoop();
    return 1;
}

