#include "Rey.h"
#include "Tablero.h"

Rey::Rey(bool color, int x, int y, Tablero* t) {
	this->color = color;
	coordenadas.setX(x);
	coordenadas.setY(y);
	tab = t;
	primer_movimiento = true;
	id = REY;
}


void Rey::movimientos() {
	//Limpieza del vector
	for (int i = 0; i < MAX_MOV; i++)
		coordenadas_disponibles[i] = { 9,9 };
	int var1 = 0, var2 = 0, var3 = 0, var4 = 0, var5 = 0, var6 = 0, var7 = 0, var8 = 0; //cada una de estas variables se usará para cada direccion en la que puede moverse el rey
	bool encontrado = false;
	Coords coordenadas_de_consulta;
	//Movimiento hacia delante 
	if (coordenadas.getY() == 8) {
		var1 = 0; //si el rey esta en y=8, no tiene posibilidad de moverse una casilla delante
	}
	else {
		coordenadas_de_consulta.setXY(coordenadas.getX(), coordenadas.getY() + 1);
		if (getColor() && tab->consultaBlancas(coordenadas_de_consulta) && !encontrado) { //si nuestro rey es blanco, y hay una pieza blanca delante, no puede moverse en esa direccion
			encontrado = true;
			var1 = 0;
		}
		else if (!getColor() && tab->consultaNegras(coordenadas_de_consulta) && !encontrado) { //si nuestro rey es negro, y hay una peiza negra delante, no puede moverse en esa direccion
			encontrado = true;
			var1 = 0;

		}

		if (getColor() && tab->consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var1 = 1; //si nuestro rey es blanco, y hay una pieza negra delante, podemos movernos en esa direccion comiendonos a esa pieza
		}
		else if (!getColor() && tab->consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var1 = 1; //si nuestro rey es negro, y hay una pieza blanca delante, podemos movernos en esa direccion comiendonos a esa pieza 
		}

		if (!encontrado) {
			var1 = 1;//si no hay nada delante, podemos movernos en esa direccion
		}
	}

	encontrado = false; //ponemos la variable encontrado a false para la comprobacion en la siguiente direccion
	//Movimiento hacia atras
	if (coordenadas.getY() == 1) {
		var2 = 0;
	}
	else {
		coordenadas_de_consulta.setXY(coordenadas.getX(), coordenadas.getY() - 1);
		if (getColor() && tab->consultaBlancas(coordenadas_de_consulta) && !encontrado) { //si nuestro rey es blanco, y hay una pieza blanca detras, no puede moverse en esa direccion
			encontrado = true;
			var2 = 0;
		}
		else if (!getColor() && tab->consultaNegras(coordenadas_de_consulta) && !encontrado) { //si nuestro rey es negro, y hay una peiza negra detras, no puede moverse en esa direccion
			encontrado = true;
			var2 = 0;

		}

		if (getColor() && tab->consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var2 = 1; //si nuestro rey es blanco, y hay una pieza negra detras, podemos movernos en esa direccion comiendonos a esa pieza
		}
		else if (!getColor() && tab->consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var2 = 1;//si nuestro rey es negro, y hay una pieza blanca detras, podemos movernos en esa direccion comiendonos a esa pieza
		}

		if (!encontrado) {
			var2 = 1;//si no hay nada detras, podemos movernos en esa direccion
		}
	}
	encontrado = false;
	//Movimiento hacia la derecha
	if (coordenadas.getX() == 8) {
		var3 = 0;
	}
	else {
		coordenadas_de_consulta.setXY(coordenadas.getX() + 1, coordenadas.getY());
		if (getColor() && tab->consultaBlancas(coordenadas_de_consulta) && !encontrado) { //si nuestro rey es blanco, y hay una pieza blanca a su derecha, no puede moverse en esa direccion
			encontrado = true;
			var3 = 0;
		}
		else if (!getColor() && tab->consultaNegras(coordenadas_de_consulta) && !encontrado) { //si nuestro rey es negro, y hay una pieza negra a su derecha, no puede moverse en esa direccion
			encontrado = true;
			var3 = 0;

		}

		if (getColor() && tab->consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var3 = 1; //si nuestro rey es blanco, y hay una pieza negra a su derecha, podemos movernos en esa direccion comiendonos a esa pieza
		}
		else if (!getColor() && tab->consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var3 = 1; //si nuestro rey es negro, y hay una pieza blanca a su derecha, podemos movernos en esa direccion comiendonos a esa pieza
		}

		if (!encontrado) {
			var3 = 1; //si no encontramos ninguna pieza a la derecha del rey, podemos movernos en esa direccion.
		}
	}

	encontrado = false;
	//Movimiento hacia la izquierda
	if (coordenadas.getX() == 1) {
		var4 = 0;
	}
	else {
		coordenadas_de_consulta.setXY(coordenadas.getX() - 1, coordenadas.getY());
		if (getColor() && tab->consultaBlancas(coordenadas_de_consulta) && !encontrado) { //si nuestro rey es blanco, y hay una pieza blanca a su izquierda, no puede moverse en esa direccion
			encontrado = true;
			var4 = 0;
		}
		else if (!getColor() && tab->consultaNegras(coordenadas_de_consulta) && !encontrado) { //si nuestro rey es negro, y hay una pieza negra a su izquierda, no puede moverse en esa direccion
			encontrado = true;
			var4 = 0;

		}

		if (getColor() && tab->consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var4 = 1; //si nuestro rey es blanco, y hay una pieza negra a su izquierda, podemos movernos en esa direccion comiendonos a esa pieza
		}
		else if (!getColor() && tab->consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var4 = 1; //si nuestro rey es negro, y hay una pieza blanca a su izquierda, podemos movernos en esa direccion comiendonos a esa pieza
		}

		if (!encontrado) {
			var4 = 1; //si no encontramos ninguna pieza a la izquierda del rey, podemos movernos en esa direccion.
		}
	}

	encontrado = false;
	//Movimiento diagonal superior derecha
	if (coordenadas.getX() == 8 || coordenadas.getY() == 8) {
		var5 = 0;
	}
	else {
		coordenadas_de_consulta.setXY(coordenadas.getX() + 1, coordenadas.getY() + 1);
		if (getColor() && tab->consultaBlancas(coordenadas_de_consulta) && !encontrado) { //si nuestro rey es blanco, y hay una pieza blanca a su esquina superior derecha, no puede moverse en esa direccion
			encontrado = true;
			var5 = 0;
		}
		else if (!getColor() && tab->consultaNegras(coordenadas_de_consulta) && !encontrado) { //si nuestro rey es negro, y hay una pieza negra a su esquina superior derecha, no puede moverse en esa direccion
			encontrado = true;
			var5 = 0;

		}

		if (getColor() && tab->consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var5 = 1; //si nuestro rey es blanco, y hay una pieza negra a su esquina superior derecha, podemos movernos en esa direccion comiendonos a esa pieza
		}
		else if (!getColor() && tab->consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var5 = 1; //si nuestro rey es negro, y hay una pieza blanca a su esquina superior derecha, podemos movernos en esa direccion comiendonos a esa pieza
		}

		if (!encontrado) {
			var5 = 1; //si no encontramos ninguna pieza a la esquina superior derecha del rey, podemos movernos en esa direccion.
		}
	}
	encontrado = false;
	//Movimiento diagonal superior izquierda
	if (coordenadas.getX() == 1 || coordenadas.getY() == 8) {
		var6 = 0;
	}
	else {
		coordenadas_de_consulta.setXY(coordenadas.getX() - 1, coordenadas.getY() + 1);
		if (getColor() && tab->consultaBlancas(coordenadas_de_consulta) && !encontrado) { //si nuestro rey es blanco, y hay una pieza blanca a su esquina superior izquierda, no puede moverse en esa direccion
			encontrado = true;
			var6 = 0;
		}
		else if (!getColor() && tab->consultaNegras(coordenadas_de_consulta) && !encontrado) { //si nuestro rey es negro, y hay una pieza negra a su esquina superior izquierda, no puede moverse en esa direccion
			encontrado = true;
			var6 = 0;

		}

		if (getColor() && tab->consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var6 = 1; //si nuestro rey es blanco, y hay una pieza negra a su esquina superior izquierda, podemos movernos en esa direccion comiendonos a esa pieza
		}
		else if (!getColor() && tab->consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var6 = 1; //si nuestro rey es negro, y hay una pieza blanca a su esquina superior izquierda, podemos movernos en esa direccion comiendonos a esa pieza
		}

		if (!encontrado) {
			var6 = 1; //si no encontramos ninguna pieza a la esquina superior izquierda del rey, podemos movernos en esa direccion.
		}
	}
	encontrado = false;
	//Movimiento diagonal inferior derecha
	if (coordenadas.getX() == 8 || coordenadas.getY() == 1) {
		var7 = 0;
	}
	else {
		coordenadas_de_consulta.setXY(coordenadas.getX() + 1, coordenadas.getY() - 1);
		if (getColor() && tab->consultaBlancas(coordenadas_de_consulta) && !encontrado) { //si nuestro rey es blanco, y hay una pieza blanca a su esquina inferior derecha, no puede moverse en esa direccion
			encontrado = true;
			var7 = 0;
		}
		else if (!getColor() && tab->consultaNegras(coordenadas_de_consulta) && !encontrado) { //si nuestro rey es negro, y hay una pieza negra a su esquina inferior derecha, no puede moverse en esa direccion
			encontrado = true;
			var7 = 0;

		}

		if (getColor() && tab->consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var7 = 1; //si nuestro rey es blanco, y hay una pieza negra a su esquina inferior derecha, podemos movernos en esa direccion comiendonos a esa pieza
		}
		else if (!getColor() && tab->consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var7 = 1; //si nuestro rey es negro, y hay una pieza blanca a su esquina inferior derecha, podemos movernos en esa direccion comiendonos a esa pieza
		}

		if (!encontrado) {
			var7 = 1; //si no encontramos ninguna pieza a la esquina inferior derecha del rey, podemos movernos en esa direccion.
		}
	}
	encontrado = false;
	//Movimiento diagonal inferior izquierda
	if (coordenadas.getX() == 1 || coordenadas.getY() == 1) {
		var8 = 0;
	}
	else {
		coordenadas_de_consulta.setXY(coordenadas.getX() - 1, coordenadas.getY() - 1);
		if (getColor() && tab->consultaBlancas(coordenadas_de_consulta) && !encontrado) { //si nuestro rey es blanco, y hay una pieza blanca a su esquina inferior izquierda, no puede moverse en esa direccion
			encontrado = true;
			var8 = 0;
		}
		else if (!getColor() && tab->consultaNegras(coordenadas_de_consulta) && !encontrado) { //si nuestro rey es negro, y hay una pieza negra a su esquina inferior izquierda, no puede moverse en esa direccion
			encontrado = true;
			var8 = 0;

		}

		if (getColor() && tab->consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var8 = 1; //si nuestro rey es blanco, y hay una pieza negra a su esquina inferior izquierda, podemos movernos en esa direccion comiendonos a esa pieza
		}
		else if (!getColor() && tab->consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var8 = 1; //si nuestro rey es negro, y hay una pieza blanca a su esquina inferior izquierda, podemos movernos en esa direccion comiendonos a esa pieza
		}

		if (!encontrado) {
			var8 = 1; //si no encontramos ninguna pieza a la esquina inferior izquierda del rey, podemos movernos en esa direccion.
		}
	}
	encontrado = 0;
	//falta añadir algun tipo de restriccion en el movimiento en los casos de jaque.

	for (int i = 0; i < var1; i++) { //Movimientos hacia delante
		coordenadas_disponibles[i].setXY(coordenadas.getX(), coordenadas.getY() + 1);
	}
	for (int i = 0; i < var2; i++) { //Movimientos hacia atras
		coordenadas_disponibles[i + var1].setXY(coordenadas.getX(), coordenadas.getY() - 1);
	}
	for (int i = 0; i < var3; i++) {
		coordenadas_disponibles[i + var1 + var2].setXY(coordenadas.getX() + 1, coordenadas.getY());
	}
	for (int i = 0; i < var4; i++) {
		coordenadas_disponibles[i + var1 + var2+var3].setXY(coordenadas.getX() - 1, coordenadas.getY());
	}
	for (int i = 0; i < var5; i++) {
		coordenadas_disponibles[i + var1 + var2 + var3+var4].setXY(coordenadas.getX() + 1, coordenadas.getY()+1);
	}
	for (int i = 0; i < var6; i++) {
		coordenadas_disponibles[i + var1 + var2 + var3 + var4+var5].setXY(coordenadas.getX() - 1, coordenadas.getY() + 1);
	}
	for (int i = 0; i < var7; i++) {
		coordenadas_disponibles[i + var1 + var2 + var3 + var4 + var5+var6].setXY(coordenadas.getX() + 1, coordenadas.getY() - 1);
	}
	for (int i = 0; i < var8; i++) {
		coordenadas_disponibles[i + var1 + var2 + var3 + var4 + var5 + var6+var7].setXY(coordenadas.getX() -1, coordenadas.getY() - 1);
	}

	//Enroques
	if (color) {
		if (tab->enroque_corto_blancas()) {
			var4++;
			coordenadas_disponibles[var1 + var2 + var3 + var4] = { g, 1 };
		}
		if (tab->enroque_largo_blancas()) {
			var4++;
			coordenadas_disponibles[var1 + var2 + var3 + var4] = { c, 1 };
		}
	}
	else if (!color) {
		if (tab->enroque_corto_negras()) {
			var4++;
			coordenadas_disponibles[var1 + var2 + var3 + var4] = { g, 8 };
		}
		if (tab->enroque_largo_negras()) {
			var4++;
			coordenadas_disponibles[var1 + var2 + var3 + var4] = { c, 8 };
		}
	}
}



bool Rey::mover(Coords destino) {
	if (!Pieza::mover(destino))
		return false;
	if (primer_movimiento)
		primer_movimiento = false;
	return true;
}

void Rey::dibuja() {
	if (color == true) {
		reyBlancas.setCenter(-coordenadas.getX()+1, -coordenadas.getY()+1);
		reyBlancas.setSize(1, 1);
		reyBlancas.draw();
	}
	else {
		reyNegras.setCenter(-coordenadas.getX()+1, -coordenadas.getY()+1);
		reyNegras.setSize(1, 1);
		reyNegras.draw();
	}
	
}