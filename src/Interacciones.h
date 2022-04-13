#pragma once
#include "Posicionamiento.h"
#include "Piezas.h"

/*Clase que deberá tener acceso a las posiciones de todas las piezas.
* Esta clase se encarga de:
*		- Detectar cuáles son los movimientos posibles de las piezas
*/


//Las funciones para detectar los movimientos posibles de cada pieza se llamarán
// movimientos y aceptan como parámetro la pieza de la que se quieren conocer los movimientos
// Como no se hacen cambios sobre la pieza debe ser const


class Interacciones {
public:
	bool consultaBlancas(Coords& const coordenada); //Informa de si una casilla está ocupada o no
	bool consultaNegras(Coords& const coordenada);
	Coords movimientos(Torre& const torre);//error de sintaxis: identificador torre no sé por que 
	Coords movimientos(Rey& const rey);
private:
	Coords casillas_ocupadas_blancas[16];
	Coords casillas_ocupadas_negras[16];
	//Falta por pensar dos cosas: qué hacer cunado una pieza desaparezca y cómo mantener actualizada la lista
};
