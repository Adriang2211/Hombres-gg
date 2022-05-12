#pragma once
#include "Piezas.h"
using ETSIDI::Sprite;

class Torre :public Pieza {
	Sprite torreBlancas{ "imagenes/torreBlanca.png" };
	Sprite torreNegras{ "imagenes/torreNegra.png" };
public:
	void movimientos();
	static const int valor = 5;
	bool primer_movimiento; //Para el enroque, la torre no se puede haber movido.
	bool mover(Coords destino);
	Torre(bool color, int x, int y, Tablero* t);
	virtual bool getPrimerMovimiento() { return primer_movimiento; }
	void dibuja();
};

