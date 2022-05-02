#pragma once

#include "Posicionamiento.h" //Incluye la clase para el uso del sistema de coordenadas

//Máximo de movimientos posibles de una pieza cualquiera
#define MAX_MOV 27
#define MAX_MOV_PEON 4 //Se utiliza en movimientos peon
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

	//virtual void movimientos(); //Define la obligatoriedad de definir en todas las clases hijas la función de movimientos.
};



