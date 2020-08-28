#include <stdio.h>
#include <stdlib.h>
// #include <GL/glut.h>
#include <GLUT/GLUT.h>
#include <math.h>
#include <string.h>

void CS()
{
	glPushMatrix();
	glutSolidCube(1);
	glTranslatef(0, 1, 0);
	glutSolidSphere(0.7, 30, 30);
	glPopMatrix();
}
void display(void)
{
	int i;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	
	CS();
	glTranslatef(1, 0, 0);
	CS();

	for (i = 0; i<20; i++)
	{
		glPushMatrix();
		glTranslatef(rand() % 5, 0, rand() % 5);
		glScalef(0.5, 0.5, 0.5);
		CS();
		glPopMatrix();
	}

	glPopMatrix();
	glutSwapBuffers();
}

void init(void)
{
	srand(0);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	glCullFace(GL_BACK);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, 1, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("C Dev");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}
