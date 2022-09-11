#include <GL/glut.h> 
#define _USE_MATH_DEFINES
#include <math.h>
double zoom = 5; // масштаб
double lr, ud;
/////////////////////////////////////////////////////
void ZoomKeys(int key, int x, int y) { // регулювання стрілками(ліво, право, вверх, вних) та клавішами PageUp(9 на NumLock) і PegeDown(3 на NumLock) масштаб(5)
	switch (key) {
	case GLUT_KEY_PAGE_DOWN: // задаємо наближення
		zoom = zoom + 0.1;
		break;
	case GLUT_KEY_PAGE_UP: // задаємо віддалення
		zoom = zoom - 0.1;
		break;
	case GLUT_KEY_LEFT: // задаємо зміщення вліво
		lr = lr - 0.1;
		break;
	case GLUT_KEY_RIGHT: // задаємо зміщення вправо
		lr = lr + 0.1;
		break;
	case GLUT_KEY_UP: // задаємо зміщення вверх
		ud = ud + 0.1;
		break;
	case GLUT_KEY_DOWN: // задаємо зміщення вниз
		ud = ud - 0.1;
		break;
	}
}
void Graf() {
	int a = 1;
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // фон - чорний 
	glBegin(GL_LINE_STRIP); 
	glColor3f(0.0f, 1.0f, 0.0f); // колір графіка - синій
	for (double t = -M_PI; t <= M_PI; t += 0.01) { // межі графіка
		float x = (2 * a * cos(t) * (1 - cos(t)));
		float y = (2 * a * sin(t) * (1 - cos(t)));
		glVertex2f(x / zoom + lr, y / zoom + ud);
	}
	glEnd();
}
void LineX() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // фон - чорний
	glBegin(GL_LINES); 
	glColor3f(0.0f, 0.0f, 1.0f); // колір лінії - зелений
	glVertex2f(-1, 0);
	glVertex2f(1, 0);
	glEnd();
}
void LineXY(double x) {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // фон - чорний
	glBegin(GL_LINES); 
	glColor3f(1.0f, 1.0f, 0.0f); // колір поділок - жовтий
	glVertex2f(x, 0.025);
	glVertex2f(x, -0.025);
	glEnd();
}
void LineY() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // фон - чорнийй 
	glBegin(GL_LINES); 
	glColor3f(0.0f, 0.0f, 1.0f); // колір лінії - зелений
	glVertex2f(0, -1);
	glVertex2f(0, 1);
	glEnd();
}
void LineYX(double y) {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // фон - чорний
	glBegin(GL_LINES); 
	glColor3f(1.0f, 1.0f, 0.0f); // колір поділок - жовтий
	glVertex2f(0.025, y);
	glVertex2f(-0.025, y);
	glEnd();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	Graf();
	LineX();
	for (double x = -1; x <= 1; x += 0.1) {
		LineXY(x);
	}
	LineY();
	for (double y = -1; y <= 1; y += 0.1) {
		LineYX(y);
	}
	glutSwapBuffers();
}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv); // ініціалізація GLUT
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutInitWindowPosition(50, 50); // положення вікна
	glutInitWindowSize(600, 600);// ширина та висота вікна
	glutCreateWindow("Grafik"); // вікно із заданим ім'ям
	glutSpecialFunc(ZoomKeys);
	glutDisplayFunc(display);// реєстрація функції зворотного
	glFlush();// виклик для малювання вікна
	glutMainLoop(); // вхід у цикл обробки подій GLUT
	return 0;
}