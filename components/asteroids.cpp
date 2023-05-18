#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<math.h>
#include <stdlib.h>

tools myTool;

class asteroids {
public:
    
    void drawAsteroid(int x, int y, int raduis, int num_segments) {
        int randomColor = 1+rand() % 3;
        if (randomColor == 1) {
           myTool.drawCircle(50, 50, 10, 100, 1, 0, 0);
        }
        else if (randomColor == 2) {
           myTool.drawCircle(50, 50, 10, 100, 0, 1, 0);
        }
        else {
           myTool.drawCircle(50, 50, 10, 100, 0, 0, 1);
        }
    }
};