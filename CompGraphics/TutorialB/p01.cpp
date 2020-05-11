/****************************************************************
  * File:    p01.cpp
  * Author:  Mario Esparza
  * Date:    05/03/2020
  *
  * In this program I follow the Youtube video called: Tut1: Ins-
  * talling, building, configuring, and testing OpenGL, FreeGlut
  * GLEW on Linux. As the title states, the tutorial shows how
  * to download freeglut and glew, as well as how to install
  * them. It also covers a very first basic OpenGL program that
  * displays a blue screen.
  *
  * Note: Add '-lGL -lglut' to command line when compiling.
  * 
****************************************************************/ 
#include <iostream>
#include <GL/freeglut.h>
using namespace std;
static void RenderSceneCB(){
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}
static void InitializeGlutCallbacks(){
	glutDisplayFunc(RenderSceneCB);
}

int main(int argc, char** argv){
	glutInit(&argc, argv); //Initialize the GLUT library
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(512,512);
	glutInitWindowPosition(5,5);
	glutCreateWindow("Hello World!");
	int wWidth = glutGet(GLUT_WINDOW_WIDTH);
	int wHeight = glutGet(GLUT_WINDOW_HEIGHT);
	cout <<"Window Width="<<wWidth<<"\n";
	cout <<"Window Height="<<wHeight<<"\n";

	InitializeGlutCallbacks();

	glClearColor(0.0f,0.0f,0.25f, 0.0f);
	glutMainLoop();
	return 0;
}

