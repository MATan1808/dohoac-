#include <GL/glut.h>
#include <cmath>

void initGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glOrtho(-6, 6, -6, 6, -1, 1);
}

void drawStar()
{
    GLfloat step = 3.14 / 30.0; // S?a s? bý?c ð? có 60 cánh
    GLfloat angle, r;

    glBegin(GL_LINE_LOOP);

    for (int i = 0; i < 60; i++) // S?a s? lý?ng cánh thành 60
    {
        r = (i % 2 == 0 ? 2 : 5);
        angle = i * step;

        glVertex3f(r * cos(angle), r * sin(angle), 0.0);
    }

    glEnd();
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);
    glViewport(0, 0, 600, 600);
    drawStar();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Star Demo");
    glutDisplayFunc(myDisplay);
    initGL();
    glutMainLoop();
    return 1;
}

