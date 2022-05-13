#include "freeglut.h"
#include <iostream>
#include "ETSIDI.h"
//#include "Tablero.h"
#include "Piezas.h"
#include <stdio.h>
using namespace std;


#include "Coordinador.h"

void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void MouseButton(int button, int down, int x, int y);

void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
int xcell_sel, ycell_sel;			//cell selected with mouse

	//mouse+special-keys combination state events 
bool controlKey;
bool shiftKey;
bool leftButton;
bool rightButton;
bool midButton;
Tablero tablero1; //Pruebas - posiciÛn inicial de la partida
Tablero tablero2; //Pruebas - posiciÛn 2


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


	gluLookAt(4, 4, 12,  // posicion del ojo
		4.0,4, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el c√≥digo de dibujo


	//tablero1.dibuja(); //Prueba


	
	master.dibuja();

	tablero2.dibuja(); //Prueba, no se elimina porque todav√≠a no est√° 100% operativo el coordinador.
	

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{

	master.tecla(key);

	//ultima linea, siempre que hay que ponerla:
	glutPostRedisplay();
}


void sacarcelda(int x, int y, int& cell_x, int& cell_y) {
	//world coordinates to cell
	cell_x = (int)(((x-36) / 90)+1);
	cell_y = (int)(((600-y) / 90)+1);
}

void MouseButton(int button, int down, int x, int y) {
	/////////////////////////
	// sets state of mouse control buttons + special keys

	/////////
	//computes cell coordinates from mouse coordinates
	cout << "hola";
	GLint viewport[4];
	GLdouble modelview[16];
	GLdouble projection[16];
	GLfloat winX, winY, winZ;
	GLdouble posX, posY, posZ;

	glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
	glGetDoublev(GL_PROJECTION_MATRIX, projection);
	glGetIntegerv(GL_VIEWPORT, viewport);

	winX = (float)x;
	winY = (float)viewport[3] - (float)y;
	glReadPixels(x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);
	gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);

	//finally cell coordinates
	sacarcelda(x, y, xcell_sel, ycell_sel);

	///////////////////////////	
	

	if (button == GLUT_LEFT_BUTTON)
		leftButton = down;
	else if (button == GLUT_RIGHT_BUTTON)
		rightButton = down;

	///////////////////////////

		//***WRITE ACTIONS CONNECTED TO MOUSE STATE HERE

		//print cell coordinates after click
	if (down)
		cout << "(" << xcell_sel << "," << ycell_sel << ")" << "("<<x<<" "<<y<<")" << endl;

}


void OnTimer(int value)
{

	master.te_mueves();

	//No borrar estas lineas, siempre tienen que ir al final:
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}


