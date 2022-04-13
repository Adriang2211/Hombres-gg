#pragma once
#include "Posicionamiento.h"
#include "Piezas.h"

/*Clase que deber� tener acceso a las posiciones de todas las piezas.
* Esta clase se encarga de:
*		- Detectar cu�les son los movimientos posibles de las piezas
*/


//Las funciones para detectar los movimientos posibles de cada pieza se llamar�n
// movimientos y aceptan como par�metro la pieza de la que se quieren conocer los movimientos
// Como no se hacen cambios sobre la pieza debe ser const


class Interacciones {
public:
	bool consultaBlancas(Coords& const coordenada); //Informa de si una casilla est� ocupada o no
	bool consultaNegras(Coords& const coordenada);
	Coords movimientos(Torre& const torre);//error de sintaxis: identificador torre no s� por que 
	Coords movimientos(Rey& const rey);
private:
	Coords casillas_ocupadas_blancas[16];
	Coords casillas_ocupadas_negras[16];
	//Falta por pensar dos cosas: qu� hacer cunado una pieza desaparezca y c�mo mantener actualizada la lista
};
