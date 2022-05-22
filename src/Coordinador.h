#pragma once
#include "Tablero.h"
#include "Piezas.h"
#include "AyudaTexto.h"
using namespace std;

class Coordinador {
private:
	enum Estado { INICIO, INSTRUCCIONES, PREGUNTAS_BAT, PREGUNTAS_MAQ, BATALLA, MAQUINA, PAUSE, GUARDADO, FIN, REND_BLANCO, REND_NEGRO, CORONAR,CARGAR };

	Estado estado;
	enum Raton {PEDIR_COORDS, COORDS_RECIBIDAS};
	Raton raton;
	Tablero tab;
	Pieza* mov;
	bool muevete;
	Coords malas;
	bool seleccion; //si true, se ha seleccionado jugar 1vs1; false contra maquina

	bool rendicion_blanco = false;
	bool rendicion_negro = false;
  
	int opcion;

public:
	Coordinador();
	Coords cell;//celda seleccionada por el raton
	void sacarcelda(int x, int y);//conversion coordenadas de la pantalla a coordeandas del tablero
	void dibuja();

	void tecla(unsigned char tecla); //las usaremos para ´avanzar´ de estados
	void tu_raton(); //Comentado el cuerpo hasta que esté operativa la función del ratón.
	int getopcion(){ return opcion; };
	void setopcion(int a) { opcion = a; }
					 //void te_mueves();
	void NombrePartidaGuardar(); //poner nombre a la partida
	//cargar partida con nombre ""

	/*
	void tu_texto(string txt, int x, int y); //Escribir de izquierda a derecha
	void tu_print(const char* txt, float x, float y);
	*/
};