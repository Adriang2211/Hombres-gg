#pragma once
#include "Posicionamiento.h"
#include "Piezas.h"
#define NUMERO_DE_PIEZAS 32

class Tablero {
public: //por ahora todo el público

	Tablero() { numero = 0; }

	bool turno;
	int jugada = 0;

	int numero; //Numero de piezas que hay en cada momento
	Pieza* piezas [NUMERO_DE_PIEZAS];

	void dibuja(); //Sin implementar
	void inicializa();
	void actualizarMovimientosPosibles(); //Sin implemetar
	bool consultaBlancas(Coords coordenada);
	bool consultaNegras(Coords coordenada);

	Coords casillas_ocupadas_blancas[NUMERO_DE_PIEZAS/2];
	Coords casillas_ocupadas_negras[NUMERO_DE_PIEZAS/2];

	//Cambio de turno
	void cambiarTurno();

	//Actualizar vectores de casillas ocupadas
	void actualizarCasillasOcupadas();


	//Enroques
	void enroque_largo_blancas();
	void enroque_largo_negras();
	void enroque_corto_blancas();
	void enroque_corto_negras();


	//Función de prueba para mostrar en la consola la situación
	friend std::ostream& operator << (std::ostream& os, const Tablero& tab);

	//Destructor
	~Tablero();
};