#pragma once
#include "Piezas.h"


class Dama :public Pieza {
public:
	static const int valor = 9;
	void movimientos(); //Sin implementar
	virtual bool mover(Coords destino);
};


