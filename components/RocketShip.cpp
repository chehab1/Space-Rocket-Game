#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<math.h>
#include <stdlib.h>

class RocketShip {
public:
    void laserBeam() {
        
    }

    void drawRocket(int x, int y) {
        //Rocket Body (white)
        glColor3f(1, 1, 1);
        glBegin(GL_POLYGON);
        glVertex2f(x - 3, y - 4);
        glVertex2f(x + 3, y - 4);
        glVertex2f(x + 3, y + 4);
        glVertex2f(x - 3, y + 4);
        glEnd();

        //Rocket tip (Blue)
        glColor3f(0.53, 0.8, 0.98);
        glBegin(GL_POLYGON);
        glVertex2f(x - 3, y + 4);
        glVertex2f(x + 3, y + 4);
        glVertex2f(x, y + 8);
        glEnd();

        //Rocket left wing (blue)
        glColor3f(0.53, 0.8, 0.98);
        glBegin(GL_POLYGON);
        glVertex2f(x - 3, y - 4);
        glVertex2f(x - 6, y - 4);
        glVertex2f(x - 3, y);
        glEnd();

        //Rocket right wing (blue)
        glColor3f(0.53, 0.8, 0.98);
        glBegin(GL_POLYGON);
        glVertex2f(x + 3, y - 4);
        glVertex2f(x + 6, y - 4);
        glVertex2f(x + 3, y);
        glEnd();

        //Rocket Fire (red)
        glColor3f(0.88, 0.34, 0.13);
        glBegin(GL_POLYGON);
        glVertex2f(x - 2, y - 4);
        glVertex2f(x + 2, y - 4);
        glVertex2f(x + 2, y - 5);
        glVertex2f(x - 2, y - 5);
        glEnd();


    }
};
