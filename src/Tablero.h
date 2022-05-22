#pragma once
#include "Posicionamiento.h"
#include "Piezas.h"
#define NUMERO_DE_PIEZAS 32
#include "Torre.h"
#include "Rey.h"
#include "Caballo.h"
#include "ListaMovimientos.h"
#include "ListaPiezas.h"


class Tablero {
private:
	//Enroques
	bool enroque_largo_blancas();
	bool enroque_largo_negras();
	bool enroque_corto_blancas();
	bool enroque_corto_negras();

	//Declaracion de amistad para que puedan acceder a los metodos privados de enroque
	friend void Torre::movimientos();
	friend void Rey::movimientos();
	bool juego_Terminado;

	Coords mov_siguiente;



public: //Por ahora de forma temporal muchas cosas son publicas

	Tablero();

	bool turno;
	int jugada = 0;


	ListaPiezas lista_piezas;


	void dibuja(bool marca, Pieza * pieza, int opcion);
	void inicializa(bool guardado = false);
	void actualizarMovimientosPosibles();
	bool consultaBlancas(Coords const coordenada);
	bool consultaNegras(Coords const coordenada);
	bool consultaCasilla(Coords const coordenada); //Devuelve true si la casilla esta ocupada
	bool casillaAtacada(Coords const coordenada, bool color); //Comprueba si una casilla esta atacada por las piezas de un determinado
	//color en base a los movimientos posibles de las piezas de ese color que deben haber sido calculados previamente con el mÃ©todo
	//correspondiente.

	Pieza* getPiezaEn(Coords const coordenada) { return lista_piezas.getPiezaEn(coordenada); };
	int getIndexPiezaEn(Coords const coordenada) { return lista_piezas.getIndexPiezaEn(coordenada); };

	bool jaqueAlRey(bool color); //Detecta si el rey del color especificado esta en jaque
	bool jaqueMate(bool color); //Compreba si se produce jaque mate.

	Coords casillas_ocupadas_blancas[NUMERO_DE_PIEZAS/2];
	Coords casillas_ocupadas_negras[NUMERO_DE_PIEZAS/2];

	//Cambio de turno
	void cambiarTurno();

	//Actualizar vectores de casillas ocupadas
	void actualizarCasillasOcupadas();

	Coords getMov_siguiente();
	void setMov_siguiente(Coords coord);

	void borrarTab();

	//Función de prueba para mostrar en la consola la situación
	//friend std::ostream& operator << (std::ostream& os, const Tablero& tab);

	//Destructor
	~Tablero();


	//Test
	void generarTest(); //Genera una situacion de test correspondiente a una partida recien comenzada.


	//Calculo de movimientos posibles
	ListaMovimientos lista;
	void generarLista();

	//Calcular la puntuacion de un jugador
	int getPuntuacion(bool color);
	void guardarPartida(std::string p_guardada);

	void leerPartida(std::string p_guardada);

	bool detectarCoronar();
	void coronar(int opcion);
	void NombrePartidaCargar();
};