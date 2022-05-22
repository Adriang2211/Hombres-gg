#include "Caballo.h"
#include "Tablero.h"

Caballo::Caballo(bool color, int x, int y, Tablero* t) {
	this->color = color;
	coordenadas.setX(x);
	coordenadas.setY(y);
	tab = t;
	id = CABALLO;
	caballoBlancas.setCenter(x, y);
	caballoNegras.setCenter(x, y);
}

void Caballo::movimientos() {
	//Limpieza del vector
	for (int i = 0; i < MAX_MOV; i++)
		coordenadas_disponibles[i] = { 9,9 };
	Coords coordenadas_de_consulta;
	Coords coordenadas_inservibles = { 9, 9 };
	//Se recomienda ver la imagen del modelo para entender la estuctura de la funcion
	//arriba
	coordenadas_de_consulta.setY(coordenadas.getY() + 2);  //Sube dos posiciones
		//izq
	coordenadas_de_consulta.setX(coordenadas.getX() - 1); //Nos movemos uno a la izq (casilla modelo 1)
	if (coordenadas_de_consulta.getY() > 8 || coordenadas_de_consulta.getX() < 1) {//Si me salgo por arriba o por la izquierda
		//significa que no es un movimiento disponible y en el espacio del vector ponemos algo especial//conocido
		coordenadas_disponibles[0] = coordenadas_inservibles;
	}
	else {//Si no me salgo por arriba o por la izquierda
		//significa que puede ser un movimiento disponible, dependiendo de si en la casilla hay un amigo o no
		tuPetitInteraccion(coordenadas_de_consulta, coordenadas_inservibles, 0);
	}

	//derecha
	coordenadas_de_consulta.setX(coordenadas_de_consulta.getX() + 2); //Nos movemos 2 casillas a la derecha (casilla modelo 2)
	if (coordenadas_de_consulta.getY() > 8 || coordenadas_de_consulta.getX() > 8) {//Si me salgo por arriba o por la derecha
		//significa que no es un movimiento disponible y en el espacio del vector ponemos algo especial//conocido
		coordenadas_disponibles[1] = coordenadas_inservibles;
	}
	else {//Si no me salgo por arriba o por la derecha
		//significa que puede ser un movimiento disponible, dependiendo de si en la casilla hay un amigo o no
		tuPetitInteraccion(coordenadas_de_consulta, coordenadas_inservibles, 1);
	}

	//derecha
		//arriba
	coordenadas_de_consulta.setXY(coordenadas_de_consulta.getX() + 1, coordenadas_de_consulta.getY() - 1); //Nos movemos una a la derecha y una abajo(casilla modelo 3)
	if (coordenadas_de_consulta.getY() > 8 || coordenadas_de_consulta.getX() > 8) {//Si me salgo por arriba o por la derecha
		//significa que no es un movimiento disponible y en el espacio del vector ponemos algo especial//conocido
		coordenadas_disponibles[2] = coordenadas_inservibles;
	}
	else {//Si no me salgo por arriba o por la derecha
		//significa que puede ser un movimiento disponible, dependiendo de si en la casilla hay un amigo o no
		tuPetitInteraccion(coordenadas_de_consulta, coordenadas_inservibles, 2);
	}
	//abajo
	coordenadas_de_consulta.setY(coordenadas_de_consulta.getY() - 2); //Nos movemos 2 abajo (casilla modelo 4)
	if (coordenadas_de_consulta.getY() < 1 || coordenadas_de_consulta.getX() > 8) {//Si me salgo por abajo o por la derecha
		//significa que no es un movimiento disponible y en el espacio del vector ponemos algo especial//conocido
		coordenadas_disponibles[3] = coordenadas_inservibles;
	}
	else {//Si no me salgo por abajo o por la derecha
		//significa que puede ser un movimiento disponible, dependiendo de si en la casilla hay un amigo o no
		tuPetitInteraccion(coordenadas_de_consulta, coordenadas_inservibles, 3);
	}

	//abajo
		//derecha
	coordenadas_de_consulta.setXY(coordenadas_de_consulta.getX() - 1, coordenadas_de_consulta.getY() - 1);//Nos movemos uno a la izq y uno abajo(casilla modelo 5)
	if (coordenadas_de_consulta.getY() < 1 || coordenadas_de_consulta.getX() > 8) {//Si me salgo por abajo o por la derecha
		//significa que no es un movimiento disponible y en el espacio del vector ponemos algo especial//conocido
		coordenadas_disponibles[4] = coordenadas_inservibles;
	}
	else {//Si no me salgo por abajo o por la derecha
		//significa que puede ser un movimiento disponible, dependiendo de si en la casilla hay un amigo o no
		tuPetitInteraccion(coordenadas_de_consulta, coordenadas_inservibles, 4);
	}

	//izquierda
	coordenadas_de_consulta.setX(coordenadas_de_consulta.getX() - 2); //Nos movemos 2 a la izq, (casilla modelo 6)
	if (coordenadas_de_consulta.getY() < 1 || coordenadas_de_consulta.getX() < 1) {//Si me salgo por abajo o por la izquierda
		//significa que no es un movimiento disponible y en el espacio del vector ponemos algo especial//conocido
		coordenadas_disponibles[5] = coordenadas_inservibles;
	}
	else {//Si no me salgo por abajo o por la izquierda
		//significa que puede ser un movimiento disponible, dependiendo de si en la casilla hay un amigo o no
		tuPetitInteraccion(coordenadas_de_consulta, coordenadas_inservibles, 5);
	}

	//izquierda
		//abajo
	coordenadas_de_consulta.setXY(coordenadas_de_consulta.getX() - 1, coordenadas_de_consulta.getY() + 1);//Nos movemos 1 a la izq y 1 arriba(casilla modelo 7)
	if (coordenadas_de_consulta.getY() < 1 || coordenadas_de_consulta.getX() < 1) {//Si me salgo por abajo o por la izquierda
		//significa que no es un movimiento disponible y en el espacio del vector ponemos algo especial//conocido
		coordenadas_disponibles[6] = coordenadas_inservibles;
	}
	else {//Si no me salgo por abajo o por la izquierda
		//significa que puede ser un movimiento disponible, dependiendo de si en la casilla hay un amigo o no
		tuPetitInteraccion(coordenadas_de_consulta, coordenadas_inservibles, 6);
	}

	//arriba
	coordenadas_de_consulta.setY(coordenadas_de_consulta.getY() + 2);//Nos movemos 2 arriba (casilla modelo 8)
	if (coordenadas_de_consulta.getY() > 8 || coordenadas_de_consulta.getX() < 1) {//Si me salgo por arriba o por la izquierda
		//significa que no es un movimiento disponible y en el espacio del vector ponemos algo especial//conocido
		coordenadas_disponibles[7] = coordenadas_inservibles;
	}
	else {//Si no me salgo por arriba o por la izquierda
		//significa que puede ser un movimiento disponible, dependiendo de si en la casilla hay un amigo o no
		tuPetitInteraccion(coordenadas_de_consulta, coordenadas_inservibles, 7);
	}
}

