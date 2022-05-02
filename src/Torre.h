#pragma once
#include "Piezas.h"

class Torre :public Pieza {
public:
	virtual void movimientos();
	static const int valor = 5;
	bool primer_movimiento; //Para el enroque, la torre no se puede haber movido.
	virtual bool mover(Coords destino);
	Torre(bool color, int x, int y, Tablero* t);
};

