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
   int radius = 5;

   void create()
   {
      x = 1 + rand() % 100;
      y = 100;
      color = 1 + rand() % 3;
   }

   void render(int down)
   {
      if (color == 1)
         glColor3f(1, 0, 0);

      else if (color == 2)
         glColor3f(0, 1, 0);

      else
         glColor3f(0, 0, 1);

      y -= down;

      glBegin(GL_POLYGON);
      for (int i = 0; i < segments; i++)
      {
         float theta = 2.0f * 3.1415926f * float(i) / float(segments); //get the current angle in radians
         float tempx = radius * cosf(theta);                           //calculate the x component
         float tempy = radius * sinf(theta);                           //calculate the y component
         glVertex2f(tempx + x, tempy + y);                             //output vertex
      }
      glEnd();
   }
};