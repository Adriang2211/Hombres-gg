#pragma once
#include "Piezas.h"
using ETSIDI::Sprite;

class Dama :public Pieza {
	Sprite damaBlancas{ "imagenes/damaBlanca.png" };
	Sprite damaNegras{ "imagenes/damaNegra.png" };
public:
	Dama(bool color, int x, int y, Tablero* t);
	static const int valor = 9;
	void movimientos() ;
	virtual bool mover(Coords destino);
	virtual void dibuja();
};


