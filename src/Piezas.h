#pragma once

/*
* En este archivo se crean las clases de cada una de las piezas.
* Previsiblemente se crear� una clase pieza que haciendo uso de hererncia
* agrupar� los aspectos comunes a todas las piezas.
*/

#include "Posicionamiento.h" //Incluye la clase para el uso del sistema de coordenadas
//#include "Interacciones.h" //Para declarla como amiga de todas las piezas

//M�ximo de movimientos posibles de cada pieza
#define MAX_MOV_TORRE 14 //No se suman dos para el enroque porque es imposible que tenga m�s de 10
//posibles movimientos en el mejor de los casos si el enroque todav�a es posible
#define MAX_MOV_CABALLO 8
#define MAX_MOV_ALFIL 13
#define MAX_MOV_PEON 4
#define MAX_MOV_REY 8 //No se incluye la posibilidad del enroque porque en ese caso hay m�ximo 7 movimientos
#define MAX_MOV_DAMA 27 //Alfil + torre

class Torre {
	friend class Interacciones;
private:
	Coords coordenadas;
	bool color; //True=blancas, flase = negras
public:
	Coords movimientos_posibles[MAX_MOV_TORRE];
	//Sets y gets
	
	Coords getCoordenadas() { return coordenadas; }
	bool getColor() { return color; }
	void setCoordenadas(int x, int y) { coordenadas.setXY(x, y); }
	void setCoordenadas(Coords a) { coordenadas = a; }
	void setColor(bool _color) { color = _color; }
};


class Caballo {
	friend class Interacciones;
private:
	Coords coordenadas;
	int valor = 3;
	bool color; //True=blancas, flase = negras
public:
	//Sets y gets
	Coords coordenadas_disponibles[8];//8 son el numero maximo de movimientos disponibles que va a tener el caballo
	Coords getCoordenadas() { return coordenadas; }
	bool getColor() { return color; }
	void setCoordenadas(int x, int y) { coordenadas.setXY(x, y); }
	void setCoordenadas(Coords a) { coordenadas = a; }
	void setColor(bool _color) { color = _color; };
};

class Alfil {
	friend class Interacciones;
private:
	Coords coordenadas;
	bool color; //True=blancas, flase = negras
public:
	//Sets y gets
	Coords coordenadas_disponibles[13];//13 son el numero maximo de movimientos disponibles que va a tener el alfil
	Coords getCoordenadas() { return coordenadas; }
	bool getColor() { return color; }
	void setCoordenadas(int x, int y) { coordenadas.setXY(x, y); }
	void setCoordenadas(Coords a) { coordenadas = a; }
	void setColor(bool _color) { color = _color; };
};

class Dama {
	Coords coordenadas;
	bool color;
};

class Rey {
	friend class Interacciones;
private:
	Coords coordenadas;
	bool color;//True=blancas y False=negras
public:
	Coords movimientos_disponibles[8]; //El rey tendra 8 movimientos como maximo. 
	Coords getCoordenadas() { return coordenadas; }
	bool getColor() { return color; }
	void setCoordenadas(int x, int y) { coordenadas.setXY(x, y); }
	void setCoordenadas(Coords a) { coordenadas = a; }
};

class Peon {
	Coords coordenadas;
	bool color;
};
