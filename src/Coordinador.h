#pragma once
#include "Tablero.h"
#include "Piezas.h"

class Coordinador {
private:
	enum Estado {INICIO, INSTRUCCIONES, PREGUNTAS_BAT, PREGUNTAS_MAQ, BATALLA, MAQUINA, PAUSE, GUARDADO, FIN};
	Estado estado;
	enum Raton {PEDIR_COORDS, COORDS_RECIBIDAS};
	Raton raton;
	Tablero tab;
	Pieza* mov;
	bool muevete;

public:
	Coordinador();
	void dibuja();
	void tecla(unsigned char tecla); //las usaremos para ´avanzar´ de estados
	void tu_raton(); //Comentado el cuerpo hasta que esté operativa la función del ratón.
	void te_mueves();

};