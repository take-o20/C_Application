#include <stdio.h>
// #include <GL/glut.h>
#include <GLUT/GLUT.h>

#include <math.h>
#define PI2 (3.1415*2)
#define N (5)

void display(void)
{
	int i;
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3d(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (i = 0; i < N;i++)
		glVertex3d(cos(PI2*i/N), sin(PI2*i/N), -1);
	glEnd();

	glFlush();
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);

	glutCreateWindow("Hello, world!");
	glutDisplayFunc(display);
	gluPerspective(100, 1, 0, 1000);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutMainLoop();
	return 0;
}
//gcc -framework GLUT -framework OpenGL code2-1.c 
