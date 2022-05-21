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




Tablero::Tablero() {
	juego_Terminado = false;
	turno = true; //empiezan las blancas
}

void Tablero::inicializa(bool guardado) {
	Pieza* piezast[NUMERO_DE_PIEZAS];
	if (guardado == false) {
		//Genera la situación inicial de una partida de ajedrez convencional.
		//Para ajedrez960 sería necesaria una nueva función
		//Crear la hilera de peones blancos
		for (int i = 0; i < 8; i++)
			*(piezast + i) = new Peon(true, i + 1, 2, this); //This hace referencia a la dirección del tablero en el que se crean las piezas

		//Crear la hilera de peones negros
		for (int i = 8; i < 16; i++)
			*(piezast + i) = new Peon(false, i - 7, 7, this);

		//Crear las torres
		piezast[16] = new Torre(true, a, 1, this);
		piezast[17] = new Torre(true, h, 1, this);
		piezast[18] = new Torre(false, a, 8, this);
		piezast[19] = new Torre(false, h, 8, this);

		//Crear caballos
		piezast[20] = new Caballo(true, b, 1, this);
		piezast[21] = new Caballo(true, g, 1, this);
		piezast[22] = new Caballo(false, b, 8, this);
		piezast[23] = new Caballo(false, g, 8, this);
		//Crear alfiles
		piezast[24] = new Alfil(true, c, 1, this);
		piezast[25] = new Alfil(true, f, 1, this);
		piezast[26] = new Alfil(false, c, 8, this);
		piezast[27] = new Alfil(false, f, 8, this);
		//Crear damas
		piezast[28] = new Dama(true, d, 1, this);
		piezast[29] = new Dama(false, d, 8, this);
		//Crear reyes
		piezast[30] = new Rey(true, e, 1, this);
		piezast[31] = new Rey(false, e, 8, this);

		//Agregar las piezas al vector 
		for (int i = 0; i < 32; i++)
			lista_piezas.agregarPieza(piezast[i]);
	}
	else {//HAY que inicializar lo que esté guardado en el fichero

	}

	//Actualización de la situación
	actualizarCasillasOcupadas();
	actualizarMovimientosPosibles();
}



bool Tablero::consultaBlancas(Coords const coordenada){
	for (int i = 0; i < 16; i++) {
		//Busca la coordenada que se ha pasado en el vector de las piezas blancas
		if (casillas_ocupadas_blancas[i].getX() == coordenada.getX() && casillas_ocupadas_blancas[i].getY() == coordenada.getY())
			return true;     //devuelve true si hay una pieza blanca en la casilla
	}
	return false;		//devuelve flase si no hay una pieza blanca en la casilla
}

bool Tablero::consultaNegras(Coords const coordenada) {
	for (int i = 0; i < 16; i++) {
		//Busca la coordenada que se ha pasado en el vector de las piezas negras
		if (casillas_ocupadas_negras[i].getX() == coordenada.getX() && casillas_ocupadas_negras[i].getY() == coordenada.getY())
			return true;
	}
	return false;
}

bool Tablero::consultaCasilla(Coords const coordenada) {
	if (consultaBlancas(coordenada) || consultaNegras(coordenada)){
		return true;
	}
	else
		return false;
}




Tablero::~Tablero() {
	lista_piezas.eliminar();;
}

void Tablero::dibuja() {
	int N = 8;
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			if ((i + j) % 2 != 0) {
				glColor3ub(255, 255, 255);
				glBegin(GL_QUADS);
				glVertex3f(i, j, -0.1);
				glVertex3f(i, j + 1, -0.1);
				glVertex3f(i + 1, j + 1, -0.1);
				glVertex3f(i + 1, j, -0.1);
				glEnd();
			}
			else {
				glColor3ub(128, 64, 0);
				glBegin(GL_QUADS);
				glVertex3f(i, j, -0.1);
				glVertex3f(i, j + 1, -0.1);
				glVertex3f(i + 1, j + 1,- 0.1);
				glVertex3f(i + 1, j, -0.1);
				glEnd();
			}
		}
		
	}
	
	
	for (int i = 0; i < lista_piezas.getNumeroPiezas(); i++) {
		lista_piezas.getPieza(i)->dibuja();
	}


}

void Tablero::cambiarTurno() {
	if (turno)
		turno = false;
	else
		turno = true;
}

