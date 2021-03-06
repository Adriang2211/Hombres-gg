#pragma once
#include "Piezas.h"
using ETSIDI::Sprite;

class Peon :public Pieza {
	Sprite peonBlancas{ "imagenes/peonBlanco.png" };
	Sprite peonNegras{ "imagenes/peonNegro.png" };

	Sprite peonDorado{ "imagenes/peonDorado.png" };
	Sprite peonPlata{ "imagenes/peonPlata.png" };
public:
	Peon(bool color, int x, int y, Tablero* t);
	bool primer_movimiento;
	static const int valor = 1;
	void movimientos();
	bool mover(Coords destino);
	virtual bool getPrimerMovimiento() { return primer_movimiento; }
	void dibuja(int opc);

	int getValor() { return valor; };
};

