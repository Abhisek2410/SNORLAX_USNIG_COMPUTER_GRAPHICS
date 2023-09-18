#include <stdio.h>
#include <glut.h>
#include<math.h>

const GLfloat light_position[] = { 1.0, 1.0, 1.0, 10 };

const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };

static int head = 0, a = 0, s = 0, rear = -90, lear = -90, body = 0, lleg = -90, rleg = -90, ball = 0, stage = 0;
GLfloat ballRadius = 0.1f;
static int slices = 50;
static int stacks = 50;

float angle = 0.0f;
float handAngle[2] = { 0.0f, 0.0f };
float legAngle[2] = { 0.0f, 0.0f };
float baseAngle[2] = { 0.0f, 0.0f };


int refreshMills = 30;
void mainpart() {
    glColor3d(0.5, 0.85, 0.9);  // head
    glPushMatrix();
    glTranslated(0, 0.25, 1);
    glRotated((GLfloat)head, 0, 1, 0);
    glutWireSphere(0.2, 140, 150);
    glPopMatrix();

    glPushMatrix();         //ear
    glTranslated(0.11, 0.30, 1);
    glRotated((GLfloat)rear, 1, 0, 0);
    glutSolidCone(0.08, 0.2, 116, 116);
    glPopMatrix();

    glPushMatrix();         //ear
    glTranslated(-0.11, 0.30, 1);
    glRotated((GLfloat)lear, 1, 0, 0);
    glutWireCone(0.08, 0.2, 116, 116);
    glPopMatrix();

    glColor3d(0.0f, 0.0f, 0.0f);  //eyes
    glPushMatrix();
    glTranslated(0.07, 0.3, 0.33);
    glRotated(0, 0, 0, 0);
    glScalef(0.5, 0.1, 0.1);
    glutSolidCube(0.1);
    glPopMatrix();

    glPushMatrix();      //eyes
    glTranslated(-0.07, 0.3, 0.33);
    glRotated(0, 0, 0, 0);
    glScalef(0.5, 0.1, 0.1);
    glutSolidCube(0.1);
    glPopMatrix();

    glPushMatrix();      //mouth
    glTranslated(0.03, 0.25, 0.35);
    glRotated(10, 0, 0, 1);
    glScalef(0.6, 0.1, 0.1);
    glutSolidCube(0.1);
    glPopMatrix();

    glPushMatrix();      //mouth
    glTranslated(-0.03, 0.25, 0.35);
    glRotated(-10, 0, 0, 1);
    glScalef(0.6, 0.1, 0.1);
    glutSolidCube(0.1);
    glPopMatrix();

    glColor3d(1.0, 1.0, 1.0);
    glPushMatrix();   // teeth
    glTranslated(-0.045, 0.255, 0.34);
    glRotated(-90, 1, 0, 0);
    glutSolidCone(0.01, 0.03, 16, 16);
    glPopMatrix();

    glPushMatrix();   // teeth
    glTranslated(0.045, 0.255, 0.34);
    glRotated(-90, 1, 0, 0);
    glutSolidCone(0.01, 0.03, 16, 16);
    glPopMatrix();

	
	

    glColor3d(0.5, 0.85, 0.88);  // body
    glTranslatef(0, -0.05, 1.1);
    glPushMatrix();
    glRotated((GLfloat)body, 1, 0, 0);
    glutSolidSphere(0.3, 40, 50);
    glPopMatrix();

}

void hand() {
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t * 90.0;
    const double s = t * 90.0;

   glColor3d(0.5, 0.85, 0.9);
    glPushMatrix();         //hand
    glTranslated(0.2, 0.12, 1);
    glRotated(100, 0, 1, 0);
    glRotated((GLfloat)a, 0, 0, 1);
    glutSolidCone(0.1, 0.4, 50, 50);
    glPopMatrix();

    glPushMatrix();         //hand
    glTranslated(-0.2, 0.12, 1);
    glRotated(100, 0, -1, 0);
    glRotated((GLfloat)s, 0, 0, 1);
    glutSolidCone(0.1, 0.4, 50, 50);
    glPopMatrix();
}


