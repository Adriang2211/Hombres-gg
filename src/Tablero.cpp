#include "Posicionamiento.h"
#include "Tablero.h"
#include "Piezas.h"
#include "Torre.h"
#include "Caballo.h"
#include "Alfil.h"
#include "Dama.h"
#include "Rey.h"
#include "Peon.h"
#include "freeglut.h"


void Tablero::inicializa() {
	
}



bool Tablero::consultaBlancas(Coords coordenada){
	for (int i = 0; i < 16; i++) {
		//Busca la coordenada que se ha pasado en el vector de las piezas blancas
		if (casillas_ocupadas_blancas[i].getX() == coordenada.getX() && casillas_ocupadas_blancas[i].getY() == coordenada.getY())
			return true;     //devuelve true si hay una pieza blanca en la casilla
	}
	return false;		//devuelve flase si no hay una pieza blanca en la casilla
}

bool Tablero::consultaNegras(Coords coordenada) {
	for (int i = 0; i < 16; i++) {
		//Busca la coordenada que se ha pasado en el vector de las piezas negras
		if (casillas_ocupadas_negras[i].getX() == coordenada.getX() && casillas_ocupadas_negras[i].getY() == coordenada.getY())
			return true;
	}
	return false;
}


Tablero::~Tablero() {
	delete[] piezas;
}

void Tablero::dibuja() {
	int N = 8;
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			if ((i + j) % 2 != 0) {
				glColor3ub(255, 255, 255);
				glBegin(GL_QUADS);
				glVertex3f(i, j, 0);
				glVertex3f(i, j + 1, 0);
				glVertex3f(i + 1, j + 1, 0);
				glVertex3f(i + 1, j, 0);
			}
			else {
				glColor3ub(255, 0, 0);
				glBegin(GL_QUADS);
				glVertex3f(i, j, 0);
				glVertex3f(i, j + 1, 0);
				glVertex3f(i + 1, j + 1, 0);
				glVertex3f(i + 1, j, 0);
			}
		}
	}
}