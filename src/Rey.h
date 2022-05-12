#pragma once
#include "Piezas.h"


class Rey :public Pieza {
public:
	Rey(bool color, int x, int y, Tablero* t);
	//El rey no tiene valor numérico
	void movimientos();
	bool primer_movimiento; //Para el enroque, el rey no se puede haber movido.
	bool mover(Coords destino);
	virtual bool getPrimerMovimiento() { return primer_movimiento; }
};
