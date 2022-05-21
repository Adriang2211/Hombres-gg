#pragma once

#include "Posicionamiento.h" //Incluye la clase para el uso del sistema de coordenadas
#include "ETSIDI.h" //La incluimos aqui para no tener que ir poniendolo en cada archivo destinado a las clases hijas

//Maximo de movimientos posibles de una pieza cualquiera
#define MAX_MOV 27
#define MAX_MOV_PEON 4 //Se utiliza en movimientos peon

enum enum_piezas { TORRE = 1, CABALLO = 2, ALFIL = 3, DAMA = 4, REY = 5, PEON = 6};

class Tablero;

class Pieza {
protected:
	Coords coordenadas;
	bool color; //True=blancas, flase = negras
	Tablero* tab; //Tablero al que pertenece la pieza, de esta forma se evita tener que pasar la referencia del tablero.

public:
	int id; //Identifica el tipo de pieza. Se asigna valor en el constructor de cada clase de pieza
	//Los valores son: 1-Torre, 2-Caballo, 3-Alfil, 4-Dama, 5-Rey, 6-Peon
	Coords getCoordenadas();
	bool getColor();
	void setCoordenadas(int x, int y);
	void setCoordenadas(Coords a);
	void setColor(bool _color);
	Coords coordenadas_disponibles[27]; //Maximos movimientos de la dama, que es la pieza que mas movimientos posibles puede tener.

	virtual bool getPrimerMovimiento() { return false; };
	virtual bool mover(Coords destino);
	virtual void movimientos() {}; //Define la obligatoriedad de definir en todas las clases hijas la función de movimientos.
	virtual void dibuja(); //Metodo que hace que se dibujen las piezas.

	virtual int getValor() { return 0; };
};



