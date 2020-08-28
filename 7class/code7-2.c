#include <stdio.h>
#include <stdlib.h>
#include <GLUt/glut.h>
#include <math.h>
#define PI (3.14159)

GLfloat pos0[] = {5.0, 0.0, 0.0, 1.0};
GLfloat pos1[] = {0.0, 0.0, 5.0, 1.0};
enum COLOR
{
	WHITE,
	RED,
	GREEN,
	BLUE,
	YELLOW,
	MAGENTA,
	CYAN,
	GRAY,
	BLACK
};
GLfloat color[][4] = {
		{1.0, 1.0, 1.0, 1.0},
		{1.0, 0.0, 0.0, 1.0},
		{0.0, 1.0, 0.0, 1.0},
		{0.0, 0.0, 1.0, 1.0},
		{1.0, 1.0, 0.0, 1.0},
		{1.0, 0.0, 1.0, 1.0},
		{0.0, 1.0, 1.0, 1.0},
		{0.7, 0.7, 0.7, 1.0},
		{0.0, 0.0, 0.0, 1.0}}; //�F�𑝂₷�ꍇ�͂����ɒǉ�

int x = 0;
int y = 0;
int z = 0;
int jumping = 0;
void calcNormal(GLdouble v0[3], GLdouble v1[3], GLdouble v2[3], GLdouble n[3])
{
	GLdouble v2v[2][3];
	GLdouble vt[3];
	double abs;
	int i;
	for (i = 0; i < 3; i++)
	{
		v2v[0][i] = v1[i] - v0[i];
		v2v[1][i] = v2[i] - v0[i];
	}
	vt[0] = v2v[0][1] * v2v[1][2] - v2v[0][2] * v2v[1][1];
	vt[1] = v2v[0][2] * v2v[1][0] - v2v[0][0] * v2v[1][2];
	vt[2] = v2v[0][0] * v2v[1][1] - v2v[0][1] * v2v[1][0];
	abs = sqrt(vt[0] * vt[0] + vt[1] * vt[1] + vt[2] * vt[2]);
	for (i = 0; i < 3; i++)
		n[i] = vt[i] / abs;
}

void drawGround()
{
	int N = 30;
	double L = 0.5;
	int i, j;
	GLdouble normal[3] = {0.0, 0.0, 1.0};

	glPushMatrix();

	glNormal3dv(normal);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, color[GRAY]); //�D�F
	glMaterialfv(GL_FRONT, GL_AMBIENT, color[BLACK]);
	glMaterialfv(GL_FRONT, GL_SPECULAR, color[WHITE]);
	glMaterialf(GL_FRONT, GL_SHININESS, 100.0);
	glBegin(GL_QUADS);
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
		{
			GLdouble v[5][3];
			if (!((i ^ j) & 1))
				continue;
			v[0][0] = (j + 0 - (N >> 1)) * L;
			v[0][1] = (i + 0 - (N >> 1)) * L;
			v[0][2] = 0;
			v[1][0] = (j + 1 - (N >> 1)) * L;
			v[1][1] = (i + 0 - (N >> 1)) * L;
			v[1][2] = 0;
			v[2][0] = (j + 1 - (N >> 1)) * L;
			v[2][1] = (i + 1 - (N >> 1)) * L;
			v[2][2] = 0;
			v[3][0] = (j + 0 - (N >> 1)) * L;
			v[3][1] = (i + 1 - (N >> 1)) * L;
			v[3][2] = 0;
			glVertex3dv(v[0]);
			glVertex3dv(v[1]);
			glVertex3dv(v[2]);
			glVertex3dv(v[3]);
		}
	glEnd();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, color[BLACK]); //��
	glMaterialfv(GL_FRONT, GL_AMBIENT, color[BLACK]);
	glMaterialfv(GL_FRONT, GL_SPECULAR, color[WHITE]);
	glMaterialf(GL_FRONT, GL_SHININESS, 100.0);
	glBegin(GL_QUADS);
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
		{
			GLdouble v[5][3];
			if ((i ^ j) & 1)
				continue;
			v[0][0] = (j + 0 - (N >> 1)) * L;
			v[0][1] = (i + 0 - (N >> 1)) * L;
			v[0][2] = 0;
			v[1][0] = (j + 1 - (N >> 1)) * L;
			v[1][1] = (i + 0 - (N >> 1)) * L;
			v[1][2] = 0;
			v[2][0] = (j + 1 - (N >> 1)) * L;
			v[2][1] = (i + 1 - (N >> 1)) * L;
			v[2][2] = 0;
			v[3][0] = (j + 0 - (N >> 1)) * L;
			v[3][1] = (i + 1 - (N >> 1)) * L;
			v[3][2] = 0;
			glVertex3dv(v[0]);
			glVertex3dv(v[1]);
			glVertex3dv(v[2]);
			glVertex3dv(v[3]);
		}
	glEnd();

	glPopMatrix();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();

	drawGround();

	glTranslatef(0.1 * x, 0.1 * y, 0.1 * z);
	glTranslatef(0.0, 0.0, 0.5);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, color[GREEN]);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color[BLACK]);
	glMaterialfv(GL_FRONT, GL_SPECULAR, color[WHITE]);
	glMaterialf(GL_FRONT, GL_SHININESS, 50.0);
	glutSolidCube(1);

	glPopMatrix();
	glutSwapBuffers();
}
void jump(int value)
{
	double v = 3;		 //�W�����v�̑��x
	double g = -0.2; //����������x
	z = v * value + g * value * value / 2;
	if (z < 0)
	{
		z = 0; //������ύX
		jumping = 0;
	}
	else
	{
		glutTimerFunc(50, jump, value + 1); //���̏�����o�^
	}
}

void myKeyboardFunc(unsigned char key, int x, int y)
{
	switch (key)
	{
	case ' ':
		if (jumping == 0)
		{
			jumping = 1;
			jump(0); //������ύX
			break;
		}
	}
}

void idle(void)
{
	glutPostRedisplay();
}
void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glutKeyboardFunc(myKeyboardFunc);

	glutIdleFunc(idle);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30.0, 1, .1, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, -10.0, 2.0, 0.0, 0.0, 1.5, 0.0, 0.0, 1.0);
	glLightfv(GL_LIGHT1, GL_POSITION, pos1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, color[WHITE]);
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
