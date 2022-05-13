#pragma once
#include "Piezas.h"
using ETSIDI::Sprite;

class Caballo :public Pieza {
private:
	void tuPetitInteraccion(Coords coordenadas_de_consulta, Coords coordenadas_inservibles, int i);
	Sprite caballoBlancas{"imagenes/caballoBlanco.png"};
	Sprite caballoNegras{ "imagenes/caballoNegro.png" };
public:
	Caballo(bool color, int x, int y, Tablero* t);
	static const int valor = 3;
	void movimientos();
	void dibuja();

};