#pragma once
#include "Piezas.h"

class Torre :public Pieza {
public:
	void movimientos();
	static const int valor = 5;
	bool primer_movimiento; //Para el enroque, la torre no se puede haber movido.
};

