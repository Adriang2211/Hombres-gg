#include "freeglut.h"
#include <iostream>
#include "ETSIDI.h"
#include "Tablero.h"
#include "Piezas.h"

void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	


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
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer(). Por ejemplo una esfera que queremos que se mueva. Cada 25 ms se movera en la direccion que le hemos indicado
	glutKeyboardFunc(OnKeyboardDown);//Eventos de teclado. Cuando pulsamos una tecla pues se "activa" esta funcion.

	//Inicializar los objetos
	Tablero tablero1;
	tablero1.inicializa();
	tablero1.actualizarCasillasOcupadas();
	std::cout << tablero1;


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

	gluLookAt(0, 00, 30,  // posicion del ojo
		0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el código de dibujo
	
	
	
	

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	

	//ultima linea, siempre que hay que ponerla:
	glutPostRedisplay();
}

void OnTimer(int value)
{



	//No borrar estas lineas, siempre tienen que ir al final:
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}

