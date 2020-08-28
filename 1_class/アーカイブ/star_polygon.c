#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#include <math.h>

#define PI2 (3.1425*2)
#define N (5)

void display(void)
{
	int i;
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3d(0.0, 0.0, 0.0);

	for (i = 0; i < N; i++){
    glBegin(GL_POLYGON);
		glVertex3d(cos(PI2*i*2/N), sin(PI2*i*2/N), -1);
    glVertex3d(cos(PI2*(i+1)*2/N), sin(PI2*(i+1)*2/N), -1);
    glVertex3d(0, 0, -1);
    glEnd();
  }

	glFlush();
}

int main(int argc, char *argv[]){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA);

  glutCreateWindow("Takeo Udo");
  glutDisplayFunc(display);
  gluPerspective(100, 1, 0, 10000);
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glutMainLoop();
  return 0;
}