#pragma once
#include "Posicionamiento.h"
#include "Piezas.h"
#define NUMERO_DE_PIEZAS 32
#include "Torre.h"
#include "Rey.h"
#include "Caballo.h"


/* SOBRE TABLERO
* Tablero es una clase que gestiona el dibujo del tablero y que contiene las piezas en juego
* Las piezas no son est�ticas, es decir, puede haber m�ltiples tableros con m�ltiples piezas
* Esto �ltimo es �til si se quieren calcular posibles escenarios.
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

public: //Por ahora de forma temporal muchas cosas son publicas

	Tablero();

	bool turno;
	int jugada = 0;

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
	int getIndexPiezaEn(Coords const coordenada); //Devuelve la posici�n en el array que ocupa una pieza dada.


	void dibuja();
	void inicializa(bool guardado = false);
	void actualizarMovimientosPosibles();
	bool consultaBlancas(Coords const coordenada);
	bool consultaNegras(Coords const coordenada);
	bool consultaCasilla(Coords const coordenada); //Devuelve true si la casilla est� ocupada
	bool casillaAtacada(Coords const coordenada, bool color); //Comprueba si una casilla est� atacada por las piezas de un determinado
	//color en base a los movimientos posibles de las piezas de ese color que deben haber sido calculados previamente con el m�todo
	//correspondiente.
	bool jaqueAlRey(bool color); //Detecta si el rey del color especificado est� en jaque

	Coords casillas_ocupadas_blancas[NUMERO_DE_PIEZAS/2];
	Coords casillas_ocupadas_negras[NUMERO_DE_PIEZAS/2];

	//Cambio de turno
	void cambiarTurno();

	//Actualizar vectores de casillas ocupadas
	void actualizarCasillasOcupadas();

	Coords getMov_siguiente();
	void setMov_siguiente(Coords coord);


	


	//Funci�n de prueba para mostrar en la consola la situaci�n
	friend std::ostream& operator << (std::ostream& os, const Tablero& tab);

	//Destructor
	~Tablero();


	//Test
	void generarTest(); //Genera una situaci�n de test correspondiente a una partida reci�n comenzada.

};