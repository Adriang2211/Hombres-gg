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
	Coords getCoordenadas();
	bool getColor();
	void setCoordenadas(int x, int y);
	void setCoordenadas(Coords a);
	void setColor(bool _color);
	Coords coordenadas_disponibles[27]; //Máximos movimientos de la dama, que es la pieza que más movimientos posibles puede tener.

	virtual void movimientos() const = 0; //Define la obligatoriedad de definir en todas las clases hijas la función de movimientos.
};