void leg() {
    glColor3d(1.0, 0.7, 0.3);
    glPushMatrix();         //leg
    glTranslated(0.15, -0.3, 0.15);
    glRotated((GLfloat)rleg, 0.5, 0, 0);
    glutSolidTorus(0.026, 0.08, 16, 16);
    glPopMatrix();

    glPushMatrix();         //leg
    glTranslated(-0.15, -0.3, 0.15);
    glRotated((GLfloat)lleg, 0.5, 0, 0);
    glutSolidTorus(0.026, 0.08, 16, 16);
    glPopMatrix();

    glColor3d(0.4, 0.3, 0.1);
    glPushMatrix();         //leg
    glTranslated(0.15, -0.3, 0.15);
    glRotated((GLfloat)rleg, 0.5, 0, 0);
    glutSolidTorus(0.026, 0.03, 16, 16);
    glPopMatrix();

    glPushMatrix();         //leg
    glTranslated(-0.15, -0.3, 0.15);
    glRotated((GLfloat)lleg, 0.5, 0, 0);
    glutSolidTorus(0.026, 0.03, 16, 16);
    glPopMatrix();
}




	void pokeball() {
   
		
    




    glColor3d(1.0, 0, 0);  // pokeball(red)
    glPushMatrix();
    glTranslated(0, -0.7, 1);
    glRotated((GLfloat)ball, 0, 0, 0);
    glutSolidSphere(0.1, slices, stacks);
    glPopMatrix();

    glColor3d(0.0, 0.0, 0.0);  // pokeball(black)
    glPushMatrix();
    glTranslated(0, -0.7, 1.04);
    glRotated(0, 0, 0, 0);
    glutSolidSphere(0.07, slices, stacks);
    glPopMatrix();

    glColor3d(1.0, 1.0, 1.0);  // pokeball(small white)
    glPushMatrix();
    glTranslated(0, -0.7, 1.09);
    glRotated(0, 0, 0, 0);
    glutSolidSphere(0.03, slices, stacks);
    glPopMatrix();

    glColor3d(1.0, 1.0, 1.0);  // pokeball(big white)
    glPushMatrix();
    glTranslated(0, -0.71, 1);
    glRotated(0, 0, 0, 0);
    glutSolidSphere(0.1, slices, stacks);
    glPopMatrix();

    glColor3d(0.0, 0.0, 0.0);  // pokeball TORUS
    glPushMatrix();
    glTranslated(0, -0.7, 1);
    glRotated(90, 1, 0, 0);
    glutSolidTorus(0.01, 0.1, slices, stacks);
    glPopMatrix();


	glColor3d(1.0, 1.0, 1.0);  // pokeball(big white)
    glPushMatrix();
    glTranslated(0.52,0.15,1);
    glRotated(0, 0, 0, 0);
    glutSolidSphere(0.1, slices, stacks);
    glPopMatrix();


//	
const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t * 90.0;
	
    glColor3d(1.0, 0.0, 0.0); 
	// pokeball TORUS
    glPushMatrix();
	glTranslated(0.52,0.15,1);
	 glRotated(1, 0, 1, 0);
    glRotated((GLfloat)a, 1, 1, 1);
    glutSolidTorus(0.01, 0.1, slices, stacks);
    glPopMatrix();

  
}



void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    pokeball();
    leg();
    hand();
    mainpart();

    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-1.5, 1.5, -1.5 * (GLfloat)h / (GLfloat)w,
            1.5* (GLfloat)h / (GLfloat)w, -10.0, 10.0);
    else
        glOrtho(-1.5 * (GLfloat)w / (GLfloat)h, 1.5 * (GLfloat)
            w / (GLfloat)h, -1.5, 1.5, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {

    case 27:
    case 'q':
        exit(0);
        break;

         case '-':
             head++;
             glutPostRedisplay();
             break;

         case 'w':
             lleg++;
             rleg--;
             break;

         case 'W':
             lleg--;
             rleg++;
             break;

         case 'E':
             a--;
             s++;
             break;

         case 'e':
             s--;
             a++;
             break;

         case '+':
             if (slices>3 && stacks>3)
             {
                 slices--;
                 stacks--;
             }
             break;
    default:
        break;
    }
}

void TimerFunc(int value) {
    glutPostRedisplay();
    glutTimerFunc(50, TimerFunc, 1);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, TimerFunc, 0);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glutMainLoop();
    return 0;
}
