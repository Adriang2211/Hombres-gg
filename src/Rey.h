#pragma once
#include "Piezas.h"


class Rey :public Pieza {
public:
	Rey(bool color, int x, int y, Tablero* t);
	//El rey no tiene valor numérico
	virtual void movimientos();
	bool primer_movimiento; //Para el enroque, el rey no se puede haber movido.
	virtual bool mover(Coords destino);
};
