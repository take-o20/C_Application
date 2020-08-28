#include <stdio.h>
#include <stdlib.h>
// #include <GL/glut.h>
#include <GLUT/GLUT.h>

#include <math.h>
#include <string.h>

GLfloat pos0[] = { 5.0, 0.0, 0.0, 1.0 };
GLfloat pos1[] = { 5.0, 0.0, 0.0, 0.0 };
GLfloat red[] = { 1, 0.0, 0.0, 1.0 };
GLfloat green[] = { 0.0, 0.4, 0.0, 1.0 };
GLfloat blue[] = { 0.0, 0.0, 0.2, 1.0 };
GLfloat grey[] = { 0.5, 0.5, 0.5, 1.0 };

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	
	glLightfv(GL_LIGHT0, GL_POSITION, pos0);
	// glLightfv(GL_LIGHT0, GL_DIFFUSE, red);
	// glLightfv(GL_LIGHT0, GL_SPECULAR, green);
	glLightfv(GL_LIGHT0, GL_AMBIENT, blue);
    
    glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
    glMaterialfv(GL_FRONT, GL_SPECULAR, grey);
    glMaterialfv(GL_FRONT, GL_AMBIENT, grey);
    glMaterialf(GL_FRONT, GL_SHININESS, 1.0);
    
	glutSolidIcosahedron();

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