void Tablero::actualizarCasillasOcupadas() {
	int j = 0, k = 0; //Índices para la escritura en los vectores
	//Leer las posiciones de las piezas existentes
	for (int i = 0; i < lista_piezas.getNumeroPiezas(); i++) {
		if (lista_piezas.getPieza(i)->getColor()) { //Para las blancas
			casillas_ocupadas_blancas[j] = lista_piezas.getPieza(i)->getCoordenadas();
			j++;
		}
		else { //Para las negras
			casillas_ocupadas_negras[k] = lista_piezas.getPieza(i)->getCoordenadas();
			k++;
		}
	}

	//Poner posiciones vacías en el resto de los vectores.
	for (int i = j; j < NUMERO_DE_PIEZAS / 2; j++)
		casillas_ocupadas_blancas[j] = { 9,9 };
	for (int i = k; k < NUMERO_DE_PIEZAS / 2; k++)
		casillas_ocupadas_negras[k] = { 9, 9 };	
}


bool Tablero::enroque_largo_blancas() {
	Coords coordenada_torre = { a, 1 };
	Coords coordenada_rey = { e, 1 };

	int index_t = 0; //Posición del vector en la que se encuentra la torre blanca
	int index_r = 0; //Posición del vector en la que se encuentra el rey

	bool rey_encontrado = false;
	bool torre_encontrada = false;

	//En teoría es redundante comprobar las coordenadas y el número el pieza.
	for (int i = 0; i < lista_piezas.getNumeroPiezas(); i++) {
		if (lista_piezas.getPieza(i)->getColor() && lista_piezas.getPieza(i)->getCoordenadas() == coordenada_torre && lista_piezas.getPieza(i)->id == TORRE) {
			index_t = i;
			torre_encontrada = true;
		}
	}
	for (int i = 0; i < lista_piezas.getNumeroPiezas(); i++) {
		if (lista_piezas.getPieza(i)->getColor() && lista_piezas.getPieza(i)->getCoordenadas() == coordenada_rey && lista_piezas.getPieza(i)->id == REY) {
			index_r = i;
			rey_encontrado = true;
		}
	}
	if (torre_encontrada && rey_encontrado) {
		if (consultaCasilla({ b, 1 }) || consultaCasilla({ c, 1 }) || consultaCasilla({ d, 1 })\
			|| !lista_piezas.getPieza(index_t)->getPrimerMovimiento() || !lista_piezas.getPieza(index_r)->getPrimerMovimiento())
			return false;
	}
	else {
		return false;
	}

	//Si las condiciones anteriores no se han cumplido, esta parte del programa no se ejecutará gracias a los return false
	//Aquí se comprueba que ninguna de las casillas del enroque esté bajo ataque.
	if (casillaAtacada({ b, 1 }, false) || casillaAtacada({ c, 1 }, false) || casillaAtacada({ d, 1 }, false) || casillaAtacada({ e, 1 }, false))
		return false;
	else
		return true; 
}


bool Tablero::enroque_largo_negras() {
	Coords coordenada_torre = { a, 8 };
	Coords coordenada_rey = { e, 8 };

	int index_t=0; //Posición del vector en la que se encuentra la torre blanca
	int index_r=0; //Posición del vector en la que se encuentra el rey

	bool rey_encontrado = false;
	bool torre_encontrada = false;

	//En teoría es redundante comprobar las coordenadas y el número el pieza.
	for (int i = 0; i < lista_piezas.getNumeroPiezas(); i++) {
		if (!lista_piezas.getPieza(i)->getColor() && lista_piezas.getPieza(i)->getCoordenadas() == coordenada_torre && lista_piezas.getPieza(i)->id == TORRE) {
			index_t = i;
			torre_encontrada = true;
		}
	}
	for (int i = 0; i < lista_piezas.getNumeroPiezas(); i++) {
		if (!lista_piezas.getPieza(i)->getColor() && lista_piezas.getPieza(i)->getCoordenadas() == coordenada_rey && lista_piezas.getPieza(i)->id == REY) {
			index_r = i;
			rey_encontrado = true;
		}
	}

	if (rey_encontrado && torre_encontrada) {
		if (consultaCasilla({ b, 8 }) || consultaCasilla({ c , 8 }) || consultaCasilla({ d, 8 })\
			|| !lista_piezas.getPieza(index_t)->getPrimerMovimiento() || !lista_piezas.getPieza(index_r)->getPrimerMovimiento())
			return false;
	}
	else {
		return false;
	}

	//Comprobación de que las casillas del enroque no se encuentren bajo ataque.
	if (casillaAtacada({ b, 8 }, true) || casillaAtacada({ c, 8 }, true) || casillaAtacada({ d, 8 }, true) || casillaAtacada({ e, 8 }, true))
		return false;
	else
		return true;
}



