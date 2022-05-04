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
	//Genera la situación inicial de una partida de ajedrez convencional.
//Para ajedrez960 sería necesaria una nueva función
//Crear la hilera de peones blancos
	for (int i = 0; i < 8; i++)
		*(piezas + i) = new Peon(true, i + 1, 2, this); //This hace referencia a la dirección del tablero en el que se crean las piezas

	//Crear la hilera de peones negros
	for (int i = 8; i < 16; i++)
		*(piezas + i) = new Peon(false, i - 7, 7, this);

	//Crear las torres
	piezas[16] = new Torre(true, a, 1, this);
	piezas[17] = new Torre(true, h, 1, this);
	piezas[18] = new Torre(false, a, 8, this);
	piezas[19] = new Torre(false, h, 8, this);

	//Crear caballos
	piezas[20] = new Caballo(true, b, 1, this);
	piezas[21] = new Caballo(true, g, 1, this);
	piezas[22] = new Caballo(false, b, 8, this);
	piezas[23] = new Caballo(false, g, 8, this);
	//Crear alfiles
	piezas[24] = new Alfil(true, c, 1, this);
	piezas[25] = new Alfil(true, f, 1, this);
	piezas[26] = new Alfil(false, c, 8, this);
	piezas[27] = new Alfil(false, f, 8, this);
	//Crear damas
	piezas[28] = new Dama(true, d, 1, this);
	piezas[29] = new Dama(false, d, 8, this);
	//Crear reyes
	piezas[30] = new Rey(true, e, 1, this);
	piezas[31] = new Rey(true, e, 8, this);
	numero = 32; //Se empieza siempre con 32 piezas.
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
				glEnd();
			}
			else {
				glColor3ub(255, 0, 0);
				glBegin(GL_QUADS);
				glVertex3f(i, j, 0);
				glVertex3f(i, j + 1, 0);
				glVertex3f(i + 1, j + 1, 0);
				glVertex3f(i + 1, j, 0);
				glEnd();
			}
		}
	}
}

void Tablero::cambiarTurno() {
	if (turno)
		turno = false;
	else
		turno = true;
}


void Tablero::actualizarCasillasOcupadas() {
	for (int i = 0, j = 0, k = 0; i < numero; i++) {
		if (piezas[i]->getColor()) {
			casillas_ocupadas_blancas[j] = piezas[i]->getCoordenadas();
			j++;
		}
		else {
			casillas_ocupadas_negras[k] = piezas[i]->getCoordenadas();
			k++;
		}
	}
}


bool Tablero::enroque_largo_blancas() {
	Coords coordenada_torre = { a, 1 };
	Coords coordenada_rey = { e, 1 };
	int index_t = 0; //Posición del vector en la que se encuentra la torre blanca
	int index_r = 0; //Posición del vector en la que se encuentra el rey

	//En teoría es redundante comprobar las coordenadas y el número el pieza.
	for (int i = 0; i < numero; i++) {
		if (piezas[i]->getColor() && piezas[i]->getCoordenadas() == coordenada_torre && piezas[i]->id == 1)
			index_t = i;
	}
	for (int i = 0; i < numero; i++) {
		if (piezas[i]->getColor() && piezas[i]->getCoordenadas() == coordenada_rey && piezas[i]->id == 5)
			index_r = i;
	}
	if (!consultaBlancas({ b, 1 }) && !consultaBlancas({ c, 1 }) && !consultaBlancas({ d, 1 })\
		&& piezas[index_t]->getPrimerMovimiento() && piezas[index_r]->getPrimerMovimiento()) {
		std::cout << "Enroque largo blancas es posible" << std::endl; //Prueba
		return true;
	}
	else {
		std::cout << "Enroque largo blancas imposible" << std::endl; //Prueba
		return false;
	}

	//Falta comprobar la legaliadad de la jugada. (Si alguna de las casillas del enroque esta bajo
	//ataque no se puede hacer el enroque.
}


bool Tablero::enroque_largo_negras() {
	Coords coordenada_torre = { a, 8 };
	Coords coordenada_rey = { e, 8 };
	int index_t=0; //Posición del vector en la que se encuentra la torre blanca
	int index_r=0; //Posición del vector en la que se encuentra el rey

	//En teoría es redundante comprobar las coordenadas y el número el pieza.
	for (int i = 0; i < numero; i++) {
		if (!piezas[i]->getColor() && piezas[i]->getCoordenadas() == coordenada_torre)
			index_t = i;
	}
	for (int i = 0; i < numero; i++) {
		if (!piezas[i]->getColor() && piezas[i]->getCoordenadas() == coordenada_rey)
			index_r = i;
	}
	if (!consultaBlancas({ b, 8 }) && !consultaBlancas({ c , 8 }) && !consultaBlancas({ d, 8 }) && piezas[index_t]->id == 1\
		&& piezas[index_t]->getPrimerMovimiento() && piezas[index_r]->getPrimerMovimiento() && piezas[index_r]->id == 5) {
		std::cout << "Enroque largo negras es posible" << std::endl; //Prueba
		return true;
	}
	else {
		std::cout << "Enroque largo negras imposible" << std::endl; //Prueba
		return false;
	}

	//Falta comprobar la legaliadad de la jugada. (Si alguna de las casillas del enroque esta bajo
	//ataque no se puede hacer el enroque.
}



