#include "Interacciones.h"
#include "Piezas.h"

bool Interacciones::consultaBlancas(Coords& const coordenada) {
	for (int i = 0; i < 16; i++) {
		//Busca la coordenada que se ha pasado en el vector de las piezas blancas
		if (casillas_ocupadas_blancas[i].getX() == coordenada.getX() && casillas_ocupadas_blancas[i].getY() == coordenada.getY())
			return true;
	}
	return false;
}

bool Interacciones::consultaNegras(Coords& const coordenada) {
	for (int i = 0; i < 16; i++) {
		//Busca la coordenada que se ha pasado en el vector de las piezas negras
		if (casillas_ocupadas_negras[i].getX() == coordenada.getX() && casillas_ocupadas_negras[i].getY() == coordenada.getY())
			return true;
	}
	return false;
}


void Interacciones::movimientos(Torre& torre) {
	int var1 = 0, var2 = 0, var3 = 0, var4 = 0; //Se definen tantas variables como direcciones de movimiento
	//posibles haya para la pieza. En el caso de la torre son 4 direcciones posibles.
	bool encontrado = false;
	Coords coordenadas_de_consulta;
	//Primero se comprueba dónde se encuentra la pieza más próxima en el semieje horizontal positivo
	for (int i = torre.coordenadas.getX() + 1; i <= 8; i++) {
		coordenadas_de_consulta.setXY(i, torre.coordenadas.getY());

		//Comprobaciones de si hay una pieza del mismo color
		if (torre.getColor() && consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var1 = i - torre.coordenadas.getX() - 1;
		}
		else if (!torre.getColor() && consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var1 = i - torre.coordenadas.getX() - 1;
		}

		//Comprobaciones de si hay una pieza de distinto color
		if (!torre.getColor() && consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var1 = i - torre.coordenadas.getX();
		}
		else if (torre.getColor() && consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var1 = i - torre.coordenadas.getX();
		}
	}
	if (!encontrado) //Si no encuentra ninguna pieza es el número de casillas hasta el borde
		var1 = 8 - torre.coordenadas.getX();

	encontrado = false; //Se prepara para la siguiente búsqueda
	//Se comprueba dónde se encuentra la pieza más próxima en el semieje horizontal negativo
	for (int i = torre.coordenadas.getX() - 1; i >= 1; i--) {
		coordenadas_de_consulta.setXY(i, torre.coordenadas.getY());

		//Comprobaciones de si hay una pieza del mismo color
		if (torre.getColor() && consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var2 = torre.coordenadas.getX() - i - 1;
		}
		else if (!torre.getColor() && consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var2 = torre.coordenadas.getX() - i - 1;
		}

		//Comprobaciones de si hay una pieza de distinto color
		if (!torre.getColor() && consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var2 = torre.coordenadas.getX() - i;
		}
		else if (torre.getColor() && consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var2 = i - torre.coordenadas.getX() - i;
		}
	}
	if (!encontrado)
		var2 = torre.coordenadas.getX() - 1;


	encontrado = false; //Se prepara para la siguiente búsqueda
	//Comprobación del semieje vertical positivo
	for (int i = torre.coordenadas.getY() + 1; i <= 8; i++) {
		coordenadas_de_consulta.setXY(torre.coordenadas.getX(), i);

		//Comprobaciones de si hay una pieza del mismo color
		if (torre.getColor() && consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var3 = i - torre.coordenadas.getY() - 1;
		}
		else if (!torre.getColor() && consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var3 = i - torre.coordenadas.getY() - 1;
		}

		//Comprobaciones de si hay una pieza de distinto color
		if (!torre.getColor() && consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var3 = i - torre.coordenadas.getY();
		}
		else if (torre.getColor() && consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var3 = i - torre.coordenadas.getY();
		}
	}
	if (!encontrado) //Si no encuentra ninguna pieza es el número de casillas hasta el borde
		var3 = 8 - torre.coordenadas.getY();


	encontrado = false; //Se prepara para la siguiente búsqueda
	//Se comprueba dónde se encuentra la pieza más próxima en el semieje vertical negativo
	for (int i = torre.coordenadas.getY() - 1; i >= 1; i--) {
		coordenadas_de_consulta.setXY(torre.coordenadas.getX(), i);

		//Comprobaciones de si hay una pieza del mismo color
		if (torre.getColor() && consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var4 = torre.coordenadas.getY() - i - 1;
		}
		else if (!torre.getColor() && consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var4 = torre.coordenadas.getY() - i - 1;
		}

		//Comprobaciones de si hay una pieza de distinto color
		if (!torre.getColor() && consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var4 = torre.coordenadas.getY() - i;
		}
		else if (torre.getColor() && consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var4 = i - torre.coordenadas.getY() - i;
		}
	}
	if (!encontrado)
		var4 = torre.coordenadas.getY() - 1;


	//Guardar las coordenadas de los posibles movimientos en el vector de movimientos posibles de la torre

	for (int i = 0; i < var1; i++) //Semieje horizontal positivo
		torre.movimientos_posibles[i].setXY(torre.coordenadas.getX() + i + 1, torre.coordenadas.getY());
	for (int i = 0; i < var2; i++) //Semieje horizontal negativo
		torre.movimientos_posibles[i + var1].setXY(torre.coordenadas.getX() - i - 1, torre.coordenadas.getY());
	for (int i = 0; i < var3; i++) //Semieje vertical positivo
		torre.movimientos_posibles[i + var1 + var2].setXY(torre.coordenadas.getX(), torre.coordenadas.getY() + i + 1);
	for (int i = 0; i < var4; i++) //Semieje vertical negativo
		torre.movimientos_posibles[i + var1 + var2 + var3].setXY(torre.coordenadas.getX(), torre.coordenadas.getY() - i - 1);
	for (int i = var1 + var2 + var3 + var4; i < MAX_MOV_TORRE; i++)
		torre.movimientos_posibles[i].setXY(9, 9); //9 como símbolo de que está vacío
}