bool Tablero::enroque_corto_blancas() {
	Coords coordenada_torre = { h, 1 };
	Coords coordenada_rey = { e, 1 };

	int index_t=0; //Posición del vector en la que se encuentra la torre blanca
	int index_r=0; //Posición del vector en la que se encuentra el rey

	bool rey_encontrado = false;
	bool torre_encontrada = false;

	//En teoría es redundante comprobar las coordenadas y el número el pieza.
	for (int i = 0; i < lista_piezas.getNumeroPiezas(); i++) {
		if (lista_piezas.getPieza(i)->getColor() && lista_piezas.getPieza(i)->getCoordenadas() == coordenada_torre && lista_piezas.getPieza(i)->id==TORRE) {
			index_t = i;
			torre_encontrada = true;
			break;
		}
	}
	for (int i = 0; i < lista_piezas.getNumeroPiezas(); i++) {
		if (lista_piezas.getPieza(i)->getColor() && lista_piezas.getPieza(i)->getCoordenadas() == coordenada_rey && lista_piezas.getPieza(i)->id == REY) {
			index_r = i;
			rey_encontrado = true;
			break;
		}
	}
	if (rey_encontrado && torre_encontrada) {
		if (consultaCasilla({ g, 1 }) || consultaCasilla({ f, 1 })\
			|| !lista_piezas.getPieza(index_t)->getPrimerMovimiento() || !lista_piezas.getPieza(index_r)->getPrimerMovimiento())
			return false;
	}
	else {
		return false;
	}

	if (!casillaAtacada({ g, 1 }, false) && !casillaAtacada({ f, 1 }, false) && !casillaAtacada({ e, 1 }, false))
		return true;
	else
		return false;
}

bool Tablero::enroque_corto_negras() {
	Coords coordenada_torre = { h, 8 };
	Coords coordenada_rey = { e, 8 };

	int index_t=0; //Posición del vector en la que se encuentra la torre blanca
	int index_r=0; //Posición del vector en la que se encuentra el rey

	bool rey_encontrado = false;
	bool torre_encontrada = false;

	for (int i = 0; i < lista_piezas.getNumeroPiezas(); i++) {
		if (!lista_piezas.getPieza(i)->getColor() && lista_piezas.getPieza(i)->id == 1 && \
			lista_piezas.getPieza(i)->getCoordenadas() == coordenada_torre && lista_piezas.getPieza(i)->id == TORRE) {
			index_t = i;
			torre_encontrada = true;
		}
	}
	for (int i = 0; i < lista_piezas.getNumeroPiezas(); i++) {
		if (!lista_piezas.getPieza(i)->getColor() && lista_piezas.getPieza(i)->id == 5 && \
			lista_piezas.getPieza(i)->getCoordenadas() == coordenada_rey && lista_piezas.getPieza(i)->id == REY) {
			index_r = i;
			rey_encontrado = true;
		}
	}

	if (rey_encontrado && torre_encontrada) {
		if (consultaCasilla({ f, 8 }) || consultaCasilla({ g , 8 })
			|| !lista_piezas.getPieza(index_t)->getPrimerMovimiento() || !lista_piezas.getPieza(index_r)->getPrimerMovimiento())
			return false;
	}
	else {
		return false;
	}

	//Comprobar que ninguna de las casillas del enroque se encuentra bajo ataque.
	if (casillaAtacada({ g, 8 }, true) || casillaAtacada({ f, 8 }, true) || casillaAtacada({ e, 8 }, true))
		return false;
}

/*
using namespace std;
ostream& operator << (ostream& os, const Tablero& tab) {
	os << "SITUACION ACTUAL DEL TABLERO: " << endl;
	os << "Turno: " << tab.turno << endl;
	os << "Numero de jugada: " << tab.jugada << endl;
	os << "Piezas y sus posiciones:" << endl;
	os << "_______________________________________________________________________________________" << endl;
	for (int i = 0; i < NUMERO_DE_PIEZAS; i++) {
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
			//Color de la pieza
			if (tab.piezas[i]->getColor())
				os << "\tColor: blanco" << endl;
			else
				os << "\tColor: negro" << endl;

			//Coordenadas de la pieza
			os << "\tCoordenadas: " << tab.piezas[i]->getCoordenadas() << endl;

			//Movimientos posibles de la pieza
			os << "\tLista de casillas a las que puede ir la pieza: " << endl << "\t";
			Coords coordenadas_vacias = { 9,9 };
			for (int j = 0; j < MAX_MOV; j++) {
				if (tab.piezas[i]->coordenadas_disponibles[j] != coordenadas_vacias)
					os << tab.piezas[i]->coordenadas_disponibles[j];
			}
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
*/

