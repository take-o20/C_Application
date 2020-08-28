#include <stdio.h>
#include <GLUT/glut.h>
#include <math.h>
#include <string.h>

GLdouble left_ear_vertex[][3]={
    {0.0, 0.0, 0.0},   //頂点0
    {0.2, 0.0, 0.0},  //頂点1
    {0.0,0.2,0.0},   //頂点2
    {0.0,0.0,0.2},   //頂点3
};
int ear_face[][3]={
  {0, 2, 1}, //面1
  {0, 3, 2}, //面2
  {1, 0, 3}, //面3
  {1, 3, 2}, //面4
};

GLdouble norm[][3] = {
    {0.0,0.0,-1.0},	//面1の法線ベクトル
    {-1.0, 0.0, 0.0},//面2,
    {0.0,-1.0, 0.0},//面3
    {1.0,1.0,1.0},//面4
};

GLdouble right_ear_vertex[][3]={
  {0.0,0.0,0.0},
  {-0.2,0.0,0.0},
  {0.0,0.2,0.0},
  {0.0,0.0,0.2},
};
int r_ear_face[][3]={
  {0, 1, 2},
  {0, 2, 3},
  {0, 3, 1},
  {3, 2, 1},
};
GLdouble r_norm[][3]={
  {0.0,0.0,-1.0},	//面1の法線ベクトル
  {1.0, 0.0, 0.0}, //面2
  {0.0, -1.0, 0.0},//面3
  {-1.0, 1.0, 1.0},
};

GLfloat pos[] = {-15.0, 10.0, 80.0,1.0 };
GLfloat blue[] = { 0.7, 0.1, 0.5, 1.0};
GLfloat red[] = {1.0, 0.1, 0.5, 1.0};
GLfloat brown[] = {2.49, 1.95, 1.5, 1.0};
GLfloat purpole[]={0.0, 0.1, 2.0, 1.0};

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.9,0.3,0.4,1);
	glLightfv(GL_LIGHT0, GL_POSITION, pos);
  	glMaterialfv(GL_FRONT, GL_SPECULAR, blue);
	glMaterialfv(GL_FRONT, GL_SPECULAR, red);
	glMaterialfv(GL_FRONT, GL_AMBIENT, brown);

  //左耳
  glPushMatrix();
  glTranslatef(0, 1.3,-0.3);
  glRotatef(-10, 0, 0, 1);
  glBegin(GL_QUADS);
  for (int j = 0; j < 4; j++) {
    glNormal3dv(norm[j]);
    for (int i = 0; i < 3; i++) {
      glVertex3dv(left_ear_vertex[ear_face[j][i]]);
    }
  }
	glEnd();
  glPopMatrix();
  // 右耳
  glPushMatrix();
  glTranslatef(-0.3, 1.3,-0.1);
  glRotatef(-15, 0,1,0);
  glBegin(GL_QUADS);
  for (int j = 0; j < 4; j++) {
    glNormal3dv(r_norm[j]);
    for (int i = 0; i < 3; i++) {
      glVertex3dv(right_ear_vertex[r_ear_face[j][i]]);
    }
  }
	glEnd();
  glPopMatrix();
  //頭
  glPushMatrix();
  glTranslatef(0, 1, 0);
  glScalef(1.0, 0.7,1.2);
	glutSolidSphere(0.5, 30, 30);
	glPopMatrix();

  // 胴体
	glPushMatrix();
	glTranslatef(0, -0.7, 0);
  glScalef(1, 2,1);
  glutSolidSphere(0.7, 30, 30);
  glPopMatrix();

  // 尻尾
  glPushMatrix();
  glTranslatef(-0.5, -2.0, 0.0);
  glScalef(10, 1,1);
  glutSolidSphere(0.1, 30, 30);
	glPopMatrix();

  //机
  glPushMatrix();
  glTranslatef(-0.5, -7.0, 0.0);

  glMaterialfv(GL_FRONT, GL_SPECULAR, purpole);
  glutSolidCube(7.0);
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
	glEnable(GL_LIGHT1);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30.0, 1, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(-7.0, 5.0, -10.0,
            0.0, 0.0, 0.0,
            0.0, 1.0, 0.0);
}

int main(int argc, char *argv[])
{
  glutInitWindowSize(500, 500);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("1W182055_有働武生");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}
