#pragma once

enum enum_x { A = 1, B, C, D, E, F, G, H }; //Equivalencia en letras para utilizar notación de ajedrez

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
	int const getX();
	int const getY();
	Coords const getXY();

};
