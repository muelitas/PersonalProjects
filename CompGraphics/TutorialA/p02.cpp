/****************************************************************
  * File:    p02.cpp
  * Author:  Mario Esparza
  * Date:    05/04/2020
  * 
  * In this program I look at how to reset the matrix with 
  * glLoadIdentity. How to clear the COLOR_BUFFER and how to
  * change the default color of the background. I also look at
  * the reshape callback function. I play with the Viewport,
  * MatrixMode and Ortho2D functions. I also learned how to
  * change the size of a pixel and how to display two dots in the
  * screen with the help of glBegin, glEnd and glVertex2f.
  *
  * Note: Add '-lGL -lglut -lGLU' to command line when compiling.
  * 
****************************************************************/ 
#include <GL/freeglut.h>
//Everytime the window is reshaped, this callback is called. If
// we don't use this function, we will have distortions. w and h
// are automatically grabbed by the API, these are the width and
// height of the reshaped window.
void reshape(int w, int h){
	//First, initialize viewport (what we will be able to see)
	glViewport(0,0,w,h); //x and y start from bottom left
	//Up until here, we are in MODELVIEW, we use this func-
	// tion to switch to PROJECTION matrix. Only use PROJEC-
	// when you need to change the projection, otherwise, use
	// MODELVIEW
	glMatrixMode(GL_PROJECTION);
	//This function "resets" the matrix (rotations, transfor-
	// mations, etc.)
	glLoadIdentity();
	gluOrtho2D(-10,10,-10,10);
	glMatrixMode(GL_MODELVIEW);

	return;
}
void display(){
	//Clear the colors of the pixels to their default color
	// Default color is black. To change the default color,
	// uncomment glClearColor function in main and set the
	// default color to whichever color you want.
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	//Default color of points is white
	glPointSize(10); //10 pixels
	glBegin(GL_POINTS);
	glVertex2f(5,5);
	glVertex2f(-5,-5);
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
