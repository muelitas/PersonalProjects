/****************************************************************
  * File:    p01.cpp
  * Author:  Mario Esparza
  * Date:    05/04/2020
  * 
  * This will be a series of programs in which I will implement
  * what is being said in this Youtube tutorial: C/C++ OpenGL
  * Tutorials | Computer Graphics using OpenGL and GLUT. It can't
  * get more basic. This program only displays a window and uses
  * the keyobard 'q' to quit the program.
  *
  * Note: Add '-lGL -lglut' to command line when compiling.
  * 
****************************************************************/ 
#include <GL/freeglut.h>

void display(){ //dummy function; for now

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
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
