#pragma once
#include "Posicionamiento.h"

#define MAX_MOVIMIENTOS 432 //N�mero m�ximo de movimientos para las piezas de un color

class ListaMovimientos {
private:
	Movimiento* lista [MAX_MOVIMIENTOS];
	int numero;

public:
	//Constructor
	ListaMovimientos();

	bool agregar(Movimiento mov);
	void eliminar();
};