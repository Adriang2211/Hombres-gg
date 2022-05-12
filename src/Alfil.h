#pragma once
#include "Piezas.h"
#include "Posicionamiento.h"
using ETSIDI::Sprite;

class Alfil :public Pieza {
	Sprite alfilBlancas{ "imagenes/alfilBlanco.png" };
	Sprite alfilNegras{ "imagenes/alfilNegro.png" };
public:
	Alfil(bool color, int x, int y, Tablero* t);
	static const int valor = 3;
	//Posible alternativa: valor 3.5, para diferenciarlo de la torre y que el programa sea más propenso a
	//conservar los alfiles en lugar de los caballos.
	virtual void movimientos();
	virtual bool mover(Coords destino);
	virtual void dibuja();
};