Coords Interacciones::movimientos(Rey& const rey) {
	int var1 = 0, var2 = 0, var3 = 0, var4 = 0, var5 = 0, var6 = 0, var7 = 0, var8 = 0; //cada una de estas variables se usará para cada direccion en la que puede moverse el rey
	bool encontrado = false;
	Coords coordenadas_de_consulta;
	//Movimiento hacia delante 
	if (rey.coordenadas.getY() == 8) {
		var1 = 0; //si el rey esta en y=8, no tiene posibilidad de moverse una casilla delante
	}
	else {
		coordenadas_de_consulta.setXY(rey.coordenadas.getX(), rey.coordenadas.getY() + 1);
		if (rey.getColor() && consultaBlancas(coordenadas_de_consulta) && !encontrado) { //si nuestro rey es blanco, y hay una pieza blanca delante, no puede moverse en esa direccion
			encontrado = true;
			var1 = 0;
		}
		else if (!rey.getColor() && consultaNegras(coordenadas_de_consulta) && !encontrado) { //si nuestro rey es negro, y hay una peiza negra delante, no puede moverse en esa direccion
			encontrado = true;
			var1 = 0;

		}

		if (rey.getColor() && consultaNegras(coordenadas_de_consulta) && !encontrado) { 
			encontrado = true;
			var1 = 1; //si nuestro rey es blanco, y hay una pieza negra delante, podemos movernos en esa direccion comiendonos a esa pieza
		}
		else if (!rey.getColor() && consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var1 = 1; //si nuestro rey es negro, y hay una pieza blanca delante, podemos movernos en esa direccion comiendonos a esa pieza 
		}

		if (!encontrado) {
			var1 = 1;//si no hay nada delante, podemos movernos en esa direccion
		}
	}

	encontrado = false; //ponemos la variable encontrado a false para la comprobacion en la siguiente direccion
	//Movimiento hacia atras
	if (rey.coordenadas.getY() == 1) {
		var2 = 0;
	}
	else {
		coordenadas_de_consulta.setXY(rey.coordenadas.getX(), rey.coordenadas.getY() - 1);
		if (rey.getColor() && consultaBlancas(coordenadas_de_consulta) && !encontrado) { //si nuestro rey es blanco, y hay una pieza blanca detras, no puede moverse en esa direccion
			encontrado = true;
			var2 = 0;
		}
		else if (!rey.getColor() && consultaNegras(coordenadas_de_consulta) && !encontrado) { //si nuestro rey es negro, y hay una peiza negra detras, no puede moverse en esa direccion
			encontrado = true;
			var2 = 0;

		}

		if (rey.getColor() && consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var2 = 1; //si nuestro rey es blanco, y hay una pieza negra detras, podemos movernos en esa direccion comiendonos a esa pieza
		}
		else if (!rey.getColor() && consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var2 = 1;//si nuestro rey es negro, y hay una pieza blanca detras, podemos movernos en esa direccion comiendonos a esa pieza
		}

		if (!encontrado) {
			var2 = 1;//si no hay nada detras, podemos movernos en esa direccion
		}
	}
	encontrado = false;
	//Movimiento hacia la derecha
	if (rey.coordenadas.getX() == 8) {
		var3 = 0;
	}
	else {
		coordenadas_de_consulta.setXY(rey.coordenadas.getX() + 1, rey.coordenadas.getY());
		if (rey.getColor() && consultaBlancas(coordenadas_de_consulta) && !encontrado) { //si nuestro rey es blanco, y hay una pieza blanca a su derecha, no puede moverse en esa direccion
			encontrado = true;
			var3 = 0;
		}
		else if (!rey.getColor() && consultaNegras(coordenadas_de_consulta) && !encontrado) { //si nuestro rey es negro, y hay una pieza negra a su derecha, no puede moverse en esa direccion
			encontrado = true;
			var3 = 0;

		}

		if (rey.getColor() && consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var3 = 1; //si nuestro rey es blanco, y hay una pieza negra a su derecha, podemos movernos en esa direccion comiendonos a esa pieza
		}
		else if (!rey.getColor() && consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var3 = 1; //si nuestro rey es negro, y hay una pieza blanca a su derecha, podemos movernos en esa direccion comiendonos a esa pieza
		}

		if (!encontrado) {
			var3 = 1; //si no encontramos ninguna pieza a la derecha del rey, podemos movernos en esa direccion.
		}
	}

	encontrado = false;
	//Movimiento hacia la izquierda
	if (rey.coordenadas.getX() == 1) {
		var4 = 0;
	}
	else {
		coordenadas_de_consulta.setXY(rey.coordenadas.getX() - 1, rey.coordenadas.getY());
		if (rey.getColor() && consultaBlancas(coordenadas_de_consulta) && !encontrado) { //si nuestro rey es blanco, y hay una pieza blanca a su izquierda, no puede moverse en esa direccion
			encontrado = true;
			var4 = 0;
		}
		else if (!rey.getColor() && consultaNegras(coordenadas_de_consulta) && !encontrado) { //si nuestro rey es negro, y hay una pieza negra a su izquierda, no puede moverse en esa direccion
			encontrado = true;
			var4 = 0;

		}

		if (rey.getColor() && consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var4 = 1; //si nuestro rey es blanco, y hay una pieza negra a su izquierda, podemos movernos en esa direccion comiendonos a esa pieza
		}
		else if (!rey.getColor() && consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var4 = 1; //si nuestro rey es negro, y hay una pieza blanca a su izquierda, podemos movernos en esa direccion comiendonos a esa pieza
		}

		if (!encontrado) {
			var4 = 1; //si no encontramos ninguna pieza a la izquierda del rey, podemos movernos en esa direccion.
		}
	}

	encontrado = false;
	//Movimiento diagonal superior derecha
	if (rey.coordenadas.getX() == 8 || rey.coordenadas.getY() == 8) {
		var5 = 0;
	}
	else {
		coordenadas_de_consulta.setXY(rey.coordenadas.getX() + 1, rey.coordenadas.getY()+1);
		if (rey.getColor() && consultaBlancas(coordenadas_de_consulta) && !encontrado) { //si nuestro rey es blanco, y hay una pieza blanca a su esquina superior derecha, no puede moverse en esa direccion
			encontrado = true;
			var5 = 0;
		}
		else if (!rey.getColor() && consultaNegras(coordenadas_de_consulta) && !encontrado) { //si nuestro rey es negro, y hay una pieza negra a su esquina superior derecha, no puede moverse en esa direccion
			encontrado = true;
			var5 = 0;

		}

		if (rey.getColor() && consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var5 = 1; //si nuestro rey es blanco, y hay una pieza negra a su esquina superior derecha, podemos movernos en esa direccion comiendonos a esa pieza
		}
		else if (!rey.getColor() && consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var5 = 1; //si nuestro rey es negro, y hay una pieza blanca a su esquina superior derecha, podemos movernos en esa direccion comiendonos a esa pieza
		}

		if (!encontrado) {
			var5 = 1; //si no encontramos ninguna pieza a la esquina superior derecha del rey, podemos movernos en esa direccion.
		}
	}
	encontrado = false;
	//Movimiento diagonal superior izquierda
	if (rey.coordenadas.getX() == 1 || rey.coordenadas.getY() == 8) {
		var6 = 0;
	}
	else {
		coordenadas_de_consulta.setXY(rey.coordenadas.getX() - 1, rey.coordenadas.getY() + 1);
		if (rey.getColor() && consultaBlancas(coordenadas_de_consulta) && !encontrado) { //si nuestro rey es blanco, y hay una pieza blanca a su esquina superior izquierda, no puede moverse en esa direccion
			encontrado = true;
			var6 = 0;
		}
		else if (!rey.getColor() && consultaNegras(coordenadas_de_consulta) && !encontrado) { //si nuestro rey es negro, y hay una pieza negra a su esquina superior izquierda, no puede moverse en esa direccion
			encontrado = true;
			var6 = 0;

		}

		if (rey.getColor() && consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var6 = 1; //si nuestro rey es blanco, y hay una pieza negra a su esquina superior izquierda, podemos movernos en esa direccion comiendonos a esa pieza
		}
		else if (!rey.getColor() && consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var6 = 1; //si nuestro rey es negro, y hay una pieza blanca a su esquina superior izquierda, podemos movernos en esa direccion comiendonos a esa pieza
		}

		if (!encontrado) {
			var6 = 1; //si no encontramos ninguna pieza a la esquina superior izquierda del rey, podemos movernos en esa direccion.
		}
	}
	encontrado = false;
	//Movimiento diagonal inferior derecha
	if (rey.coordenadas.getX() == 8 || rey.coordenadas.getY() == 1) {
		var7 = 0;
	}
	else {
		coordenadas_de_consulta.setXY(rey.coordenadas.getX() + 1, rey.coordenadas.getY() - 1);
		if (rey.getColor() && consultaBlancas(coordenadas_de_consulta) && !encontrado) { //si nuestro rey es blanco, y hay una pieza blanca a su esquina inferior derecha, no puede moverse en esa direccion
			encontrado = true;
			var7 = 0;
		}
		else if (!rey.getColor() && consultaNegras(coordenadas_de_consulta) && !encontrado) { //si nuestro rey es negro, y hay una pieza negra a su esquina inferior derecha, no puede moverse en esa direccion
			encontrado = true;
			var7 = 0;

		}

		if (rey.getColor() && consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var7 = 1; //si nuestro rey es blanco, y hay una pieza negra a su esquina inferior derecha, podemos movernos en esa direccion comiendonos a esa pieza
		}
		else if (!rey.getColor() && consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var7 = 1; //si nuestro rey es negro, y hay una pieza blanca a su esquina inferior derecha, podemos movernos en esa direccion comiendonos a esa pieza
		}

		if (!encontrado) {
			var7 = 1; //si no encontramos ninguna pieza a la esquina inferior derecha del rey, podemos movernos en esa direccion.
		}
	}
	encontrado = false;
	//Movimiento diagonal inferior izquierda
	if (rey.coordenadas.getX() == 1 || rey.coordenadas.getY() == 1) {
		var8 = 0;
	}
	else {
		coordenadas_de_consulta.setXY(rey.coordenadas.getX() - 1, rey.coordenadas.getY() - 1);
		if (rey.getColor() && consultaBlancas(coordenadas_de_consulta) && !encontrado) { //si nuestro rey es blanco, y hay una pieza blanca a su esquina inferior izquierda, no puede moverse en esa direccion
			encontrado = true;
			var8 = 0;
		}
		else if (!rey.getColor() && consultaNegras(coordenadas_de_consulta) && !encontrado) { //si nuestro rey es negro, y hay una pieza negra a su esquina inferior izquierda, no puede moverse en esa direccion
			encontrado = true;
			var8 = 0;

		}

		if (rey.getColor() && consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var8 = 1; //si nuestro rey es blanco, y hay una pieza negra a su esquina inferior izquierda, podemos movernos en esa direccion comiendonos a esa pieza
		}
		else if (!rey.getColor() && consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var8 = 1; //si nuestro rey es negro, y hay una pieza blanca a su esquina inferior izquierda, podemos movernos en esa direccion comiendonos a esa pieza
		}

		if (!encontrado) {
			var8 = 1; //si no encontramos ninguna pieza a la esquina inferior izquierda del rey, podemos movernos en esa direccion.
		}
	}
	encontrado = 0;
	//falta añadir algun tipo de restriccion en el movimiento en los casos de jaque.

	return { 0, 0 }; //Retorno temporal de la función mientras se termina. (Para poder compilar el proyecto mientras tanto).

}
