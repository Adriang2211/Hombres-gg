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

int const Coords::getX() {
	return x;
}

int const Coords::getY() {
	return y;
}

Coords const Coords::getXY() {
	return {x,y};
}