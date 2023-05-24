#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include <stdlib.h>
#include "tools/tools.cpp"
#include "components/RocketShip.cpp"
#include "components/asteroids.cpp"

int phyWidth = 700;
int phyHeight = 700;

int logWidth = 100;
int logHeight = 100;

int centerX = logWidth / 2;
int centerY = logHeight / 2;

int mouseX = centerX;
int mouseY = centerY;

int laserBeamColor = 0;
int asterCount = 25;
int score = 0;

RocketShip rocketShip;
tools tool;
asteroids asteroid1;

void changeBeamColor(unsigned char key, int x, int y){
    if (key == 32)
    {
        if (laserBeamColor < 2)
            laserBeamColor++;
        else
            laserBeamColor = 0;
    }
    glutPostRedisplay();
}

void passiveMouse(int x, int y) {
    mouseX = x;
    mouseX = 0.5 + 1.0 * mouseX * logWidth / phyWidth;
    mouseY = phyHeight - y;
    mouseY = 0.5 + 1.0 * mouseY * logHeight / phyHeight;
    glutPostRedisplay();
}

void Timer(int value) {
    glutTimerFunc(1, Timer, value);
    glutPostRedisplay();
}

void fallingAsteroid() {
    asteroid1.render();
    if (asteroid1.y < 15) {
        asterCount--;
        asteroid1.create();
    }
    
    // destroy atersoid
    //Beam_left_borders = mouseX - (beamwidth / 2);
    //Asteroid_Right_Borders = asteroid.x + asteroid.radius
    //Asteroid_Left_Borders = asteroid.x - asteroid.radius
    //if(Beam_left_borders < Asteroid_Right_Borders && Beam_left_borders >= Asteroid_Right_Borders && Beamcolor = asteroid.color)
    //  asterCount--; 
    //  score++;
    //  asteroid1.create();
    //  asterDownY = 0;
    
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    rocketShip.drawRocket(mouseX, mouseY, laserBeamColor);
    
    if (asterCount) {
        fallingAsteroid();
    }
    glutSwapBuffers();
    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Road picture");
    tool.init2D(0, 0, 0);
    glutDisplayFunc(display);
    glutPassiveMotionFunc(passiveMouse);
    glutKeyboardFunc(changeBeamColor);
    Timer(0);
    glutMainLoop();
}
