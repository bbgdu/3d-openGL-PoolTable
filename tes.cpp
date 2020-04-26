//Snooker table
#include<iostream>
#include<GL/glut.h>
using namespace std;
int semicircle_points[]={24,23,23,23,23,23,23,22,22,22,21,21,20,20,19,18,17,16,15,14,13,11,9,6,-24,-23,-23,-23,-23,-23,-23,-22,-22,-22,-21,-21,-20,-20,-19,-18,-17,-16,-15,-14,-13,-11,-9,-6};
void displayMe(void)
{
	//Board
	glColor3f(0,1,0);
	glBegin(GL_POLYGON);
	glVertex3f(100,100,0);
	glVertex3f(-100,100,0);
	glVertex3f(-100,-100,0);
	glVertex3f(100,-100,0);
	glEnd();

	//Lines
	glColor3f(1,1,1);
	glBegin(GL_LINES);
	glVertex3f(-66,-100,0);
	glVertex3f(-66,100,0);
	glEnd();

	glColor3f(1,1,1);
	glBegin(GL_LINES);
	glVertex3f(66,100,0);
	glVertex3f(66,-100,0);
	glEnd();


	//SemiCircle
	glColor3f(1,1,1);
	for (int i=0 ; i<23; i++)
	{	
		glBegin(GL_LINES);
		glVertex3f(i+66,semicircle_points[i],0);
		glVertex3f(i+67,semicircle_points[i+1],0);
		glEnd();

		glBegin(GL_LINES);
		glVertex3f(i+66,semicircle_points[i+24],0);
		glVertex3f(i+67,semicircle_points[i+25],0);
		glEnd();
	}

	//TODO
	//Holes
		//Camera and lighting
	//3dBorder
	//Balls
	//Potential animation

	glFlush();
}

void displayAll(void)
{
	displayMe();
}
void init(void){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(200,-200,200,-200,1,-1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(1080, 680);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("ProjectCS352");
	init();
	glutDisplayFunc(displayMe);
	glutMainLoop();
	return 0;
}