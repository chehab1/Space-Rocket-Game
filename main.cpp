#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "tools/tools.cpp"
#include "components/RocketShip.cpp"
#include "components/asteroids.cpp"

using namespace std;

int phyWidth = 700;
int phyHeight = 700;

int logWidth = 100;
int logHeight = 100;

int centerX = logWidth / 2;
int centerY = logHeight / 2;

int mouseX = centerX;
int mouseY = centerY;

int laserBeamColor = 1;
int asterCount = 25; // total asteroids 25
int gameplayTime = 20;
int score = 0;

RocketShip rocketShip;
tools tool;
asteroids asteroid1;

void changeBeamColor(unsigned char key, int x, int y){
    if (key == 32)
    {
        if (laserBeamColor < 3)
            laserBeamColor++;
        else
            laserBeamColor = 1;
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
    glutTimerFunc(10, Timer, value);
    glutPostRedisplay();
}
void destroy() {
    int beamLeft = mouseX - 5;
    int beamRight = mouseX + 5;
    int asteroidLeft = asteroid1.x - 3;
    int asteroidRight = asteroid1.x + 3;
    if (asteroidLeft >= beamLeft && asteroidRight <= beamRight && laserBeamColor == asteroid1.color) {
        asteroid1.kill();
        cout << "destroyed";
    }
}

void fallingAsteroid() {
    
    asteroid1.render();
    if (asteroid1.y < 10) {
        asterCount--;
        asteroid1.create();
    }
    destroy();
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
    tool.printSome("Time:", 84, 96, 1, 1, 1);
    tool.printSome("Score:", 1, 96, 1, 1, 1);
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
