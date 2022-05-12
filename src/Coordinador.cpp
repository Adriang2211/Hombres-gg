#include "Coordinador.h"
#include "freeglut.h"
#include "ETSIDI.h"

Coordinador::Coordinador() {

	estado = INICIO;
	raton = PEDIR_COORDS;
	muevete = false;
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
		if (raton == COORDS_RECIBIDAS) {
			//METODO PARA DIBUJAR LAS CASILLAS DISPONIBLES EN UN COLOR DIFERENTE
		}
		else if (raton == PEDIR_COORDS) {
			//METODO DE DIBUJAR LA PARTIDA POR DEFECTO

		}
		
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

void Coordinador::tu_raton() {

	if (raton == PEDIR_COORDS) {
		if (tab.turno) {//turno blancas
			//solo es válido obtener una pieza blanca
			Coords aux = tab.mouseButton(); //obtengo coordenadas
			for (int i = 0; i < NUMERO_DE_PIEZAS / 2; i++) {
				if (tab.casillas_ocupadas_blancas[i] == aux) { //si en la casilla seleccionada hay pieza blanca
					mov = tab.getPiezaEn(aux); // nuestro puntero a pieza que se mueve corresponde con uno de la lista de piezas
					raton = COORDS_RECIBIDAS;
				}
			}

		}
		else {//turno negras
			//solo es válido obtener una pieza negra
			Coords aux = tab.mouseButton(); //obtengo coordenadas
			for (int i = 0; i < NUMERO_DE_PIEZAS / 2; i++) {
				if (tab.casillas_ocupadas_negras[i] == aux) { //si en la casilla seleccionada hay pieza negra
					mov = tab.getPiezaEn(aux); // nuestro puntero a pieza que se mueve corresponde con uno de la lista de piezas
					raton = COORDS_RECIBIDAS;
				}
			}
		}
		
	}
	else if (raton == COORDS_RECIBIDAS) {//coordenadas recibidas
		//No es necesario hacer distincion entre color al que le toque jugar(la implementacion es la misma)
		bool verificador = true;//Sirve para que si pulsas fuera de las casillas disponibles, vuelvas al estado anterior de PEDIR_COORDS

		Coords aux = tab.mouseButton(); //obtengo coordenadas de raton
		mov->movimientos(); //Actualizamos la lista de movimientos disponibles por si acaso ////////////////////////////////////////////////////////////////////////////CONSULTAR GRUPO
		for (int i = 0; i < 27; i++) {//recorrer el vectcor de coordenadas disponibles
			if (mov->coordenadas_disponibles[i] == aux) {//si las Coords del raton concuerdan con alguna de las
				//coordenadas disponibles de la pieza apuntada por el puntero mov
				//Indicar que se puede y debe realizar el movimiento
				tab.setMov_siguiente(aux); //auctualizamos la casilla a la que se debe mover
				muevete = true; //autorizamos a que la pieza se mueva
				raton = PEDIR_COORDS; //cambiamos de estado del ratón a standby
				tab.cambiarTurno(); //cambiamos el turno
				verificador = false;
			}
		}
		if (verificador) {
			raton = PEDIR_COORDS;//si no se pulsó alguna de las casillas disponibles, volvemos al estado de standby
		}
		

	}
}

void Coordinador::te_mueves() {
	//tab.actualizarMovimientosPosibles();
	if ((estado == BATALLA && muevete) || (estado == MAQUINA && muevete)) {
		mov->mover(tab.getMov_siguiente()); 
	}
}