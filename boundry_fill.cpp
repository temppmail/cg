#include <GL/glut.h> 
#include <GL/gl.h>
#include <iostream>

using namespace std;

float current[3];
int ww = 500, wh = 500;

void init()
{
    gluOrtho2D(0, ww, 0, wh); glClearColor(0, 0, 0, 0);
    glColor3f(1, 1, 0);
}

void plotPixel(int x, int y, float* fill_color)
{
    glColor3f(fill_color[0], fill_color[1], fill_color[2]);

    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void boundryFill(int x, int y, float* fill_color, float* boundry_color)
{
    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, current);

    if ((current[0] != boundry_color[0] || current[1] != boundry_color[1] || current[2] != boundry_color[2]) && (current[0] != fill_color[0] || current[1] != fill_color[1] || current[2] != fill_color[2]))
    {
        plotPixel(x, y, fill_color);
        boundryFill(x + 1, y, fill_color, boundry_color);
        boundryFill(x, y + 1, fill_color, boundry_color);
        boundryFill(x - 1, y, fill_color, boundry_color);
        boundryFill(x, y - 1, fill_color, boundry_color);
    }
}

void polygonShape()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    glVertex2i(250, 100);
    glVertex2i(250, 200);
    glVertex2i(100, 200);
    glVertex2i(100, 400);
    glVertex2i(250, 400);
    glVertex2i(250, 300);
    glVertex2i(400, 300);
    glVertex2i(400, 100);
    glEnd();
    glFlush();
}

void mouse(int btn, int state, int x, int y)
{
    if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        int xi = x;
        int yi = (wh - y);
        float boundry_color[3], fill_color[3];

        boundry_color[0] = 1; // boundry color - Red color
        boundry_color[1] = 1;
        boundry_color[2] = 0;

        fill_color[0] = 0; // fill color - Green Color 
        fill_color[1] = 1;
        fill_color[2] = 0;

        boundryFill(xi, yi, fill_color, boundry_color);

    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // Initializing the library
    glutInitWindowSize(ww, wh);
    glutInitWindowPosition(400, 150);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Boudary Fill");
    init();
    glutDisplayFunc(polygonShape); glutMouseFunc(mouse);
    glutMainLoop(); return 0;
}
