#pragma once

#include "Posicionamiento.h" //Incluye la clase para el uso del sistema de coordenadas

//Máximo de movimientos posibles de cada pieza
#define MAX_MOV_TORRE 14 //No se suman dos para el enroque porque es imposible que tenga más de 10
//posibles movimientos en el mejor de los casos si el enroque todavía es posible
#define MAX_MOV_CABALLO 8
#define MAX_MOV_ALFIL 13
#define MAX_MOV_PEON 4
#define MAX_MOV_REY 8 //No se incluye la posibilidad del enroque porque en ese caso hay máximo 7 movimientos
#define MAX_MOV_DAMA 27 //Alfil + torre

//Solo debe quedar esta constante
#define MAX_MOV 27 //Máximo de movimientos

class Tablero;

class Pieza {
protected:
	Coords coordenadas;
	bool color; //True=blancas, flase = negras
	Tablero* tab; //Tablero al que pertenece la pieza, de esta forma se evita tener que pasar la referencia del tablero.
public:
	Coords getCoordenadas() { return coordenadas; }
	bool getColor() { return color; }
	void setCoordenadas(int x, int y) { coordenadas.setXY(x, y); }
	void setCoordenadas(Coords a) { coordenadas = a; }
	void setColor(bool _color) { color = _color; }
	Coords coordenadas_disponibles[27]; //Máximos movimientos de la dama, que es la pieza que más movimientos posibles puede tener.

};




class Alfil:public Pieza {
public:
	static const int valor = 3;
	//Posible alternativa: valor 3.5, para diferenciarlo de la torre y que el programa sea más propenso a
	//conservar los alfiles en lugar de los caballos.
	void movimientos(); //Sin implementar
};

class Dama:public Pieza {
public:
	static const int valor = 9;
	void movimientos(); //Sin implementar
};

class Rey:public Pieza {
public:
	//El rey no tiene valor
	void movimientos(); //Sin implementar
};

class Peon:public Pieza {
public:
	bool primer_movimiento;
	static const int valor = 1;
	void movimientos(); //Sin implementar

};
