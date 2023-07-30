#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
//#include <GL/glut.h>

using namespace std;

const int WIDTH = 640;
const int HEIGHT = 480;

// Function to plot a point on the screen
void plot(int x, int y) {
  glBegin(GL_POINTS);
  glVertex2i(x, HEIGHT - y);
  glEnd();
}

// Function to display the graph
void display() {
  glClear(GL_COLOR_BUFFER_BIT);

  // Define the points to be plotted
  int x[] = {10, 20, 30, 40, 50};
  int y[] = {100, 200, 300, 400, 500};

  // Plot the points
  for (int i = 0; i < 5; i++) {
    plot(x[i], y[i]);
  }

  glFlush();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(WIDTH, HEIGHT);
  glutCreateWindow("Line Graph");
  glClearColor(1.0, 1.0, 1.0, 0.0);
  gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);

  glutDisplayFunc(display);
  glutMainLoop();

  return 0;
}
