#include "freeglut.h"
#include <iostream>
#include "Coordinador.h"

void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void MouseButton(int button, int down, int x, int y);//cuando se haga click

Coordinador master;

int main(int argc, char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(900, 900);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");
	
	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 900.0f / 900.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer(). Por ejemplo una esfera que queremos que se mueva. Cada 25 ms se movera en la direccion que le hemos indicado
	glutKeyboardFunc(OnKeyboardDown);//Eventos de teclado. Cuando pulsamos una tecla pues se "activa" esta funcion.
	glutMouseFunc(MouseButton);
	//Inicializar los objetos

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();

	return 0;
}
void OnDraw(void)
{
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(4.0, 4.0, 19,  // posicion del ojo
		4.0, 4.0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el código de dibujo

	master.dibuja();	

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	
	master.tecla(key);
	//ultima linea, siempre que hay que ponerla:
	glutPostRedisplay();
}

void OnTimer(int value)
{

	//No borrar estas lineas, siempre tienen que ir al final:
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}
void MouseButton(int button, int down, int x, int y) {

	//finally cell coordinates

	if (button == down)
	{
		master.sacarcelda(x, y);
		master.tu_raton();
	}
	
	glutPostRedisplay();
}

