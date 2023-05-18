#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<math.h>
#include <stdlib.h>

class tools {
public:
    void drawCircle(float cx, float cy, float raduis, int num_segments, float r, float g, float b) {
        glColor3f(r, g, b);
        glBegin(GL_POLYGON);
        for (int i = 0; i < num_segments; i++) {
            float theta = 2.0f * 3.1415926f * float(i) / float(num_segments); //get the current angle in radians
            float x = raduis * cosf(theta);//calculate the x component
            float y = raduis * sinf(theta);//calculate the y component
            glVertex2f(x + cx, y + cy);//output vertex
        }
        glEnd();
    }
    
    void init2D(float r, float g, float b) {
        glClearColor(r, g, b, 0);
        glMatrixMode (GL_PROJECTION);
        gluOrtho2D (0.0, 100.0, 0.0, 100.0);
    }

    void printSome(char* str, int x, int y, float r, float g, float b) {
        glColor3f(r, g, b);
        glRasterPos2d(x,y);
        for (int i=0;i<strlen(str);i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
        glFlush();
    }
};