void Caballo::tuPetitInteraccion(Coords coordenadas_de_consulta, Coords coordenadas_inservibles, int i) {

	if (getColor() == true) { //si el caballo es blanco
		if (tab->consultaBlancas(coordenadas_de_consulta) == true) {	//Si ya habia una pieza blanca(aliada) en la casilla
			//significa que no es un movimiento disponible y en el espacio del vector ponemos algo especial//conocido
			coordenadas_disponibles[i] = coordenadas_inservibles;
		}
		else {//Si no habia una pieza blanca en la casilla(vacia o pieza negra)
			//significa que es un movimiento disponible, y lo incluimos en el vector
			coordenadas_disponibles[i] = coordenadas_de_consulta;
		}
	}
	else { //si el caballo es negro
		if (tab->consultaNegras(coordenadas_de_consulta) == true) {	//Si ya habia una pieza negra(aliada) en la casilla
			//significa que no es un movimiento disponible y en el espacio del vector ponemos algo especial//conocido
			coordenadas_disponibles[i] = coordenadas_inservibles;
		}
		else {//Si no habia una pieza negra en la casilla(vacia o pieza blanca)
			//significa que es un movimiento disponible, y lo incluimos en el vector
			coordenadas_disponibles[i] = coordenadas_de_consulta;
		}
	}

}


void Caballo::dibuja(int opc) {
	if (opc == 0)
	{

		if (color == true) {
			caballoBlancas.setCenter(-coordenadas.getX() + 1, -coordenadas.getY() + 1);
			caballoBlancas.setSize(1, 1);
			caballoBlancas.draw();
		}
		else {
			caballoNegras.setCenter(-coordenadas.getX() + 1, -coordenadas.getY() + 1);
			caballoNegras.setSize(1, 1);
			caballoNegras.draw();
		}
	}
	else if (opc == 1)
	{
		if (color == false) {
			caballoDorado.setCenter(-coordenadas.getX() + 1, -coordenadas.getY() + 1);
			caballoDorado.setSize(1, 1);
			caballoDorado.draw();
		}
		else {
			caballoPlata.setCenter(-coordenadas.getX() + 1, -coordenadas.getY() + 1);
			caballoPlata.setSize(1, 1);
			caballoPlata.draw();
		}
	}

}