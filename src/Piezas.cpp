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
	//Esta función detecta si el movimiento introducido es válido.
	//Lo hace en función de los datos ya calculados con los movimientos posibles y comprueba
	//también si se producen jaques descubiertos, que son más difíciles de detectar antes de haber probado a hacer
	//el movimiento, cosa que se hace en esta función.
	Coords coordenadas_originales = coordenadas;
	for (int i = 0; i < MAX_MOV; i++) {
		if (destino == coordenadas_disponibles[i]) {
			if (tab->consultaCasilla(destino)) { //Comprueba si hay una pieza para comerla (eliminarla)
				tab->lista_piezas.eliminarPieza(tab->getIndexPiezaEn(destino));
			}

			coordenadas = destino; //Actualiza la posición de la pieza

			if (tab->jaqueAlRey(getColor())) {
				coordenadas = coordenadas_originales;
				return false;
			}
			return true;
		}
	}
	return false;
}


void Pieza::dibuja() {
	;
}