#pragma once

/*
* En este archivo se crean las clases de cada una de las piezas.
* Previsiblemente se creará una clase pieza que haciendo uso de hererncia
* agrupará los aspectos comunes a todas las piezas.
*/

#include "Posicionamiento.h" //Incluye la clase para el uso del sistema de coordenadas
#include "Interacciones.h" //Para declarla como amiga de todas las piezas

<<<<<<< Updated upstream

class Torre {
	friend class Interacciones;
public:
	Coords coordenadas;
	bool color; //True=blancas, flase = negras
public:
	//Sets y gets
	Coords getCorodenadas() { return coordenadas; }
	bool getColor() { return color; }
	void setCoordenadas(int x, int y){ coordenadas.setXY(x, y); }
	void setCoordenadas(Coords a) { coordenadas = a; }
=======
class Torre {
	Coords coordenadas;
	bool color; //True=blancas, flase = negras
>>>>>>> Stashed changes
};

class Caballo {
	Coords coordenadas;
	bool color;
};

class Alfil {
	Coords coordenadas;
	bool color;
};

class Dama {
	Coords coordenadas;
	bool color;
};

class Rey {
	Coords coordenadas;
	bool color;
};

class Peon {
	Coords coordenadas;
	bool color;
};