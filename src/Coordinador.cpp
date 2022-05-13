#include "Coordinador.h"
#include "freeglut.h"
#include "ETSIDI.h"

Coordinador::Coordinador() {

	estado = INICIO;
	raton = PEDIR_COORDS;
	muevete = false;
}
void Coordinador::sacarcelda(int x, int y)
{
	cell.setX((int)(((x - 189) / 65) + 1));//las variables son x: pos x del click del mouse, 189, separacion a la izquierda tab-ventana, 65 ancho de casilla
	cell.setY((int)(((588 - y) / 53) + 1));//las variables son y: pos y del click del mouse, 588, separacion de arriba a la esquina inferior izqd del tablero, 65 ancho de casilla
	if (cell.getX() < 1 || cell.getY() > 8 || cell.getX() > 8 || cell.getY() < 1)
		cell.setXY(-1, -1);//por si selecciona fuera de lacelda
	//cout << "(" << cell.getX() << "," << cell.getY() << ")" << endl; //test realizado para comprobar por consola que la celda seleccionada es la correcta
}
void Coordinador::dibuja() {

	if (estado == INICIO) {
		gluLookAt(0, 10, 30, // posicion del ojo
			0.0, 10, 0.0, // hacia que punto mira (0,7.5,0) 
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("BIENVENIDO A NUESTRO AJEDREZ, INDIQUE LO QUE QUIERA HACER:", -19, 31);
		AyudaTexto::tu_texto("HOMBRES GG", 16, 2, 0.7);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -I- PARA CONSULTAR LAS INSTRUCCIONES", -12, 29);
		ETSIDI::printxy("PULSE LA TECLA -1- PARA INICIAR EL MODO BATALLA", -12, 28);
		ETSIDI::printxy("PULSE LA TECLA -2- PARA INICIAR EL MODO MAQUINA", -12, 27);
		ETSIDI::setTextColor(0, 255, 255);
		AyudaTexto::tu_texto("Adrian & Ignacio & Samuel & Joshua & Eloy", 16, 1, 0.4);//ADRIAN & IGNACIO & SAMUEL & JOSHUA & ELOY

	}
	else if (estado == INSTRUCCIONES) { //hay que escribir unas instrucciones
		gluLookAt(0, 10, 30, // posicion del ojo
			0.0, 10, 0.0, // hacia que punto mira (0,7.5,0) 
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("INSTRUCCIONES DEL AJEDREZ:", -13, 31);
		AyudaTexto::tu_texto("HOMBRES GG", 16, 2, 0.7);///////////////////////////////////////////////////////////////////////////////////////////
		//ETSIDI::printxy("HOMBRES GG", 11, 2);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("EL AJEDREZ ES UN JUEGO DE 1 CONTRA 1", -12, 29);
		ETSIDI::printxy("EL OBJETIVO ES ACABAR CON EL REY ENEMIGO", -12, 28);
		ETSIDI::printxy("PARA ELLO, CADA EQUIPO TIENE UNA SERIE DE TIPOS DE PIEZAS", -12, 27);
		ETSIDI::printxy("CADA TIPO DE PIEZA SE MUEVE DE FORMA DISTINTA", -12, 26);
		ETSIDI::printxy("UNA PIEZA NO SE PUEDE MOVER A LA CASILLA DE OTRA PIEZA DEL MISMO COLOR", -12, 25);
		ETSIDI::printxy("CUANNDO UNA PIEZA SE MUEVE A LA CASILLA DE OTRA PIEZA DE OTRO COLOR, SE LA COME", -12, 24);
		ETSIDI::setTextColor(0, 0, 204);
		ETSIDI::printxy("LOS DISTINTOS TIPOS DE PIEZAS SON:", -12, 23);
		ETSIDI::setTextColor(0, 255, 255);
		ETSIDI::printxy("-PEON", -12, 22);
		ETSIDI::printxy("-CABALLO", -12, 21);
		ETSIDI::printxy("-ALFIL", -12, 20);
		ETSIDI::printxy("-TORRE", -12, 19);
		ETSIDI::printxy("-DAMA", -12, 18);
		ETSIDI::printxy("-REY", -12, 17);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::printxy("PULSE LA TECLA -I- PARA VOLVER AL INICIO", -12, 16);
		ETSIDI::printxy("PULSE LA TECLA -F- PARA FINALIZAR EL PROGRAMA", -12, 15);
		ETSIDI::setTextColor(0, 255, 255);
		AyudaTexto::tu_texto("Adrian & Ignacio & Samuel & Joshua & Eloy", 16, 1, 0.4);
		//ETSIDI::printxy("Adrian & Ignacio & Samuel & Joshua & Eloy", 2, 1);//Adrian & Ignacio & Samuel & Joshua & Eloy
	}
	else if (estado == PREGUNTAS_BAT || estado == PREGUNTAS_MAQ) {
		gluLookAt(0, 10, 30, // posicion del ojo
			0.0, 10, 0.0, // hacia que punto mira (0,7.5,0) 
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		AyudaTexto::tu_texto("HOMBRES GG", 16, 2, 0.7);
		//ETSIDI::printxy("HOMBRES GG", 15, 2);
		ETSIDI::setTextColor(0, 255, 128);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 14);
		ETSIDI::printxy("SI QUIERE COMENZAR UNA NUEVA PARTIDA PULSE 1", -10, 29);
		ETSIDI::printxy("SI QUIERE CARGAR UNA PARTIDA GUARDADA PULSE 2", -10, 28);
		ETSIDI::printxy("PULSE LA TECLA -I- PARA VOLVER AL INICIO", -10, 27);
		ETSIDI::setTextColor(0, 255, 255);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		AyudaTexto::tu_texto("Adrian & Ignacio & Samuel & Joshua & Eloy", 16, 1, 0.4);
		//ETSIDI::printxy("Adrian & Ignacio & Samuel & Joshua & Eloy", 2, 1);
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
		ETSIDI::printxy("PULSE F SI QUIERE FINALIZAR EL JUEGO", -10, 29);
		ETSIDI::printxy("PULSE I SI QUIERE VOLVER AL INICIO", -10, 28);
		ETSIDI::printxy("PULSE G SI QUIERE GUARDAR Y FINALIZAR EL JUEGO", -10, 27);
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		AyudaTexto::tu_texto("HOMBRES GG", 16, 2, 0.7);
		//ETSIDI::printxy("HOMBRES GG", 15, 2);
		ETSIDI::setTextColor(0, 255, 255);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		AyudaTexto::tu_texto("Adrian & Ignacio & Samuel & Joshua & Eloy", 16, 1, 0.4);
		//ETSIDI::printxy("Adrian & Ignacio & Samuel & Joshua & Eloy", 2, 1);
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
		AyudaTexto::tu_texto("HOMBRES GG", 16, 2, 0.7);
		//ETSIDI::printxy("HOMBRES GG", 15, 2);
		ETSIDI::setTextColor(0, 255, 255);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		AyudaTexto::tu_texto("Adrian & Ignacio & Samuel & Joshua & Eloy", 16, 1, 0.4);
		//ETSIDI::printxy("Adrian & Ignacio & Samuel & Joshua & Eloy", 2, 1);
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
			case 'i':
			case 'I':
				//Regresar al estado inicial
				estado = INICIO;
				///

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
		case 'i':
		case 'I':
			//Regresar al estado inicial
			estado = INICIO;
			///

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

//ANULADO TEMPORALMENTE HASTA QUE ESTÉ PROGRAMADA LA FUNCIÓN DEL RATÓN
//para que mientras tanto el programa siga compilando.
/*
void Coordinador::tu_raton() {

	if (estado == BATALLA) {
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
}
*/

void Coordinador::te_mueves() {
	//tab.actualizarMovimientosPosibles();
	if ((estado == BATALLA && muevete) || (estado == MAQUINA && muevete)) {
		mov->mover(tab.getMov_siguiente()); 
	}
}


/*
void Coordinador::tu_texto(string txt, int x, int y) {

	int i = txt.length(); //almacenamos en i la longitud de la cadena
	//ahora hay que darle la vuelta
	string reves(txt);//le asignamos el texto a una nueva string que se llama reves
	reverse(reves.begin(), reves.end()); //le damos la vuelta
	float separacion = 0.65;
	for (int n = 0; n < i; n++) {
		string aux;
		aux = reves[n];
		const char* texto = aux.c_str();
		tu_print(texto, x - (n * separacion), y);
		
	}

}

void Coordinador::tu_print(const char* txt, float x, float y) {

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glTranslated(x, y, 0);
	ETSIDI::print(txt);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glPopMatrix();
}*/