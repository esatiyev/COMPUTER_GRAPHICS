#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <gl/gl.h>
#include <gl/glut.h>

using namespace std;
int x1, x2, y1, y2;

void init(void) {
	glClearColor(1, 1, 1, 1);
	
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-300, 300, 0, 600); // yazilmasa, isl?mir
}

void setPixel(int x, int y) {
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}
void Bresenham_Line(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	int dx, dy, i1, i2, d, x, y, x_end, y_end;
	dx = x2 - x1;
	dy = y2 - y1;
	i1 = 2 * dy;
	i2 = 2 * (dy - dx);
	d = i1 - dx;
	
	if(dx < 0 || dy < 0) {
		x = x2;
		y = y2;
		i1 = -i1;
		i2 = -i2;
		x_end = x1;
		y_end = y1;
	}
	else {
		x = x1;
		y = y1;
		x_end = x2;
		y_end = y2;
	}
	
	while(x <= x_end || y <= y_end) {
		setPixel(x, y);
		cout << x << " " << y << endl;
		if(x == x_end && y == y_end) break;
		
		if(d < 0) {
			d += i1;
		}
		else {
			d += i2;
			if(y != y_end) y++;
		}
		
		if(x != x_end) x++;
	}
	
	glFlush();
}

int main(int argc, char** argv) {
	cout << "Value of x1: ";
	cin >> x1;
	cout << "Value of y1: ";
	cin >> y1;
	cout << "Value of x2: ";
	cin >> x2;
	cout << "Value of y2: ";
	cin >> y2;
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(200, 100);
	
	glutCreateWindow("Bresenham Line Drawing");
	init();
	
	glutDisplayFunc(Bresenham_Line);
	glutMainLoop();
	return 0;
}