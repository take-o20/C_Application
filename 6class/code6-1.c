#include <stdio.h>
#include <stdlib.h>
#include <GLUT/GLUT.h>
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
double z = 0;
int colorOffset = 0;

GLfloat sphereList[8][4] = {{0.0, 0.0, 2.0, 1.0}, {0.0, 2.0, 1.5, 0.3}}; //x, y, z, r
int listIndex = 2;

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
	int i, j;
	glPushMatrix();
	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
		{
			GLdouble v[5][3];
			v[0][0] = (j + 0) * 0.5 - 2.5;
			v[0][1] = (i + 0) * 0.5 - 2.5;
			v[0][2] = 0;
			v[1][0] = (j + 1) * 0.5 - 2.5;
			v[1][1] = (i + 0) * 0.5 - 2.5;
			v[1][2] = 0;
			v[2][0] = (j + 1) * 0.5 - 2.5;
			v[2][1] = (i + 1) * 0.5 - 2.5;
			v[2][2] = 0;
			v[3][0] = (j + 0) * 0.5 - 2.5;
			v[3][1] = (i + 1) * 0.5 - 2.5;
			v[3][2] = 0;
			if ((i ^ j) & 1)
			{
				glMaterialfv(GL_FRONT, GL_DIFFUSE, color[GRAY]);
				glMaterialfv(GL_FRONT, GL_AMBIENT, color[BLACK]);
				glMaterialfv(GL_FRONT, GL_SPECULAR, color[WHITE]);
				glMaterialf(GL_FRONT, GL_SHININESS, 100.0);
			}
			else
			{
				glMaterialfv(GL_FRONT, GL_DIFFUSE, color[BLACK]);
				glMaterialfv(GL_FRONT, GL_AMBIENT, color[BLACK]);
				glMaterialfv(GL_FRONT, GL_SPECULAR, color[WHITE]);
				glMaterialf(GL_FRONT, GL_SHININESS, 100.0);
			}
			calcNormal(v[0], v[1], v[2], v[4]);
			glNormal3dv(v[4]);
			glBegin(GL_QUADS);
			glVertex3dv(v[0]);
			glVertex3dv(v[1]);
			glVertex3dv(v[2]);
			glVertex3dv(v[3]);
			glEnd();
		}
	glPopMatrix();
}

void drawSphere()
{
	int i;
	for (i = 0; i < listIndex; i++)
	{
		glPushMatrix();
		glMaterialfv(GL_FRONT, GL_DIFFUSE, color[RED + (i + colorOffset) % 8]); //�����ŐF��ݒ肵�Ă���
		glMaterialfv(GL_FRONT, GL_AMBIENT, color[BLACK]);
		glMaterialfv(GL_FRONT, GL_SPECULAR, color[WHITE]);
		glMaterialf(GL_FRONT, GL_SHININESS, 50.0);
		glTranslatef(sphereList[i][0], sphereList[i][1], sphereList[i][2]);
		glutSolidSphere(sphereList[i][3], 30, 30);
		glPopMatrix();
	}
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();

	gluLookAt(0.0, -10.0, 2.0, 0.0, 0.0, 1.5, 0.0, 0.0, 1.0); //������ύX

	glLightfv(GL_LIGHT1, GL_POSITION, pos1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, color[WHITE]);

	drawGround();

	//������ύX
	glTranslatef(0.0, 0.0, z);
	//
	glRotatef(r, 0, 0, 1);

	drawSphere(); //����\��

	glPopMatrix();
	glutSwapBuffers();
}
void myKeyboardFunc(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'a':
		printf("a\n");
		break;
	case '1':
		printf("1\n");
		break;
	default:
		break;
	}
}
void mySpcialFunc(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		z += 0.1;
		break;
	case GLUT_KEY_LEFT:
		r++;
		if (r > 360)
			r -= 360;
		break;
	case GLUT_KEY_RIGHT:
		r--;
		if (r < 0)
			r += 360;
		break;
	case GLUT_KEY_DOWN:
		z -= 0.1;
		break;
	default:
		break;
	}
}

void idle(void) //����ȍ~�̍u�`�Ő���
{
	glutPostRedisplay();
}

void init(void)
{
	srand(0);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glutKeyboardFunc(myKeyboardFunc);
	glutSpecialFunc(mySpcialFunc);

	glutIdleFunc(idle);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30.0, 1, .1, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
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
//gcc -framework GLUT -framework OpenGL code6-1.c