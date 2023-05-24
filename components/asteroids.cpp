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

   int x = 50;  // start first asteroid at 50 in x axis (Middle of screen)
   int y = 100; // start all asteroids at 100 in y axis (Top of screen)
   float rate = 0.1; // speed in which asteroids fall
   int color = 1 + rand() % 3; // generate random color for asteroids (r,g,b)

   void create() {
      x = 10 + rand() % 90;
      y = 100;
      color = 1 + rand() % 3;
   }

   void render() {
      myTool.drawCircle(x, y, 3, 100, color);
      y -= rate;
   }

   void kill() {
      y = 0;
   }
};