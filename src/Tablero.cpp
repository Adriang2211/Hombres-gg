#include "Posicionamiento.h"
#include "Tablero.h"
#include "Piezas.h"
#include "Torre.h"
#include "Caballo.h"
#include "Alfil.h"
#include "Dama.h"
#include "Rey.h"
#include "Peon.h"
#include <iostream>



void Tablero::inicializa() {
	//Genera la situación inicial de una partida de ajedrez convencional.
	//Para ajedrez960 sería necesaria una nueva función

	//Crear la hilera de peones blancos
	for (int i = 0; i < 8; i++)
		*(piezas + i) = new Peon(true, i + 1, 2, this); //This hace referencia a la dirección del tablero en el que se crean las piezas
	
	//Crear la hilera de peones negros
	for (int i = 8; i < 16; i++)
		*(piezas + i) = new Peon(false, i -7, 7, this);
	
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
	delete[] piezas; //Elimina todos los objetos creados dinámicamente.
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

void Tablero::cambiarTurno() {
	if (turno)
		turno = false;
	else
		turno = true;
}

void Tablero::actualizarCasillasOcupadas() {
	for (int i = 0, j =0, k=0; i < numero; i++) {
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

void Tablero::enroque_largo_blancas() {
	Coords coordenada_torre = { a, 1 };
	Coords coordenada_rey = { e, 1 };
	int index_t; //Posición del vector en la que se encuentra la torre blanca
	int index_r; //Posición del vector en la que se encuentra el rey

	//En teoría es redundante comprobar las coordenadas y el número el pieza.
	for (int i = 0; i < numero; i++) {
		if (piezas[i]->getColor() && piezas[i]->id==1 &&\
			piezas[i]->getCoordenadas() == coordenada_torre)
			index_t = i;
	}
	for (int i = 0; i < numero; i++) {
		if (piezas[i]->getColor() && piezas[i]->id == 5 && \
			piezas[i]->getCoordenadas() == coordenada_rey)
			index_r = i;
	}
	if (!consultaBlancas({ b, 1 }) && !consultaBlancas({ c, 1 }) && !consultaBlancas({ d, 1 })\
		&& piezas[index_t]->getPrimerMovimiento() && piezas[index_r]->getPrimerMovimiento())
		std::cout << "Enroque largo blancas es posible" << endl; //Prueba
	else
		std::cout << "Enroque imposible" << endl; //Prueba

	//Hay que comprobar que no esté en jaque

	//Guardar la posición en el vector
}