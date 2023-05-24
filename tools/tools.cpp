#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>

using namespace std;

class tools {
public:
    void drawCircle(float cx, float cy, float radius, int num_segments, int color) {
        if (color == 1)
            glColor3f(1, 0, 0);

        else if (color == 2)
            glColor3f(0, 1, 0);

        else
            glColor3f(0, 0, 1);

        glBegin(GL_POLYGON);
        for (int i = 0; i < num_segments; i++)
        {
            float theta = 2.0f * 3.1415926f * float(i) / float(num_segments); //get the current angle in radians
            float x = radius * cosf(theta);                                   //calculate the x component
            float y = radius * sinf(theta);                                   //calculate the y component
            glVertex2f(x + cx, y + cy);                                       //output vertex
        }
        glEnd();
    }

    void init2D(float r, float g, float b) {
        glClearColor(r, g, b, 0);
        glMatrixMode(GL_PROJECTION);
        gluOrtho2D(0.0, 100.0, 0.0, 100.0);
    }

    void printSome(string str, int x, int y, float r, float g, float b) {
        glColor3f(r, g, b);
        glRasterPos2d(x, y);
        for (int i = 0; i < str.size(); i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
        glFlush();
    }
};