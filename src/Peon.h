#pragma once
#include "Piezas.h"


class Peon :public Pieza {
public:
	bool primer_movimiento;
	static const int valor = 1;
	virtual void movimientos();
	virtual bool mover(Coords destino);
};

