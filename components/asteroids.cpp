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

   int x = 1 + rand() % 100;
   int y = 100;
   int color = 1 + rand() % 3;
   int segments = 100;
   int radius = 3;

   void create()
   {
      x = 1 + rand() % 100;
      y = 100;
      color = 1 + rand() % 3;
   }

   void render(int down)
   {
      y -= down;  
      myTool.drawCircle(x, y, radius, segments, color);
   }
};