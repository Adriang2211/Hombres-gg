#pragma once
#include "Piezas.h"


class Peon :public Pieza {
public:
	Peon(bool color, int x, int y, Tablero* t);
	bool primer_movimiento;
	static const int valor = 1;
	void movimientos();
	bool mover(Coords destino);
	virtual bool getPrimerMovimiento() { return primer_movimiento; }
};

