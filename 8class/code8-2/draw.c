#include <stdio.h>
#include <stdlib.h>
#include <GLUT/glut.h>
#include <math.h>
#include "head.h"

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
	GLdouble normal[3] = {0.0, 0.0, 1.0};

	glPushMatrix();

	glNormal3dv(normal);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, color[YELLOW]);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color[BLACK]);
	glMaterialfv(GL_FRONT, GL_SPECULAR, color[WHITE]);
	glMaterialf(GL_FRONT, GL_SHININESS, 100.0);
	glBegin(GL_QUADS);
	glVertex3d(-0.5 * L, -0.5 * L, 0.0); //�X�^�[�g
	glVertex3d((XG - 0.5) * L, -0.5 * L, 0.0);
	glVertex3d((XG - 0.5) * L, 0.5 * L, 0.0);
	glVertex3d(-0.5 * L, 0.5 * L, 0.0);

	glVertex3d(-0.5 * L, (YG - 0.5) * L, 0.0); //�S�[��
	glVertex3d((XG - 0.5) * L, (YG - 0.5) * L, 0.0);
	glVertex3d((XG - 0.5) * L, (YG + 0.5) * L, 0.0);
	glVertex3d(-0.5 * L, (YG + 0.5) * L, 0.0);
	glEnd();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, color[GRAY]); //�D�F
	glMaterialfv(GL_FRONT, GL_AMBIENT, color[BLACK]);
	glMaterialfv(GL_FRONT, GL_SPECULAR, color[WHITE]);
	glMaterialf(GL_FRONT, GL_SHININESS, 100.0);
	glBegin(GL_QUADS);
	for (i = 1; i < YG; i++)
		for (j = 0; j < XG; j++)
		{
			GLdouble v[4][3];
			if (!((i ^ j) & 1))
				continue;
			v[0][0] = (j + 0 - 0.5) * L;
			v[0][1] = (i + 0 - 0.5) * L;
			v[0][2] = 0;
			v[1][0] = (j + 1 - 0.5) * L;
			v[1][1] = (i + 0 - 0.5) * L;
			v[1][2] = 0;
			v[2][0] = (j + 1 - 0.5) * L;
			v[2][1] = (i + 1 - 0.5) * L;
			v[2][2] = 0;
			v[3][0] = (j + 0 - 0.5) * L;
			v[3][1] = (i + 1 - 0.5) * L;
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
	for (i = 0; i < YG; i++)
		for (j = 0; j < XG; j++)
		{
			GLdouble v[4][3];
			if ((i ^ j) & 1)
				continue;
			v[0][0] = (j + 0 - 0.5) * L;
			v[0][1] = (i + 0 - 0.5) * L;
			v[0][2] = 0;
			v[1][0] = (j + 1 - 0.5) * L;
			v[1][1] = (i + 0 - 0.5) * L;
			v[1][2] = 0;
			v[2][0] = (j + 1 - 0.5) * L;
			v[2][1] = (i + 1 - 0.5) * L;
			v[2][2] = 0;
			v[3][0] = (j + 0 - 0.5) * L;
			v[3][1] = (i + 1 - 0.5) * L;
			v[3][2] = 0;
			glVertex3dv(v[0]);
			glVertex3dv(v[1]);
			glVertex3dv(v[2]);
			glVertex3dv(v[3]);
		}
	glEnd();

	glPopMatrix();
}

void drawJiki(void)
{
	glPushMatrix();

	glTranslatef(x, y, z);
	glTranslatef(0.0, 0.0, 0.5);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, color[GREEN]);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color[BLACK]);
	glMaterialfv(GL_FRONT, GL_SPECULAR, color[WHITE]);
	glMaterialf(GL_FRONT, GL_SHININESS, 50.0);

	glutSolidCube(1);
	glPopMatrix();
}
void drawTeki(void)
{
	int i;
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color[RED]);
	glMaterialfv(GL_FRONT, GL_AMBIENT, color[BLACK]);
	glMaterialfv(GL_FRONT, GL_SPECULAR, color[WHITE]);
	glMaterialf(GL_FRONT, GL_SHININESS, 100.0);

	for (i = 0; i < tekiIndex; i++)
	{
		glPushMatrix();
		glTranslatef(tekiList[i][0], tekiList[i][1], tekiList[i][2]);
		glutSolidCone(0.5, 1, 30, 30);
		glPopMatrix();
	}
	glPopMatrix();
}
