// #include<GL/glut.h>
void init2D(float r, float g, float b){
	glClearColor(0,0.0,0,0);
	// glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,500.0,0.0,500.0);
}
void display(void){
	// glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	glPointSize(13.0);
	// glBegin(GL_LINES); //draw a line
		glVertex2d(275,450);
		glVertex2d(165,25);
	glEnd();
	glFlush();
}
int main(int argc,char**argv){
	glutInit(&argc,argv);
	// glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(10,10);
	glutCreateWindow("OpenGL Line Draw : Krishna");
	init2D(0.0,0.0,0.0);
	glutDisplayFunc(display);
	glutMainLoop();
}