void Tablero::actualizarMovimientosPosibles() {
	for (int i = 0; i < lista_piezas.getNumeroPiezas(); i++) {
		lista_piezas.getPieza(i)->movimientos();
	}
}


void Tablero::generarTest() {
	//Función de pruebas, no es parte del programa definitivo
	//Situación basada en posición 2 de test pero sin el enroque
	//información sobre esto no disponible en github todavía.
	Pieza* piezast [NUMERO_DE_PIEZAS];
	piezast[0] = new Torre(true, a, 1, this);
	piezast[1] = new Caballo(true, b, 1, this);
	piezast[2] = new Alfil(true, c, 1, this);
	piezast[3] = new Dama(true, d, 1, this);
	piezast[4] = new Rey(true, e, 1, this);
	piezast[5] = new Torre(true, h, 1, this);
	piezast[6] = new Peon(true, a, 2, this);
	piezast[7] = new Peon(true, b, 2, this);
	piezast[8] = new Peon(true, c, 2, this);
	piezast[9] = new Peon(true, d, 2, this);
	piezast[10] = new Peon(true, f, 2, this);
	piezast[11] = new Peon(true, g, 2, this);
	piezast[12] = new Peon(true, h, 2, this);
	piezast[13] = new Peon(true, e, 4, this);
	piezast[14] = new Caballo(true, f, 3, this);
	piezast[15] = new Alfil(true, c, 4, this);

	piezast[16] = new Torre(false, a, 8, this);
	piezast[17] = new Alfil(false, c, 8, this);
	piezast[18] = new Dama(false, d, 8, this);
	piezast[19] = new Rey(false, e, 8, this);
	piezast[20] = new Caballo(false, g, 8, this);
	piezast[21] = new Torre(false, h, 8, this);
	piezast[22] = new Peon(false, b, 7, this);
	piezast[23] = new Peon(false, c, 7, this);
	piezast[24] = new Peon(false, d, 7, this);
	piezast[25] = new Peon(false, f, 7, this);
	piezast[26] = new Peon(false, g, 7, this);
	piezast[27] = new Peon(false, h, 7, this);
	piezast[28] = new Peon(false, a, 6, this);
	piezast[29] = new Caballo(false, c, 6, this);
	piezast[30] = new Alfil(false, c, 5, this);
	piezast[31] = new Peon(false, e, 5, this);
	for (int i = 0; i < 32; i++)
		lista_piezas.agregarPieza(piezast[i]);

	//Actualización de la situación
	//Doble ejecución para garantizar que todos los movimientos se calculan conociendo de antemano
	//los movimientos posibles de todas las demás piezas (es imortante para los jaques y para los enroques).
	for (int i = 0; i < 2; i++) {
		actualizarCasillasOcupadas();
		actualizarMovimientosPosibles();
	}

}


bool Tablero::casillaAtacada(Coords const coordenada, bool color) {
	//Color hace referencia a la pieza atacante
	for (int i = 0; i < lista_piezas.getNumeroPiezas(); i++) {
		if (lista_piezas.getPieza(i)->getColor() == color) { //Comprueba que el color sea el elegido
			for (int j = 0; j < MAX_MOV; j++) {
				if (lista_piezas.getPieza(i)->coordenadas_disponibles[j] == coordenada)
					return true;
			}
		}
	}
	return false;
}

bool Tablero::jaqueAlRey(bool color) {
	for (int i = 0; i < lista_piezas.getNumeroPiezas(); i++) {
		if (lista_piezas.getPieza(i)->getColor() == color && lista_piezas.getPieza(i)->id == REY)
			return casillaAtacada(lista_piezas.getPieza(i)->getCoordenadas(), !color);
	}
}

Coords Tablero::getMov_siguiente() {
	return mov_siguiente;
}

void Tablero::setMov_siguiente(Coords coord) {
	mov_siguiente = coord;
}








/* En progreso...
bool Tablero::jaqueMate(bool color) {
	int index_rey=0;
	for (int i = 0; i < numero; i++) {
		if (piezas[i]->getColor() == color && piezas[i]->id == REY) {
			index_rey = i;
			break;
		}
	}
}
*/

void Tablero::generarLista() {
	Movimiento mov;
	Coords coordenadas_no_validas = { 9,9 };
	for (int i = 0; i < lista_piezas.getNumeroPiezas(); i++) {
		for (int j = 0; j < lista_piezas.getNumeroPiezas(); j++) {
			if (lista_piezas.getPieza(i)->getCoordenadas() == coordenadas_no_validas) {
				mov.index = i; //Guardar la posición de la pieza en el array
				mov.destino = lista_piezas.getPieza(i)->coordenadas_disponibles[j]; //Guardar el destino
			}
		}
	}
}