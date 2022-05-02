#pragma once
#include "Piezas.h"


class Rey :public Pieza {
public:
	//El rey no tiene valor
	virtual void movimientos();
	bool primer_movimiento; //Para el enroque, el rey no se puede haber movido.
	virtual bool mover(Coords destino);
};
