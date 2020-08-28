#include <stdio.h>
#include <stdlib.h>
// #include <GL/glut.h>
#include <GLUT/glut.h>
#include <math.h>
#include <string.h>

GLfloat pos0[] = { 0.0, 0.0, -0.1, 1.0 };
GLfloat pos1[] = { 0.0, 0.0, -0.1, 0.0 };

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	
	// glLightfv(GL_LIGHT0, GL_POSITION, pos0);
	glLightfv(GL_LIGHT0, GL_POSITION, pos1);

	glPushMatrix();
	glTranslatef(1,0,0);
	glutSolidSphere(0.5, 30, 30);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1, 0, 0);
	glutSolidSphere(0.5, 30, 30);
	glPopMatrix();

	glPopMatrix();
	glutSwapBuffers();
}

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30.0, 1, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, -5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
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
