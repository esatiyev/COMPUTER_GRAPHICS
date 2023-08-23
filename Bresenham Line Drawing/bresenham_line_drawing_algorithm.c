#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;
int x1, x2, y1, y2;

void display(void) {

  int dx, dy, x, y, x_end, i1, i2, d;
  dx = x2 - x1;
  dy = y2 - y1;
  i1 = 2 * dy;
  i2 = 2 * (dy - dx);
  d = i1 - dx;
  
  x = (dx < 0) ? x2 : x1;
 
  y = (dx < 0) ? y2 : y1;
  x_end = (dx < 0) ? x1 : x2; 
  
  glColor4f(1, 0, 0,1);
  glBegin(GL_POINTS);
  glVertex2i(x, y);
  glVertex2i(10, 10);
  glVertex2i(11, 11);
   glVertex2i(12, 12);
  glVertex2i(13, 13);
  glEnd();
  
  printf("%d %d\n",x, y);
  
  while(x<x_end){
    d += (d < 0) ? i1 : i2;
    y += (d < 0) ? 0 : 1;
    
    x++;
    
    printf("%d %d\n",x, y);
    
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd;
    
 
  }
  
  glFlush();
}

void myInit(void) {
  glClearColor(1000, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

int main(int argc, char ** argv) {

  printf("Value of x1 : ");
  scanf("%d", & x1);
  printf("Value of y1 : ");
  scanf("%d", & y1);
  printf("Value of x2 : ");
  scanf("%d", & x2);
  printf("Value of y2 : ");
  scanf("%d", & y2);
  glutInit( & argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DOUBLE);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(100, 150);
  glutCreateWindow("Bresenham Line Drawing Algorithm");
  myInit();
  glutDisplayFunc(display);
  glutMainLoop();
}
