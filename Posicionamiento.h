#pragma once

class Vector2d {
	float x, y;
};

class Coords {
	int x, y;
	enum enum_x { A = 1, B, C, D, E, F, G, H };

public:
	Coords() { x = 1; y = 1; }
	Coords(int xi, int yi);
	void setX(int xi);
	void setY(int yi);
	void setXY(int xi, int yi);
	int getX();
	int getY();
	Coords getXY();

};
