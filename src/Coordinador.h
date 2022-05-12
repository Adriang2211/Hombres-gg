#pragma once
#include "Tablero.h"

class Coordinador {
private:
	enum Estado {INICIO, INSTRUCCIONES, PREGUNTAS_BAT, PREGUNTAS_MAQ, BATALLA, MAQUINA, PAUSE, GUARDADO, FIN};
	Estado estado;
	Tablero tab;

public:
	Coordinador();
	void dibuja();
	void tecla(unsigned char tecla); //las usaremos para ´avanzar´ de estados

};