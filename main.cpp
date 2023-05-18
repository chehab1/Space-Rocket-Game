#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<math.h>
#include <stdlib.h>
#include "tools/tools.cpp"
#include "components/RocketShip.cpp"

int phyWidth = 700;
int phyHeight = 700;
int logWidth = 100;
int logHeight = 100;
int centerX = logWidth/2;
int centerY = logHeight/2;
int mouseX = centerX, mouseY = centerY;
int startButton[4] = {35, 45, 65, 55}; // [x1, y1, x2, y2]

RocketShip rocketShip;
tools tool;

void passiveMouse(int x, int y) {
    mouseX = x;
    mouseX=0.5+1.0*mouseX*logWidth/phyWidth;
    mouseY = phyHeight - y;
    mouseY=0.5+1.0*mouseY*logHeight/phyHeight;
    glutPostRedisplay();
}



void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    rocketShip.drawRocket(mouseX, mouseY);
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
    //glutMouseFunc(mouseClick);
    glutPassiveMotionFunc(passiveMouse);
    glutMainLoop();
}
