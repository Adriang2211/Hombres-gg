#include "Dama.h"
#include "Tablero.h"


Dama::Dama(bool color, int x, int y, Tablero* t) {
	this->color = color;
	coordenadas.setX(x);
	coordenadas.setY(y);
	tab = t;
}



bool Dama::mover(Coords destino) {
	for (int i = 0; i < MAX_MOV; i++) {
		if (destino == coordenadas_disponibles[i]) {
			coordenadas = destino;
			return true;
		}
	}
	return false;
}