#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>

GLubyte rasters[24] = {
    0xff, 0xff, 0xff, 0xff, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01,
    0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0xff, 0xff,
    0xff, 0xff, 0x80, 0x01
};

GLubyte rasters1[24] = {
    0xff, 0xff, 0xff, 0xff, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01,
    0x80, 0x01, 0xff, 0xff, 0xff, 0xff, 0x01, 0x80, 0x01, 0x80,
    0x01, 0x80, 0x01, 0x80
};

GLubyte rasters2[24] = {
    0x80, 0x01, 0xc0, 0x01, 0xe0, 0x01, 0xf0, 0x01, 0xd8, 0x01,
    0xcc, 0x01, 0xc6, 0x01, 0x83, 0x01, 0x81, 0x81, 0x80, 0xc1,
    0x80, 0x61, 0x80, 0x31
};

void init(void)
{
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    // Thi?t l?p l?i v? trí hi?n t?i
    glRasterPos2i(50, 50);

    // L?nh v?
    glBitmap(20, 24, 0.0, 0.0, 22.0, 0.0, rasters);
    glBitmap(20, 24, 0.0, 0.0, 22.0, 0.0, rasters1);
    glBitmap(20, 24, 0.0, 0.0, 22.0, 0.0, rasters2);
    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // C?u h?nh ma tr?n chi?u ð? gi? nguyên t? l?
    glOrtho(0, w, 0, h, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:
        exit(0);
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);  // Kích thý?c c?a s? l?n hõn
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

