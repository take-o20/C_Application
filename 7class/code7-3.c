#include <stdio.h>
#include <stdlib.h>
#include <GLUT/glut.h>
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
int r = 0;
int x = 0;
int y = 0;
int z = 0;
int ij = 0;
int mySpecialValue = 0;
int right = 0;
int left = 0;
int up = 0;
int down = 0;
double rotation_base = 0;
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
double ffff = 1.0;
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();

	drawGround();

	glTranslatef(0.1 * x, 0.1 * y, 0.1 * z);
	//glTranslatef(  , 0.0,  );//������ύX
	// glTranslatef(rotation_base, 0.0, 0.0);
	glRotatef(r, 0.0, ffff, 0.0); //������ύX

	// glTranslatef(-1 * rotation_base, 0.0, 0.0);
	glTranslatef(0.0, 0.0, 0.5); //������ύX

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
		z = 0;
		ij = 0;
	}
	else
	{
		glutTimerFunc(50, jump, value + 1); //���̏�����o�^
	}
}

void myTimerFunc(int value)
{
	if (mySpecialValue == 1 << 0)
		y++; //������ύX
	if (mySpecialValue == 1 << 1)
		x--; //������ύX
	if (mySpecialValue == 1 << 2)
		// x++; //������ύX
		x += 1;
	if (mySpecialValue == 1 << 3)
		y--; //������ύX
	if (up && left)
	{
		x--;
		y++;
	}
	if (down && left)
	{
		x--;
		y--;
	}
	if (up & right)
	{
		x++;
		y++;
	}
	if (down & right)
	{
		x++;
		y--;
	}
	if (mySpecialValue)
		glutTimerFunc(50, myTimerFunc, 0);
}

void myKeyboardFunc(unsigned char key, int x, int y)
{
	if (!mySpecialValue)
		glutTimerFunc(50, myTimerFunc, 0);
	switch (key)
	{
	case 'r':
		rotation_base = 1.5;
		ffff = 1.5;
		if (r != 0 && r % 90 == 0)
		{
			// right = 1;
			// mySpecialValue |= 1 << 2;
			// r = 0;
			ffff += 1.5;
			// rotation_base -= 0.5;
			r += 10;
		}
		else
			r += 10.0;
		break;
	case 'l':
		// rotation_base = -0.5;
		if (r < 0 && r % 90 == 0)
		{
			r = 0;
			rotation_base -= 0.5;
		}
		else
			r -= 10.0;
		break;
	case ' ':
		if (ij == 0)
		{
			jump(0);
			ij = 1;
		}
		break;
	}
}

void mySpcialFunc(int key, int x, int y)
{
	if (!mySpecialValue)
		glutTimerFunc(50, myTimerFunc, 0);
	switch (key)
	{
	case GLUT_KEY_UP:
		up = 1;
		mySpecialValue |= 1 << 0; //mySpecialValue��1bit�ڂ�1�ɂ���
		break;
	case GLUT_KEY_LEFT:
		left = 1;
		mySpecialValue |= 1 << 1; //mySpecialValue��2bit�ڂ�1�ɂ���
		break;
	case GLUT_KEY_RIGHT:
		right = 1;
		mySpecialValue |= 1 << 2; //mySpecialValue��3bit�ڂ�1�ɂ���
		break;
	case GLUT_KEY_DOWN:
		down = 1;
		mySpecialValue |= 1 << 3; //mySpecialValue��4bit�ڂ�1�ɂ���
		break;
	default:
		break;
	}
}
void mySpcialUpFunc(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		up = 0;
		mySpecialValue &= ~(1 << 0); //mySpecialValue��1bit�ڂ�0�ɂ���
		break;
	case GLUT_KEY_LEFT:
		left = 0;
		mySpecialValue &= ~(1 << 1); //mySpecialValue��2bit�ڂ�0�ɂ���
		break;
	case GLUT_KEY_RIGHT:
		right = 0;
		mySpecialValue &= ~(1 << 2); //mySpecialValue��3bit�ڂ�0�ɂ���
		break;
	case GLUT_KEY_DOWN:
		down = 0;
		mySpecialValue &= ~(1 << 3); //mySpecialValue��4bit�ڂ�0�ɂ���
		break;
	case 'r':
		right = 0;
		mySpecialValue &= ~(1 << 2); //mySpecialValue��3bit�ڂ�0�ɂ���
		break;
	default:
		break;
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
	glutSpecialFunc(mySpcialFunc);
	glutSpecialUpFunc(mySpcialUpFunc);

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
