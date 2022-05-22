#pragma once
#include "Tablero.h"
#include "Piezas.h"
#include "AyudaTexto.h"
using namespace std;

class Coordinador {
private:
	enum Estado { INICIO, INSTRUCCIONES, PREGUNTAS_BAT,  BATALLA, PAUSE, GUARDADO, FIN, REND_BLANCO, REND_NEGRO, CORONAR,CARGAR, JAQUE_MATE };
	Estado estado;
	enum Raton {PEDIR_COORDS, COORDS_RECIBIDAS, DETENCION};
	Raton raton;
	Tablero tab;
	Pieza* mov;
	Coords malas;
	Coords aux;

	bool rendicion_blanco = false;
	bool rendicion_negro = false;

	bool habilitar_mate;
  
	int opcion;

public:
	Coordinador();
	Coords cell;//celda seleccionada por el raton
	void sacarcelda(int x, int y);//conversion coordenadas de la pantalla a coordeandas del tablero
	void dibuja();
	void setMate(bool op);

	void tecla(unsigned char tecla); //las usaremos para ´avanzar´ de estados
	void tu_raton(); //Funcion para la gestion de los turnos que se introducen por el raton
	int getopcion(){ return opcion; };
	void setopcion(int a) { opcion = a; }
	void NombrePartidaGuardar(); //poner nombre a la partida

};