#include "Posicionamiento.h"
#include <iostream> //Para sobrecarga de operadores

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

int Coords::getX() const{
	return x;
}

int Coords::getY() const{
	return y;
}

Coords Coords::getXY() const{
	return {x,y};
}

using namespace std;
ostream& operator << (ostream& os, const Coords& coordenadas) {
	os << "[";
	switch (coordenadas.getX()) {
	case 0: //Para cuando una pieza se ha comido y se ha "sacado" del tablero
		os << "#";
		break;
	case a:
		os << "a";
		break;
	case b:
		os << "b";
		break;
	case c:
		os << "c";
		break;
	case d:
		os << "d";
		break;
	case e:
		os << "e";
		break;
	case f:
		os << "f";
		break;
	case g:
		os << "g";
		break;
	case h:
		os << "h";
		break;
	default:
		os << "?";

	}
	if (coordenadas.getY() > 0 && coordenadas.getY() < 9)
		os << coordenadas.getY();
	else if (coordenadas.getY() == 0)
		os << "#";
	else
		os << "?";
	os << "]";
	return os;
}

bool operator == (const Coords& coordenada1, const Coords& coordenada2) {
	if (coordenada1.x == coordenada2.x && coordenada1.y == coordenada2.y)
		return true;
	else
		return false;
}

bool operator != (const Coords& coordenada1, const Coords& coordenada2) {
	if (coordenada1.x == coordenada2.x && coordenada1.y == coordenada2.y)
		return false;
	else
		return true;
}