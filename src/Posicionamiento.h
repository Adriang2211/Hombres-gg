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

};
