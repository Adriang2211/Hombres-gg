#include "Piezas.h"
#include "Posicionamiento.h"
#include "Tablero.h"
#include <iostream>

bool Pieza::getColor()
{
	return color;
};

Coords Pieza::getCoordenadas()
{
	return coordenadas;
};

void Pieza::setCoordenadas(int x, int y)
{
	coordenadas.setXY(x, y);
};

void Pieza::setCoordenadas(Coords a) { coordenadas = a; }
void Pieza::setColor(bool _color) { color = _color; }


bool Pieza::mover(Coords destino) {
	//Esta funci�n detecta si el movimiento introducido es v�lido.
	//Lo hace en funci�n de los datos ya calculados con los movimientos posibles y comprueba
	//tambi�n si se producen jaques descubiertos, que son m�s dif�ciles de detectar antes de haber probado a hacer
	//el movimiento, cosa que se hace en esta funci�n.
	Coords coordenadas_originales = coordenadas;
	Pieza* copia_comida = nullptr;
	bool intenta_comer = false;
	for (int i = 0; i < MAX_MOV; i++) {
		if (destino == coordenadas_disponibles[i]) {
			if (tab->consultaCasilla(destino)) { //Comprueba si hay una pieza para comerla (eliminarla)
				copia_comida = tab->getPiezaEn(destino);
				intenta_comer = true;
				tab->lista_piezas.eliminarPieza(tab->getIndexPiezaEn(destino));
			}

			coordenadas = destino; //Actualiza la posici�n de la pieza
			tab->actualizarCasillasOcupadas();
			tab->actualizarMovimientosPosibles();

			//En caso de jaque reestablecer la situaci�n inicial y salir devolviendo false.
			if (tab->jaqueAlRey(getColor())) {
				coordenadas = coordenadas_originales;
				if (intenta_comer)
					tab->lista_piezas.agregarPieza(copia_comida);
				return false;
			}
			tab->actualizarCasillasOcupadas();
			tab->actualizarMovimientosPosibles();
			return true;
		}
	}
	return false;
}


void Pieza::dibuja() {
	;
}