#pragma once

/*
* En este archivo se crean las clases de cada una de las piezas.
* Previsiblemente se creará una clase pieza que haciendo uso de hererncia
* agrupará los aspectos comunes a todas las piezas.
*/

#include "Posicionamiento.h" //Incluye la clase para el uso del sistema de coordenadas

class Torre {
	Coords coordenadas;
	bool color; //TRUE = blancas; FALSE = negras
};

class Caballo {
	Coords coordenadas;
	bool color; //TRUE = blancas; FALSE = negras
};

class Alfil {
	Coords coordenadas;
	bool color; //TRUE = blancas; FALSE = negras
};

class Dama {
	Coords coordenadas;
	bool color; //TRUE = blancas; FALSE = negras
};

class Rey {
	Coords coordenadas;
	bool color; //TRUE = blancas; FALSE = negras
};

class Peon {
	Coords coordenadas;
	bool color; //TRUE = blancas; FALSE = negras
};