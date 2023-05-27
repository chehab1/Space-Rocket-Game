#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <sstream>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "tools/tools.cpp"
#include "components/RocketShip.cpp"
#include "components/asteroids.cpp"
#include "components/stars.cpp"

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
int gameOver = 0;

RocketShip rocketShip;
tools tool;
asteroids asteroid1;
stars star;

void restart(int key, int x, int y) {
    if(key == GLUT_KEY_F1 && gameOver == 1) {
        score = 0;
        gameplayTime = 20;
        gameOver = 0;
        asterCount = 25;
    }
    
}

void changeBeamColor(unsigned char key, int x, int y) {
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
    glutTimerFunc(1, Timer, value);
    glutPostRedisplay();
}

void destroy() {
    int beamLeft = mouseX - 5;
    int beamRight = mouseX + 5;
    int asteroidLeft = asteroid1.x - 3;
    int asteroidRight = asteroid1.x + 3;
    if (asteroidLeft >= beamLeft && asteroidRight <= beamRight && laserBeamColor == asteroid1.color) {
        asteroid1.kill();
        score++;
    }
}

void decreaseTime(int value) {
    glutTimerFunc(1000, decreaseTime, value);
    gameplayTime--;
}

void fallingAsteroid() {
    
    asteroid1.render();
    if (asteroid1.y < 10) {
        asterCount--;
        asteroid1.create();
    }
    destroy();
}

void gameOverScreen() {
    glClear(GL_COLOR_BUFFER_BIT);
    tool.printSome("Game Over!", 40, 70, 1, 1, 1);
    stringstream ss;
    ss << "Your Score: " << score;
    tool.printSome(ss.str().c_str(), 40, 60, 1, 1, 1);
    tool.printSome("Press F1 to restart", 40, 50, 1, 1, 1);

}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    rocketShip.drawRocket(mouseX, mouseY, laserBeamColor); // draw rocket
    std::stringstream ss1;
    ss1 << "Time: " << gameplayTime;
    tool.printSome(ss1.str().c_str(), 84, 96, 1, 1, 1);
    std::stringstream ss;
    ss << "Score: " << score;
    
    tool.printSome(ss.str().c_str(), 1, 96, 1, 1, 1);

    star.createStars();


    if (asterCount > 0 && gameplayTime > 0) {
        fallingAsteroid();
    }
    else{
        gameOver = 1;
        gameOverScreen();
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
    glutSpecialFunc(restart);
    Timer(0);
    decreaseTime(0);
    glutMainLoop();
}
