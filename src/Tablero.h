#pragma once
#include "Posicionamiento.h"
#include "Piezas.h"

class Tablero {
public: //por ahora todo el público
	//jugador blancas
	//jugador negras
	bool turno;
	int jugada = 0;
	Coords casillas_ocupadas_blancas[16];
	Coords casillas_ocupadas_negras[16];
	void dibuja(); //Sin implementar
	void inicializa(); //Sin implementar
	bool mover(Pieza& p, Coords coordenada); //Sin implementar
	void actualizarMovimientosPosibles(); //Sin implemetar
	bool consultaBlancas(Coords coordenada);
	bool consultaNegras(Coords coordenada);
};