bool Tablero::enroque_corto_blancas() {
	Coords coordenada_torre = { h, 1 };
	Coords coordenada_rey = { e, 1 };
	int index_t=0; //Posición del vector en la que se encuentra la torre blanca
	int index_r=0; //Posición del vector en la que se encuentra el rey

	//En teoría es redundante comprobar las coordenadas y el número el pieza.
	for (int i = 0; i < numero; i++) {
		if (piezas[i]->getColor() && piezas[i]->getCoordenadas() == coordenada_torre)
			index_t = i;
	}
	for (int i = 0; i < numero; i++) {
		if (piezas[i]->getColor() && piezas[i]->getCoordenadas() == coordenada_rey)
			index_r = i;
	}
	if (!consultaBlancas({ g, 1 }) && !consultaBlancas({ f, 1 }) && piezas[index_t]->id == 1\
		&& piezas[index_t]->getPrimerMovimiento() && piezas[index_r]->getPrimerMovimiento() && piezas[index_r]->id == 5) {
		std::cout << "Enroque corto blancas es posible" << std::endl; //Prueba
		return true;
	}
	else {
		std::cout << "Enroque corto blancas imposible" << std::endl; //Prueba
		return false;
	}
}

bool Tablero::enroque_corto_negras() {
	Coords coordenada_torre = { h, 8 };
	Coords coordenada_rey = { e, 8 };
	int index_t=0; //Posición del vector en la que se encuentra la torre blanca
	int index_r=0; //Posición del vector en la que se encuentra el rey

	for (int i = 0; i < numero; i++) {
		if (!piezas[i]->getColor() && piezas[i]->id == 1 && \
			piezas[i]->getCoordenadas() == coordenada_torre)
			index_t = i;
	}
	for (int i = 0; i < numero; i++) {
		if (!piezas[i]->getColor() && piezas[i]->id == 5 && \
			piezas[i]->getCoordenadas() == coordenada_rey)
			index_r = i;
	}
	if (!consultaBlancas({ f, 8 }) && !consultaBlancas({ g , 8 }) && piezas[index_r]->id == 5\
		&& piezas[index_t]->getPrimerMovimiento() && piezas[index_r]->getPrimerMovimiento() && piezas[index_t]->id==5) {
		std::cout << "Enroque negras corto es posible" << std::endl; //Prueba
		return true;
	}
	else {
		std::cout << "Enroque negras corto imposible" << std::endl; //Prueba
		return false;
	}
}

using namespace std;
ostream& operator << (ostream& os, const Tablero& tab) {
	os << "SITUACION ACTUAL DEL TABLERO: " << endl;
	os << "Turno: " << tab.turno << endl;
	os << "Numero de jugada: " << tab.jugada << endl;
	os << "Piezas y sus posiciones:" << endl;
	os << "_______________________________________________________________________________________" << endl;
	for (int i = 0; i < tab.numero; i++) {
		if (*(tab.piezas + i) != NULL) {
			switch (tab.piezas[i]->id) {
			case 1:
				os << "Torre" << endl;
				break;
			case 2:
				os << "Caballo" << endl;
				break;
			case 3:
				os << "Alfil" << endl;
				break;
			case 4:
				os << "Dama" << endl;
				break;
			case 5:
				os << "Rey" << endl;
				break;
			case 6:
				os << "Peon" << endl;
				break;
			default:
				os << "Ooops. Se ha producido un error." << endl;
			}
			if (tab.piezas[i]->getColor())
				os << "\tColor: blanco" << endl;
			else
				os << "\tColor: negro" << endl;
			os << "\tCoordenadas: " << tab.piezas[i]->getCoordenadas();
			os << endl << "________________________________" << endl;
		}
	}
	os << endl << "Casillas ocupadas blancas:" << endl;
	for (int i = 0; i < NUMERO_DE_PIEZAS / 2; i++)
		os << tab.casillas_ocupadas_blancas[i] << endl;
	os << "___________________________________" << endl;
	os << endl << "Casillas ocupadas negras:" << endl;
	for (int i = 0; i < NUMERO_DE_PIEZAS / 2; i++)
		os << tab.casillas_ocupadas_negras[i] << endl;
	return os;
}
