#pragma once
#include "Piezas.h"
using ETSIDI::Sprite;

class Rey :public Pieza {
	Sprite reyBlancas{ "imagenes/reyBlanco.png" };
	Sprite reyNegras{ "imagenes/reyNegro.png" };
	Sprite reyDorado{ "imagenes/reyDorado.png" };
	Sprite reyPlata{ "imagenes/reyPlata.png" };
	static const int valor = INT_MAX/2;
public:
	Rey(bool color, int x, int y, Tablero* t);
	//El rey no tiene valor numérico
	void movimientos();
	bool primer_movimiento; //Para el enroque, el rey no se puede haber movido.
	bool mover(Coords destino);
	virtual bool getPrimerMovimiento() { return primer_movimiento; }
	void dibuja(int opc);

	int getValor() { return valor; };
};
