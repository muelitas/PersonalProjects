/****************************************************************
  * File:    p04.cpp
  * Author:  Mario Esparza
  * Date:    05/04/2020
  * 
  * In this program I look at GL_DOUBLE, glutSwapBuffers(),
  * glutTimerFunc() and glutPostRedisplay(). At the end we get an
  * animated square moving from left to right and right to left.
  *
  * Note: Add '-lGL -lglut -lGLU' to command line when compiling.
  * 
****************************************************************/ 
#include <GL/freeglut.h>
//Projection Coords
float left = -10;
float right = 10;
float top = 10;
float bottom = -10;

//Square Coords
bool direction = true;//true=right, false=left 
float x_pos = -10.0;
float y_pos = 1.0;

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

	glBegin(GL_POLYGON);
	glVertex2f(x_pos,y_pos);
	glVertex2f(x_pos,y_pos-2);
	glVertex2f(x_pos+2,y_pos-2);
	glVertex2f(x_pos+2,y_pos);
	glEnd();

	//We change from glFlush to glutSwapBuffers()	
	glutSwapBuffers(); //This the "display" command.
}

void keyboard(unsigned char key, int x, int y){
	if(key == 'q' || key == 'Q'){
		exit(0);
	}
	return;
}

void timer(int){ //dummy integer for now
	glutPostRedisplay(); //rerun the display function
	//"recursively", call itself every 1000/60 miliseconds,
	// since common fps is 60.
	glutTimerFunc(1000/60, timer, 0);

	//Update coordinates
	if(direction){
		if(x_pos < right-2){
			x_pos+=0.1;
		}else{
			direction = false;
		}
	}
	else{
		if(x_pos > left){
			x_pos-=0.1;
		}else{
			direction = true;
		}
	}
	
	return;
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	//We change to double buffer, so that we don't encounter
	// distortions (using single buffer could put us in the
	// situation in which we render frames with objects that
	// weren't ready to be rendered yet).
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
	glutInitWindowPosition(512,512);
	glutInitWindowSize(512,512);
	glutCreateWindow("My 1st Window");

	//Callback Functions
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	//args: miliseconds after this function should be called,
	// the name of the function to which this call will be
	// directed to, integer value that we will ignore for now
	glutTimerFunc(0,timer,0);
	glutMainLoop();
	return 0;
}
