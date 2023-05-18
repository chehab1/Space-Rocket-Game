#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<math.h>
#include <stdlib.h>
#include "tools/tools.cpp"
#include "components/RocketShip.cpp"
#include "components/asteroids.cpp"

int phyWidth = 700;
int phyHeight = 700;
int logWidth = 100;
int logHeight = 100;
int centerX = logWidth/2;
int centerY = logHeight/2;
int mouseX = centerX, mouseY = centerY;
int laserBeamColor = 0;

RocketShip rocketShip;
tools tool;
asteroids asteroid;

void changeBeamColor(unsigned char key, int x, int y) {
    if (key == 32) {
        if(laserBeamColor<2)
            laserBeamColor++;
        else laserBeamColor=0;
    }
}

void passiveMouse(int x, int y) {
    mouseX = x;
    mouseX=0.5+1.0*mouseX*logWidth/phyWidth;
    mouseY = phyHeight - y;
    mouseY=0.5+1.0*mouseY*logHeight/phyHeight;
    glutPostRedisplay();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    rocketShip.drawRocket(mouseX, mouseY, laserBeamColor);
    glutSwapBuffers();
    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Road picture");
    tool.init2D(0,0,0);
    glutDisplayFunc(display);
    glutPassiveMotionFunc(passiveMouse);
    glutKeyboardFunc(changeBeamColor);
    glutMainLoop();
}
