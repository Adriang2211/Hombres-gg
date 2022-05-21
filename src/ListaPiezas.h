#pragma once
#include "Posicionamiento.h"
#include "Piezas.h"

#define NUMERO_DE_PIEZAS 32

class ListaPiezas {
private: //Las piezas son privadas
	int numero; //Numero de piezas que hay en cada momento

	Pieza* piezas[NUMERO_DE_PIEZAS];

public:
	//Para el acceso a miembro privados de la clase
	bool agregarPieza(Pieza* p);
	void eliminarPieza(int index);
	int getNumeroPiezas() { return numero; };
	Pieza* getPieza(int i) { return piezas[i]; };
	Pieza* getPiezaEn(Coords const coordenada); //Devuelve la referenia la pieza que se encuentra en unas coordenadas dadas
	int getIndexPiezaEn(Coords const coordenada); //Devuelve la posicion en el array que ocupa una pieza dada.
	void eliminar();
};