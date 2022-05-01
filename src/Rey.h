#pragma once
#include "Piezas.h"


class Rey :public Pieza {
public:
	//El rey no tiene valor
	void movimientos(); //Sin implementar
	bool primer_movimiento; //Para el enroque, el rey no se puede haber movido.
};
