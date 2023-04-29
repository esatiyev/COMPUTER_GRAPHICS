#include <iostream>
#include <gl/gl.h>
#include <gl/glut.h>

using namespace std;
int x_centre, y_centre, r;

void mid_point(void);
void init (void){
/* select clearing (background) color */
glClearColor (1.0, 1.0, 1.0, 1.0);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();

gluOrtho2D(-300, 300, -300, 300);

}
int main(int argc, char** argv) {
	cout << "x_centre: ";
	cin >> x_centre;
	cout << "y_centre: ";
	cin >> y_centre;
	cout << "radius: ";
	cin >> r;
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 200);
	glutCreateWindow("MID_POINT_CIRCLE");
    init();
	
	glutDisplayFunc(mid_point);
	glutMainLoop();
	
	return 0;
}

void mid_point(void){
	glClear (GL_COLOR_BUFFER_BIT);

	int x = 0, y = r, p = 1 - r;
	
	while(x < y){
		glColor3f(1.0, 0.0, 1.0);
		glBegin(GL_POINTS);
		glVertex2i(x + x_centre, y + y_centre);
	    glVertex2i(-x + x_centre, y + y_centre);
	    glVertex2i(-y + x_centre, x + y_centre);
	    glVertex2i(-y + x_centre, -x + y_centre);
	    glVertex2i(-x + x_centre, -y + y_centre);
	    glVertex2i(x + x_centre, -y + y_centre);
	    glVertex2i(y + x_centre, -x + y_centre);
	    glVertex2i(y + x_centre, x + y_centre);
	    glEnd();
		
		if(p < 0){
			x++;
			p = p + 2 * x + 1;
		}
		else if(p >= 0){
			x++;
			y--;
			p = p + 2 * (x - y) + 1;
		}
		
		
	}
	
	glBegin(GL_POINTS);
	glVertex2i(x_centre, y_centre);
	glEnd();
	
	glFlush();
}
