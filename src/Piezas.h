#pragma once

/*
* En este archivo se crean las clases de cada una de las piezas.
* Previsiblemente se creará una clase pieza que haciendo uso de hererncia
* agrupará los aspectos comunes a todas las piezas.
*/

#include "Posicionamiento.h" //Incluye la clase para el uso del sistema de coordenadas
//#include "Interacciones.h" //Para declarla como amiga de todas las piezas

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

class Pieza {
protected:
	Coords coordenadas;
	bool color; //True=blancas, flase = negras
public:

	Coords getCoordenadas() { return coordenadas; }
	bool getColor() { return color; }
	void setCoordenadas(int x, int y) { coordenadas.setXY(x, y); }
	void setCoordenadas(Coords a) { coordenadas = a; }
	void setColor(bool _color) { color = _color; }
	Coords coordenadas_disponibles[27]; //Máximos movimientos de la dama, que es la pieza que más movimientos posibles puede tener.

};

class Torre:public Pieza {
	friend class Interacciones;
public:
	void movimientos();
};


class Caballo:public Pieza {
	friend class Interacciones;
private:
	int valor = 3;
public:
	
};

class Alfil:public Pieza {
	friend class Interacciones;
private:
	Coords coordenadas;
	bool color; //True=blancas, flase = negras
public:
	
};

class Dama:public Pieza {


};

class Rey:public Pieza {
	friend class Interacciones;
public:
	
};

class Peon:public Pieza {


};
