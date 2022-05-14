#pragma once
#include <iostream>

enum enum_x { a = 1, b, c, d, e, f, g, h }; //Equivalencia en letras para utilizar notación de ajedrez

class Vector2d {
	float x, y;
};

class Coords {
	int x, y;
	

public:
	Coords() { x = 1; y = 1; }
	Coords(int xi, int yi);
	void setX(int xi);
	void setY(int yi);
	void setXY(int xi, int yi);
	int getX() const;
	int getY() const;
	Coords getXY() const;
	friend std::ostream& operator << (std::ostream& os, const Coords& coordenada);
	friend bool operator == (const Coords& coordenada1, const Coords& coordenada2);
	friend bool operator != (const Coords& coordenada1, const Coords& coordenada2);

};

struct Movimiento { //Para el registro de movimientos
	int index; //Posición de la pieza dentro del vector de piezas al que pertenezca
	Coords destino; //Coordenadas de las que se puede mover la pieza.
	bool operator == (const Movimiento& mov);
};