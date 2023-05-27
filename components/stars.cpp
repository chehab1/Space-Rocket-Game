#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<math.h>
#include <stdlib.h>

tools tool1;

class stars {
public:
    void createStars() {
        for (int i = 0; i < 100; i++) {
            tool1.drawCircle(1 + rand() % 100, 1 + rand() % 100, 0.2, 100, 5);
        }
    }

};