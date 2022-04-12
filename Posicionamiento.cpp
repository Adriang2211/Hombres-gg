#include "Posicionamiento.h"


Coords::Coords(int xi, int yi) {
	x = xi;
	y = yi;
}
void Coords::setX(int xi) {
	x = xi;
}

void Coords::setY(int yi) {
	y = yi;
}

void Coords::setXY(int xi, int yi) {
	x = xi;
	y = yi;
}

int Coords::getX() {
	return x;
}

int Coords::getY() {
	return y;
}

Coords Coords::getXY() {
	return {x,y};
}