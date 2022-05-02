#pragma once
#include "Piezas.h"


class Alfil :public Pieza {
public:
	static const int valor = 3;
	//Posible alternativa: valor 3.5, para diferenciarlo de la torre y que el programa sea más propenso a
	//conservar los alfiles en lugar de los caballos.
	virtual void movimientos();
};
