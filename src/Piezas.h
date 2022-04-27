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

};

class Torre:public Pieza {
	friend class Interacciones;
public:
	Coords coordenadas_disponibles[MAX_MOV_TORRE];
	//Sets y gets
};


class Caballo:public Pieza {
	friend class Interacciones;
private:
	int valor = 3;
public:
	//Sets y gets
	Coords coordenadas_disponibles[MAX_MOV_CABALLO];//8 son el numero maximo de movimientos disponibles que va a tener el caballo

};

class Alfil:public Pieza {
	friend class Interacciones;
private:
	Coords coordenadas;
	bool color; //True=blancas, flase = negras
public:
	//Sets y gets
	Coords coordenadas_disponibles[MAX_MOV_ALFIL];//13 son el numero maximo de movimientos disponibles que va a tener el alfil
};

class Dama:public Pieza {


};

class Rey:public Pieza {
	friend class Interacciones;
public:
	Coords coordenadas_disponibles[MAX_MOV_REY]; //El rey tendra 8 movimientos como maximo. 
};

class Peon:public pieza {
	friend class Interacciones;
public:
	bool primer_movimiento;
	Coords movimientos_posibles[MAX_MOV_PEON];
};
