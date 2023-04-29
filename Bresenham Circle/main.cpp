#include <iostream>
#include <gl/gl.h>
#include <gl/glut.h>

int x_centre, y_centre, r;
using namespace std;

void init (void){
/* select clearing (background) color */
glClearColor (1.0, 1.0, 1.0, 1.0);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();

gluOrtho2D(-300, 300, 0, 600);
}

void Bresenham_Circle(void){
	glClear(GL_COLOR_BUFFER_BIT);

    int x=0,y=r,d=3-(2*r);  
    
  
    while(x<=y){ 
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
		 
        if(d<=0){  
            d=d+(4*x)+6;  
        }  
        else{  
            d=d+(4*x)-(4*y)+10;  
            y=y-1;  
        }  
        x=x+1;    
    }  
    
    glFlush();
    
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
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Bresenham Circle Drawing");
	init();
	glutDisplayFunc(Bresenham_Circle);
	glutMainLoop();
	return 0;
}