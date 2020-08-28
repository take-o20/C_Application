#include <stdio.h>
//#include <GL/glut.h>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>

#define W 22
#define H 11
char helloworld[H][W] = {
		{ "* * *** *   *   ***  " },
		{ "* * *   *   *   * *  " },
		{ "*** *** *   *   * *  " },
		{ "* * *   *   *   * *  " },
		{ "* * *** *** *** ***  " },
		{ "                     " },
		{ "* * * *** **  *   ** " },
		{ "* * * * * * * *   * *" },
		{ "* * * * * **  *   * *" },
		{ " * *  * * * * *   * *" },
		{ " * *  *** * * *** ** " } };

void display(void)
{
	int i,j;
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3d(0.0, 0.0, 0.0);
	for (i = 0; i < H; i++)
		for (j = 0; j < W-1; j++)
		{
		if (helloworld[H-i-1][j] == ' ')continue;
		glBegin(GL_POLYGON);
		glVertex3d(j / (double)W - 0.5, i / (double)H - 0.5, -1);
		glVertex3d((j + 1) / (double)W - 0.5, i / (double)H - 0.5, -1);
		glVertex3d((j + 1) / (double)W - 0.5, (i + 1) / (double)H - 0.5, -1);
		glVertex3d(j / (double)W - 0.5, (i + 1) / (double)H - 0.5, -1);
		glEnd();
		}
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
