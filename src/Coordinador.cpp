#include "Coordinador.h"
#include "freeglut.h"
#include "ETSIDI.h"

Coordinador::Coordinador() {

	estado = INICIO;
}

void Coordinador::dibuja() {

	if (estado == INICIO) {
		gluLookAt(0, 10, 30, // posicion del ojo
			0.0, 10, 0.0, // hacia que punto mira (0,7.5,0) 
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("BIENVENIDO A NUESTRO AJEDREZ, INDIQUE LO QUE QUIERA HACER:", -19, 31);
		ETSIDI::printxy("HOMBRES GG", 15, 2);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -i- PARA CONSULTAR LAS INSTRUCCIONES", -12, 29);
		ETSIDI::printxy("PULSE LA TECLA -1- PARA INICIAR EL MODO BATALLA", -12, 28);
		ETSIDI::printxy("PULSE LA TECLA -2- PARA INICIAR EL MODO MAQUINA", -12, 27);
		ETSIDI::printxy("Adrian & Ignacio & Samuel & Joshua & Eloy", 2, 1);

	}
	else if (estado == INSTRUCCIONES) { //hay que escribir unas instrucciones

	}
	else if (estado == PREGUNTAS_BAT || estado == PREGUNTAS_MAQ) {
		gluLookAt(0, 10, 30, // posicion del ojo
			0.0, 10, 0.0, // hacia que punto mira (0,7.5,0) 
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("HOMBRES GG", 15, 2);
		ETSIDI::setTextColor(255, 0, 255);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 14);
		ETSIDI::printxy("SI QUIERE COMENZAR UNA NUEVA PARTIDA PULSE 1", -19, 31);
		ETSIDI::printxy("SI QUIERE CARGAR UNA PARTIDA GUARDADA PULSE 2", -19, 29);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("Adrian & Ignacio & Samuel & Joshua & Eloy", 2, 1);
	}
	else if (estado == BATALLA || estado == MAQUINA) {
		//METODO DIBUJA CORRESPONDIENTE DEL TALBERO
	}
	else if (estado == PAUSE) {
		//INTERFAZDE PAUSE
		gluLookAt(0, 10, 30, // posicion del ojo
			0.0, 10, 0.0, // hacia que punto mira (0,7.5,0) 
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 
		
		ETSIDI::setTextColor(0, 255, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 14);
		ETSIDI::printxy("MENU DE PAUSE", -19, 31);
		ETSIDI::setTextColor(255, 0, 255);
		ETSIDI::printxy("PULSE F SI QUIERE FINALIZAR EL JUEGO", -19, 29);
		ETSIDI::printxy("PULSE I SI QUIERE VOLVER AL INICIO", -19, 28);
		ETSIDI::printxy("PULSE G SI QUIERE GUARDAR Y FINALIZAR EL JUEGO", -19, 27);
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("HOMBRES GG", 15, 2);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("Adrian & Ignacio & Samuel & Joshua & Eloy", 2, 1);
	}
	else if (estado == FIN) {
		//estado final
		//INTERFAZDE PAUSE
		gluLookAt(0, 10, 30, // posicion del ojo
			0.0, 10, 0.0, // hacia que punto mira (0,7.5,0) 
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 

		ETSIDI::setTextColor(0, 255, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 14);
		ETSIDI::printxy("FIN DEL JUEGO", -19, 31);
		ETSIDI::setTextColor(255, 0, 255);
		ETSIDI::printxy("MUCHAS GRACIAS POR JUGAR", -19, 29);
		ETSIDI::printxy("QUE TENGA UN BUEN DIA", -19, 28);
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("HOMBRES GG", 15, 2);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("Adrian & Ignacio & Samuel & Joshua & Eloy", 2, 1);
	}
}

void Coordinador::tecla(unsigned char tecla) {

	if (estado == INICIO) {
		//INICILIZAR

		switch (tecla) {
			case 'i':
			case 'I':
				//Ir al estado de INSTRUCCIONES
				estado = INSTRUCCIONES;
				//Hay que hacer algo más?
				break;
			case '1':
				//Ir al estado de 1 vs 1
				estado = PREGUNTAS_BAT;
				//INICIALIZA
				break;
			case '2':///////////////////////////////////////////////////////////////
				//Ir al estado vs la máquina
				estado = PREGUNTAS_MAQ;
				//INICIALIZA
				break;
		}	
	}
	else if (estado == INSTRUCCIONES) {

		switch (tecla) {
			case 'i':
			case 'I':
				//Regresar al estado inicial
				estado = INICIO;
				///

				break;
			case 'f':
			case 'F':
				//Ir al final del todo
				estado = FIN;
				///

				break;
		}
	}
	else if (estado == PREGUNTAS_BAT) {

		switch (tecla) {
			case '1'://caso en el que hay que empezar una partida nueva
				estado = BATALLA;
				//INICIALIZACIÓN
				tab.inicializa();
				break;
			case '2':
				estado = BATALLA;
				//INICIALIZACIÓN
				tab.inicializa(true);

				break;
		}
	}
	else if (estado == PREGUNTAS_MAQ) {
		switch (tecla) {
		case '1'://caso en el que hay que empezar una partida nueva
			estado = MAQUINA;
			//INICIALIZACIÓN
			tab.inicializa();
			break;
		case '2':
			estado = MAQUINA;
			//INICIALIZACIÓN
			tab.inicializa(true);

			break;
		}
	}
	else if (estado == BATALLA) {
		if (tecla == 'p' || tecla == 'P') {
			estado = PAUSE;
		}
	}
	else if (estado == MAQUINA) {
		if (tecla == 'p' || tecla == 'P') {
			estado = PAUSE;
		}
	}
	else if (estado == PAUSE) {
		
		switch (tecla) {
			case 'f':
			case 'F':
				/////destruir lo que sea necesario
				estado = FIN;
				
				break;
			case 'i':
			case 'I':
				//destruir lo que sea necesario y volver al inicio
				estado = INICIO;

				break;
			case 'g':
			case 'G':
				/// tab.guardar();
				estado = GUARDADO;

		}
	}
	else if (estado == GUARDADO) {
		
		if (tecla == 'f' || tecla == 'F') {
			estado = FIN;
		}
	}

	else if (estado == FIN) {//el juego ha finalizado, cualquier tecla para finalizar
		//HAY QUE FINALIZAR EL JUEGO
		exit(1);
	}

}