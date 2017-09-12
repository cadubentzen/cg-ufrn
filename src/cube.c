#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

void init(void) 
{
   glClearColor (0.0, 0.5, 0.5, 1.0);
   glShadeModel (GL_FLAT);
}

float theta = 0.0;
float phi = 0.0;

void display(void)
{
   //printf("display event\n");
   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f (1.0, 1.0, 1.0);
   glLoadIdentity ();             /* clear the matrix */
           /* viewing transformation  */
   //glTranslatef(0.0, 0.0, -5.0);
   float z = 5*cos(M_PI*theta/180.0)*cos(M_PI*phi/180.0);
   float x = 5*sin(M_PI*theta/180.0)*cos(M_PI*phi/180.0);
   float y = 5*sin(M_PI*phi/180.0);
   gluLookAt (x, y, z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
   glScalef (1.0, 2.0, 1.0);      /* modeling transformation */ 
   glutWireCube (1.0);
   glFlush ();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(60.0, 1.0, 1.5, 20.0);
   //glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
   glMatrixMode (GL_MODELVIEW);
}

void mouse(int button, int state, int x, int y) 
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
		 theta += 5.0;
		 //if (theta >= 90.0) theta = 90.0;
         break;
      case GLUT_RIGHT_BUTTON:
		 theta -= 5.0;
		 //if (theta <= 0.0) theta = 0.0;
         break;
	  case GLUT_MIDDLE_BUTTON:
         break;
   }

   glutPostRedisplay();
}

void special(int key, int x, int y) {
	//printf("key = %c\n", key);
	switch(key) {
		case GLUT_KEY_LEFT:
			theta += 1.0;
			break;
		case GLUT_KEY_RIGHT:
			theta -= 1.0;
			break;
		case GLUT_KEY_UP:
			phi += 1.0;
			break;
		case GLUT_KEY_DOWN:
			phi -= 1.0;
			break;
	}

	glutPostRedisplay();
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutSpecialFunc(special);
   glutMainLoop();
   return 0;
}


