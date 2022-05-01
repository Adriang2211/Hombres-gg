#pragma once
#include "Piezas.h"

class Torre :public Pieza {
public:
	void movimientos();
	static const int valor = 5;
};

