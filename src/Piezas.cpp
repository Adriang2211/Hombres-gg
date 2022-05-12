#include "Piezas.h"
#include "Posicionamiento.h"
#include "Tablero.h"
#include <iostream>

bool Pieza::getColor()
{
	return color;
};

Coords Pieza::getCoordenadas()
{
	return coordenadas;
};

void Pieza::setCoordenadas(int x, int y)
{
	coordenadas.setXY(x, y);
};

void Pieza::setCoordenadas(Coords a) { coordenadas = a; }
void Pieza::setColor(bool _color) { color = _color; }


bool Pieza::mover(Coords destino) { return 0; }


void Pieza::dibuja() {
	;

}