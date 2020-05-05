/****************************************************************
  * File:    p03.cpp
  * Author:  Mario Esparza
  * Date:    05/04/2020
  * 
  * In this program I look at GL_TRIANGLES, GL_QUADS, GL_POLYGON
  *
  * Note: Add '-lGL -lglut -lGLU' to command line when compiling.
  * 
****************************************************************/ 
#include <GL/freeglut.h>
void reshape(int w, int h){
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10,10,-10,10);
	glMatrixMode(GL_MODELVIEW);
	return;
}
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	//To create a trapezoid use:
	glBegin(GL_QUADS);
	glVertex2f(-7,7);
	glVertex2f(-6,8);
	glVertex2f(-3,8);
	glVertex2f(-2,7);
	glEnd();

	//For front side, specify vertices counter clockwise. To
	// create the same trapezoid with polygons:
	glBegin(GL_POLYGON);
	glVertex2f(-7,5);
	glVertex2f(-2,5);
	glVertex2f(-3,6);
	glVertex2f(-6,6);
	//Notice I had to change the order of the vertices. If I
	// would've left them the same, it wouldn't display.
	glEnd();
	
	//To create a square use:
	glBegin(GL_QUADS);
	glVertex2f(7,7);
	glVertex2f(7,8);
	glVertex2f(8,8);
	glVertex2f(8,7);
	glEnd();

	//To create two trianlges use:
	glBegin(GL_TRIANGLES);
	glVertex2f(1,1);
	glVertex2f(1,2);
	glVertex2f(2,1);
	glVertex2f(-1,-1);
	glVertex2f(-1,-2);
	glVertex2f(-2,-1);
	glEnd();
	glFlush(); //This the "display" command.
}

void keyboard(unsigned char key, int x, int y){
	if(key == 'q' || key == 'Q'){
		exit(0);
	}
	return;
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(512,512);
	glutInitWindowSize(512,512);
	glutCreateWindow("My 1st Window");

	//Callback Functions
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	//glClearColor(1.0,1.0,1.0,1.0);
	glutMainLoop();
	return 0;
}
