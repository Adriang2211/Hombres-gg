#pragma once
#include "Posicionamiento.h"
#include "Piezas.h"
#define NUMERO_DE_PIEZAS 32

class Tablero {
public: //por ahora todo el p�blico

	Tablero() { numero = 0; }

	bool turno;
	int jugada = 0;

	int numero; //Numero de piezas que hay en cada momento
	Pieza* piezas [NUMERO_DE_PIEZAS];

	void dibuja();
	void inicializa();
	void actualizarMovimientosPosibles();
	bool consultaBlancas(Coords coordenada);
	bool consultaNegras(Coords coordenada);
	bool consultaCasilla(Coords coordenada); //Devuelve true si la casilla est� ocupada

	Coords casillas_ocupadas_blancas[NUMERO_DE_PIEZAS/2];
	Coords casillas_ocupadas_negras[NUMERO_DE_PIEZAS/2];

	//Cambio de turno
	void cambiarTurno();

	//Actualizar vectores de casillas ocupadas
	void actualizarCasillasOcupadas();


	//Enroques
	bool enroque_largo_blancas();
	bool enroque_largo_negras();
	bool enroque_corto_blancas();
	bool enroque_corto_negras();


	//Funci�n de prueba para mostrar en la consola la situaci�n
	friend std::ostream& operator << (std::ostream& os, const Tablero& tab);

	//Destructor
	~Tablero();
};