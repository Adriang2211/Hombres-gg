#pragma once
#include "Piezas.h"

class Caballo :public Pieza {
private:
	void tuPetitInteraccion(Coords coordenadas_de_consulta, Coords coordenadas_inservibles, int i);
public:
	static const int valor = 3;
	virtual void movimientos();
	virtual bool mover(Coords destino);
};