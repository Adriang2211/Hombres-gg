#pragma once
#include "Posicionamiento.h"
#include "Piezas.h"
#define NUMERO_DE_PIEZAS 32
#include "Torre.h"
#include "Rey.h"
#include "Caballo.h"


/* SOBRE TABLERO
* Tablero es una clase que gestiona el dibujo del tablero y que gestiona



*/
class Tablero {
private:
	//Enroques
	bool enroque_largo_blancas();
	bool enroque_largo_negras();
	bool enroque_corto_blancas();
	bool enroque_corto_negras();
	//Declaraci�n de amistad para que puedan acceder a los m�todos privados de enroque
	friend void Torre::movimientos();
	friend void Rey::movimientos();
	bool juego_Terminado;

	Coords mov_siguiente;

public: //por ahora todo el p�blico

	Tablero();

	bool turno;
	int jugada = 0;


	int numero; //Numero de piezas que hay en cada momento
	Pieza* piezas [NUMERO_DE_PIEZAS];
	

	void dibuja();
	void inicializa(bool guardado = false);
	void actualizarMovimientosPosibles();
	bool consultaBlancas(Coords const coordenada);
	bool consultaNegras(Coords const coordenada);
	bool consultaCasilla(Coords const coordenada); //Devuelve true si la casilla est� ocupada
	Pieza* getPiezaEn(Coords const coordenada); //Devuelve la referenia la pieza que se encuentra en unas coordenadas dadas
	bool casillaAtacada(Coords const coordenada, bool color); //Comprueba si una casilla est� atacada por las piezas de un determinado
	//color en base a los movimientos posibles de las piezas de ese color que deben haber sido calculados previamente con el m�todo
	//correspondiente.
	bool jaqueAlRey(bool color); //Detecta si el rey del color especificado est� en jaque

	Coords casillas_ocupadas_blancas[NUMERO_DE_PIEZAS/2];
	Coords casillas_ocupadas_negras[NUMERO_DE_PIEZAS/2];

	//Cambio de turno
	void cambiarTurno();

	//Actualizar vectores de casillas ocupadas
	void actualizarCasillasOcupadas();////////////////////////////////////////////////////////////////////////////////////////DONDE SE LLAMA A ESTA FUNCION

	Coords getMov_siguiente();
	void setMov_siguiente(Coords coord);


	


	//Funci�n de prueba para mostrar en la consola la situaci�n
	friend std::ostream& operator << (std::ostream& os, const Tablero& tab);

	//Destructor
	~Tablero();


	//Test
	void generarTest(); //Genera una situaci�n de test correspondiente a una partida reci�n comenzada.

};