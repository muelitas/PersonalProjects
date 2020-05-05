/****************************************************************
  * File:    p01.cpp
  * Author:  Mario Esparza
  * Date:    05/04/2020
  * 
  * In this program I review the first example seen in CS 420 - 
  * Computer Graphics, here I ... TODO
  *
  * Note: Add '-lGL -lglut' to command line when compiling.
  * 
****************************************************************/ 
#include <stdlib.h>
#include <GL/freeglut.h>

GLfloat vertices[][3]={ {-1,-1,-1},{1,-1,-1},{1,1,-1},
			{-1,1,-1},{-1,-1,1},{1,-1,1},
			{1,1,1},{-1,1,1}};

GLfloat colors[][3]={	{0,0,0},{1,0,0},{1,1,0},
			{0,1,0},{0,0,1},{1,0,1},
			{1,1,1},{0,1,1}};

void polygon(int a, int b, int c, int d){
	glBegin(GL_POLYGON);
	glColor3fv(colors[a]);
	glVertex3fv(vertices[a]);
	glColor3fv(colors[b]);
	glVertex3fv(vertices[b]);
	glColor3fv(colors[c]);
	glVertex3fv(vertices[c]);
	glColor3fv(colors[d]);
	glVertex3fv(vertices[d]);
	glEnd();
	return;
}

void colorcube(){
	polygon(0,3,2,1);
	polygon(2,3,7,6);
	polygon(0,4,7,3);
	polygon(1,2,6,5);
	polygon(4,5,6,7);
	polygon(0,1,5,4);
	return;
}

void myReshape(int w, int h){
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2,2,-2,2,-10,10);
	glMatrixMode(GL_MODELVIEW);
	return;
}

void keyboard(unsigned char key, int x, int y){
	if(key == 'q' || key == 'Q'){
		exit(0);
	}
	return;
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glShadeModel(GL_SMOOTH);
	glLoadIdentity();
	//glRotatef();
	colorcube();
	glFlush();
	glutSwapBuffers();
	return;
}

int main(int argc, char** argv){
	glutInit(&argc, argv); //Initialize the GLUT library
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA|GLUT_DEPTH);
	glutInitWindowSize(512,512);
	glutInitContextFlags(GLUT_COMPATIBILITY_PROFILE);
//	glutInitWindowPosition(5,5);
	glutCreateWindow("Colored Cube");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}
