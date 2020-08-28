#include <stdio.h>
// #include <GL/glut.h>
#include <GLUT/GLUT.h>

#include <math.h>
#define PI2 (3.1415*2)

void drawPolygon(double x, double y, double z, int n)
{
	int i;
	glBegin(GL_POLYGON);
	for (i = 0; i < n; i++)
		glVertex3d(x+cos(PI2*i / n), y+sin(PI2*i / n), z);
	glEnd();

}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3d(1.0, 0.0, 0.0);
	drawPolygon(-1, 0, -1, 3);

	glColor3d(0.0, 1.0, 0.0);
	drawPolygon(1, 1, -2, 4);

	glColor3d(0.0, 0.0, 1.0);
	drawPolygon(1, -1, -3, 5);

	glFlush();
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);

	glutCreateWindow("Hello, world!");
	glutDisplayFunc(display);
	gluPerspective(100, 5, 0, 10000);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutMainLoop();
	return 0;
}
