#include <GL/glut.h> 
#include <GL/gl.h>
#include<iostream>


int ww = 600, wh = 500;

float intCol[3] = { 1.0, 1.0, 0.0 };
float fillCol[3] = { 0.0, 1.0, 0.0 };


void setPixel(int pointx, int pointy, float f[3])
{
    glBegin(GL_POINTS);
    glColor3fv(f);
    glVertex2i(pointx, pointy);
    glEnd();
    glFlush();
}

void getPixel(int x, int y, float pixels[3])
{
    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, pixels);
}

void drawPolygon(int x1, int y1, int x2, int y2)
{
    glBegin(GL_POLYGON);
    glVertex2i(x1, y1);
    glVertex2i(x1, y2);
    glVertex2i(x2, y2);
    glVertex2i(x2, y1);
    glEnd();
    glFlush();
}

void display()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    drawPolygon(150, 100, 430, 400);
    glColor3f(1.0, 1.0, 0.0);
    glFlush();
}

void floodfill4(int x, int y, float oldcolor[3], float newcolor[3])
{
    float color[3];
    getPixel(x, y, color);
    if (color[0] == oldcolor[0] && (color[1]) == oldcolor[1] && (color[2]) == oldcolor[2])
    {
        setPixel(x, y, newcolor);
        floodfill4(x + 1, y, oldcolor, newcolor);
        floodfill4(x - 1, y, oldcolor, newcolor);
        floodfill4(x, y + 1, oldcolor, newcolor);
        floodfill4(x, y - 1, oldcolor, newcolor);

    }
}

void mouse(int btn, int state, int x, int y)
{
    if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        int xi = x;
        int yi = (wh - y);
        floodfill4(xi, yi, intCol, fillCol);
    }
}

void init()
{
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 0);
    gluOrtho2D(0.0, (GLdouble)ww, 0.0, (GLdouble)wh);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(ww, wh);
    glutCreateWindow("Flood Fill");
    glutDisplayFunc(display);
    init();
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}




