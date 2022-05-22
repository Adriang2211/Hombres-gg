#include "Coordinador.h"
#include "freeglut.h"
#include "ETSIDI.h"

Coordinador::Coordinador() {

	estado = INICIO;
	raton = PEDIR_COORDS;
	cell = {-1, -1};
	muevete = false;
	malas = {-1, -1};
	ETSIDI::playMusica("sonidos/ambiente.wav", true);
	opcion = 0;
}
void Coordinador::sacarcelda(int x, int y)
{
	Coords r_1 = {1, 10};
	Coords r_2 = { 8, 10 };
	cell.setX((int)(((x - 190) / 65) + 1));//las variables son x: pos x del click del mouse, 189, separacion a la izquierda tab-ventana, 65 ancho de casilla
	cell.setY((int)(((709 - y) / 65) + 1));//las variables son y: pos y del click del mouse, 588, separacion de arriba a la esquina inferior izqd del tablero, 65 ancho de casilla
	
	if (cell.getXY() == r_1 && tab.turno == true)
		rendicion_blanco = true;
	if (cell.getXY() == r_2 && tab.turno == false)
		rendicion_negro = true;
		
	
	if ((cell.getX() < 1 || cell.getY() > 8 || cell.getX() > 8 || cell.getY() < 1)) 
		cell.setXY(-1, -1);//por si selecciona fuera de lacelda
	cout << "(" << cell.getX() << "," << cell.getY() << ")" << endl; //test realizado para comprobar por consola que la celda seleccionada es la correcta
}
void Coordinador::dibuja() {

	if (estado == INICIO) {
		gluLookAt(0, 10, 30, // posicion del ojo
			0.0, 10, 0.0, // hacia que punto mira (0,7.5,0) 
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Rubik-Regular.ttf", 16);
		ETSIDI::printxy("BIENVENIDO A NUESTRO AJEDREZ, INDIQUE LO QUE QUIERA HACER:", -19, 31);
		AyudaTexto::tu_texto("HOMBRES GG", 16, 2, 0.7);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Rubik-Regular.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -i- PARA CONSULTAR LAS INSTRUCCIONES", -12, 29);
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


		
		if (raton == PEDIR_COORDS) {
			tab.dibuja(false, mov, opcion);
		}
		else if (raton == COORDS_RECIBIDAS) {
			tab.dibuja(true, mov, opcion);
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
		ETSIDI::printxy("PULSE R SI QUIERE VOLVER AL JUEGO", -10, 29);
		ETSIDI::printxy("PULSE F SI QUIERE FINALIZAR EL JUEGO", -10, 28);
		ETSIDI::printxy("PULSE I SI QUIERE VOLVER AL INICIO", -10, 27);
		ETSIDI::printxy("PULSE G SI QUIERE GUARDAR Y FINALIZAR EL JUEGO", -10, 26);
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

	else if (estado == REND_BLANCO) {//Los blancos se han rendido
		gluLookAt(0, 10, 30, // posicion del ojo
			0.0, 10, 0.0, // hacia que punto mira (0,7.5,0) 
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 

		ETSIDI::setTextColor(0, 255, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 14);
		ETSIDI::printxy("¡LAS BLANCAS SE HAN RENDIDO!", -10, 29);
		ETSIDI::printxy("ENHORABUENA NEGRAS", -10, 28);
		ETSIDI::printxy("NO TAN BIEN JUGADO BLANCAS.. ", -10, 27);
		ETSIDI::printxy("PULSE LA TECLA I PARA VOLVER AL MENU DE INICIO ", -10, 26);
		ETSIDI::printxy("PULSE F PARA FINALIZAR EL JUEGO", -10, 25);
		ETSIDI::setTextColor(255, 0, 255);
		ETSIDI::printxy("MUCHAS GRACIAS POR JUGAR", -10, 18);
		ETSIDI::printxy("QUE TENGA UN BUEN DIA", -10, 17);
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		AyudaTexto::tu_texto("HOMBRES GG", 16, 2, 0.7);
		//ETSIDI::printxy("HOMBRES GG", 15, 2);
		ETSIDI::setTextColor(0, 255, 255);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		AyudaTexto::tu_texto("Adrian & Ignacio & Samuel & Joshua & Eloy", 16, 1, 0.4);

	}
	else if (estado == REND_NEGRO) {
		gluLookAt(0, 10, 30, // posicion del ojo
			0.0, 10, 0.0, // hacia que punto mira (0,7.5,0) 
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 

		ETSIDI::setTextColor(0, 255, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 14);
		ETSIDI::printxy("¡LAS NEGRAS SE HAN RENDIDO!", -10, 29);
		ETSIDI::printxy("ENHORABUENA BLANCAS", -10, 28);
		ETSIDI::printxy("NO TAN BIEN JUGADO NEGRAS.. ", -10, 27);
		ETSIDI::printxy("PULSE LA TECLA I PARA VOLVER AL MENU DE INICIO ", -10, 26);
		ETSIDI::printxy("PULSE F PARA FINALIZAR EL JUEGO", -10, 25);
		ETSIDI::setTextColor(255, 0, 255);
		ETSIDI::printxy("MUCHAS GRACIAS POR JUGAR", -10, 18);
		ETSIDI::printxy("QUE TENGA UN BUEN DIA", -10, 17);
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		AyudaTexto::tu_texto("HOMBRES GG", 16, 2, 0.7);
		//ETSIDI::printxy("HOMBRES GG", 15, 2);
		ETSIDI::setTextColor(0, 255, 255);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		AyudaTexto::tu_texto("Adrian & Ignacio & Samuel & Joshua & Eloy", 16, 1, 0.4);

	}

	else if (estado == GUARDADO)
	{
		gluLookAt(0, 10, 30, // posicion del ojo
			0.0, 10, 0.0, // hacia que punto mira (0,7.5,0) 
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Rubik-Regular.ttf", 16);
		ETSIDI::printxy("PULSE G OTRA VEZ E INSERTE EN LA CONSOLA EL NOMBRE ", -10, 26);
		ETSIDI::printxy("DE LA PARTIDA QUE DESEA GUARDAR (SIN ESPACIOS)", -10, 25);
		ETSIDI::printxy("PULSE F PARA FINALIZAR", -10, 23);
	}
	else if (estado == CARGAR)
	{
		gluLookAt(0, 10, 30, // posicion del ojo
			0.0, 10, 0.0, // hacia que punto mira (0,7.5,0) 
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Rubik-Regular.ttf", 16);
		ETSIDI::printxy("PULSE 2 OTRA VEZ E INSERTE EN LA CONSOLA EL NOMBRE ", -10, 26);
		ETSIDI::printxy("DE LA PARTIDA QUE DESEA CARGAR (SIN ESPACIOS)", -10, 25);

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
				seleccion = true;
				//INICIALIZA
				break;
			case '2':///////////////////////////////////////////////////////////////
				//Ir al estado vs la máquina
				estado = PREGUNTAS_MAQ;
				seleccion = false;
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
				
				//INICIALIZACIÓN
				
				estado = CARGAR;
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
	else if (estado == CARGAR)
	{
		if (tecla == '2')
		{
			tab.inicializa(true);
			estado = BATALLA;
		}
	}
	else if (estado == BATALLA) {
		if (tecla == 'p' || tecla == 'P') {
			estado = PAUSE;
		}
		else if (tecla == '1') {
			setopcion(0);
		}
		else if (tecla == '2') {
			setopcion(1);
		}
	}
	else if (estado == MAQUINA) {
		if (tecla == 'p' || tecla == 'P') {
			estado = PAUSE;
		}
	}
	else if (estado == PAUSE) {
		
		switch (tecla) {
			case 'r':
			case 'R':
				//retornar a la partida
				if (seleccion) {
					estado = BATALLA;
				}
				else {
					estado = MAQUINA;
				}
				raton = PEDIR_COORDS;
				break;
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
				
				estado = GUARDADO;
				break;
		}
	}
	else if (estado == GUARDADO) {
	
	
		if (tecla == 'f' || tecla == 'F') {
			estado = FIN;
		}
		else if (tecla == 'g' || tecla == 'G')
		{
		NombrePartidaGuardar();
		}
	}
	else if (estado == REND_BLANCO || estado == REND_NEGRO) {
		if (tecla == 'I' || tecla == 'i') {//Volver al inicio
			estado = INICIO;
			rendicion_blanco = false;
			rendicion_negro = false;
			//borrar la partida anterior, de otra forma al volver a iniciar otra partida, continuariamos con aquella donde nos hemos rendido
			tab.borrarTab();
		}
		else if (tecla == 'F' || tecla == 'f') {//se para la ejecucion del programa
			exit(1);
		}
	}

	else if (estado == FIN) {//el juego ha finalizado, cualquier tecla para finalizar
		//HAY QUE FINALIZAR EL JUEGO
		exit(1);
	}
	else if (estado == CORONAR) {
		switch (tecla) {
			case 't':
			case 'T':
				tab.coronar(1);
				estado = BATALLA;
				break;
			case 'c':
			case 'C':
				tab.coronar(2);
				estado = BATALLA;
				break;
			case 'A':
			case 'a':
				tab.coronar(3);
				estado = BATALLA;
				break;
			case 'D':
			case 'd':
				tab.coronar(4);
				estado = BATALLA;
				break;
		}

	}

}


void Coordinador::tu_raton() {
	if (estado == BATALLA) {
		//cout << tab;
		if (raton == COORDS_RECIBIDAS) {//coordenadas recibidas
			//No es necesario hacer distincion entre color al que le toque jugar(la implementacion es la misma)
			
			cout << "listo para mover" << endl;
			Coords aux = cell; //obtengo coordenadas de raton
			if (cell.getXY() != malas) {

				cout << "coordenada:"<<cell.getXY() << endl;
				tab.actualizarCasillasOcupadas();
				tab.actualizarMovimientosPosibles();

				//mov->movimientos(); //Actualizamos la lista de movimientos disponibles por si acaso ////////////////////////////////////////////////////////////////////////////CONSULTAR GRUPO
				if (mov->mover(aux)) {//Si se puede mover la pieza a la casilla seleccionada, se mueve
					cout << "Movimiento seleccionado permitido, bien jugado" << endl;
					tab.cambiarTurno();

					raton = PEDIR_COORDS;//cambiamos el estado del raton
				}
				else {//Si la pieza no se puede mover a la casilla seleccionada
					raton = PEDIR_COORDS;
					cout << "Movimiento seleccionado no permitido y vuelta al estado de standby" << endl;
					ETSIDI::play("sonidos/error.wav"); //linea agregada
				}
				
			}

		}
		else if (raton == PEDIR_COORDS) {
			if (tab.turno) {//turno blancas
				//solo es válido obtener una pieza blanca
				Coords aux = cell; //obtengo coordenadas
				for (int i = 0; i < NUMERO_DE_PIEZAS / 2; i++) {
					if (tab.casillas_ocupadas_blancas[i] == aux) { //si en la casilla seleccionada hay pieza blanca
						mov = tab.getPiezaEn(aux); // nuestro puntero a pieza que se mueve corresponde con uno de la lista de piezas
						
						cout << cell.getXY() << endl;
						cout << "Coordenadas de pieza de mover blanca recibida" << endl;

						cell.setXY(-1,-1);
						raton = COORDS_RECIBIDAS;
					}
				}

			}
			else {//turno negras
				//solo es válido obtener una pieza negra
				Coords aux = cell; //obtengo coordenadas
				for (int i = 0; i < NUMERO_DE_PIEZAS / 2; i++) {
					if (tab.casillas_ocupadas_negras[i] == aux) { //si en la casilla seleccionada hay pieza negra
						mov = tab.getPiezaEn(aux); // nuestro puntero a pieza que se mueve corresponde con uno de la lista de piezas
						
						cout << "Coordenadas de pieza de mover negra recibida" << endl;
						cell.setXY(-1,-1);
						raton = COORDS_RECIBIDAS;
					}
				}


			}
		}

		
		//
		if (rendicion_blanco == true) {//los blancos se rinden
			estado = REND_BLANCO;
		}
		if (rendicion_negro == true) {//los negros se rinden
			estado = REND_NEGRO;
		}

		if (tab.detectarCoronar())
			estado = CORONAR;

	}
}
void Coordinador::NombrePartidaGuardar() {
	std::string nombrepartida;
	

	std::cout << "introduce el nombre de la partida sin espacios" << std::endl;
	std::cin >> nombrepartida;
	tab.guardarPartida(nombrepartida);
}