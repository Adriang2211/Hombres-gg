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
	case A:
		os << "a";
		break;
	case B:
		os << "b";
		break;
	case C:
		os << "c";
		break;
	case D:
		os << "d";
		break;
	case E:
		os << "e";
		break;
	case F:
		os << "f";
		break;
	case G:
		os << "g";
		break;
	case H:
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