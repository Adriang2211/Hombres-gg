#pragma once
#include "Piezas.h"


class Dama :public Pieza {
public:
	Dama(bool color, int x, int y, Tablero* t);
	static const int valor = 9;
	void movimientos() ;
	bool mover(Coords destino);
};


