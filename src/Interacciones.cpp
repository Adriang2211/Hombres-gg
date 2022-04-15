#include "Interacciones.h"
#include "Piezas.h"

bool Interacciones::consultaBlancas(Coords& const coordenada) {
	for (int i = 0; i < 16; i++) {
		//Busca la coordenada que se ha pasado en el vector de las piezas blancas
		if (casillas_ocupadas_blancas[i].getX() == coordenada.getX() && casillas_ocupadas_blancas[i].getY() == coordenada.getY())
			return true;     //devuelve true si hay una pieza blanca en la casilla
	}
	return false;		//devuelve flase si no hay una pieza blanca en la casilla
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


	for (int i = 0; i < var1; i++) //Semieje horizontal positivo
		torre.movimientos_posibles[i].setXY(torre.coordenadas.getX() + i + 1, torre.coordenadas.getY());
	for (int i = 0; i < var2; i++) //Semieje horizontal negativo
		torre.movimientos_posibles[i + var1].setXY(torre.coordenadas.getX() - i - 1, torre.coordenadas.getY());
	for (int i = 0; i < var3; i++) //Semieje vertical positivo
		torre.movimientos_posibles[i + var1 + var2].setXY(torre.coordenadas.getX(), torre.coordenadas.getY() + i + 1);
	for (int i = 0; i < var4; i++) //Semieje vertical negativo
		torre.movimientos_posibles[i + var1 + var2 + var3].setXY(torre.coordenadas.getX(), torre.coordenadas.getY() - i - 1);
	for (int i = var1 + var2 + var3 + var4; i < MAX_MOV_TORRE; i++)
		torre.movimientos_posibles[i].setXY(9, 9); //9 como s�mbolo de que est� vac�o
}

void Interacciones::movimientos(Rey& rey) {
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

	for (int i = 0; i < var1; i++) { //Movimientos hacia delante
		rey.movimientos_disponibles[i].setXY(rey.coordenadas.getX(), rey.coordenadas.getY() + 1);
	 }
	for (int i = 0; i < var2; i++) { //Movimientos hacia atras
		rey.movimientos_disponibles[i + var1].setXY(rey.coordenadas.getX(), rey.coordenadas.getY() - 1);
	}
	for (int i = 0; i < var3; i++) {
		rey.movimientos_disponibles[i + var1 + var2].setXY(rey.coordenadas.getX() + 1, rey.coordenadas.getY());
	}


}

void Interacciones::movimientos(Alfil& alfil) {
	int var1 = 0, var2 = 0, var3 = 0, var4 = 0; //Se definen tantas variables como direcciones de movimiento
	//posibles haya para la pieza. En el caso de la torre son 4 direcciones posibles.
	bool encontrado = false;
	Coords coordenadas_de_consulta;
	//Primero se comprueba dónde se encuentra la pieza más próxima en el PRIMER CUADRANTE
	int c1 = 1;
	for (int i = alfil.coordenadas.getX() + 1; i <= 8; i++) {
		coordenadas_de_consulta.setXY(i, alfil.coordenadas.getY() + c1);
		c1++;
		//Comprobaciones de si hay una pieza del mismo color
		if (alfil.getColor() && consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var1 = i - alfil.coordenadas.getX() - 1;
		}
		else if (!alfil.getColor() && consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var1 = i - alfil.coordenadas.getX() - 1;
		}

		//Comprobaciones de si hay una pieza de distinto color
		if (!alfil.getColor() && consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var1 = i - alfil.coordenadas.getX();
		}
		else if (alfil.getColor() && consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var1 = i - alfil.coordenadas.getX();
		}
	}
	if (!encontrado) //Si no encuentra ninguna pieza es el número de casillas hasta el borde
	{
		if (alfil.coordenadas.getX() == 8 && alfil.coordenadas.getY() == 1)
			var1 = 0;
		else if (alfil.coordenadas.getY() == 1)
			var1 = 8 - alfil.coordenadas.getX();
		else if (alfil.coordenadas.getY() == 8)
			var1 = 0;
	}

	encontrado = false; //Se prepara para la siguiente búsqueda
	int c2 = 1;
	//Se comprueba dónde se encuentra la pieza más próxima en el SEGUNDO CUADRANTE
	for (int i = alfil.coordenadas.getX() - 1; i >= 1; i--) {
		coordenadas_de_consulta.setXY(i, alfil.coordenadas.getY() + c2);
		c2++;

		//Comprobaciones de si hay una pieza del mismo color
		if (alfil.getColor() && consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var2 = alfil.coordenadas.getX() - i - 1;
		}
		else if (!alfil.getColor() && consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var2 = alfil.coordenadas.getX() - i - 1;
		}

		//Comprobaciones de si hay una pieza de distinto color
		if (!alfil.getColor() && consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var2 = alfil.coordenadas.getX() - i;
		}
		else if (alfil.getColor() && consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var2 = alfil.coordenadas.getX() - i;
			
		}
	}
	if (!encontrado)
	{
		if (alfil.coordenadas.getX() == 1 && alfil.coordenadas.getY() == 1)
			var2 = 0;
		else if (alfil.coordenadas.getY() == 1)
			var2 = alfil.coordenadas.getX() - 1;
		else if (alfil.coordenadas.getY() == 8)
			var2 = 0;
	}

	encontrado = false; //Se prepara para la siguiente búsqueda
	int c3 = 1;
	//Comprobación del TERCER CUADRANTE
	for (int i = alfil.coordenadas.getY() - 1; i >= 1; i--) {
		coordenadas_de_consulta.setXY(alfil.coordenadas.getX() - c3, i);
		c3++;
		//Comprobaciones de si hay una pieza del mismo color
		if (alfil.getColor() && consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var3 = alfil.coordenadas.getY() - i - 1;
		}
		else if (!alfil.getColor() && consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var3 = alfil.coordenadas.getY() - i - 1;
		}

		//Comprobaciones de si hay una pieza de distinto color
		if (!alfil.getColor() && consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var3 = alfil.coordenadas.getY() - i;
		}
		else if (alfil.getColor() && consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var3 = alfil.coordenadas.getY() - i;
		}
	}
	if (!encontrado) //Si no encuentra ninguna pieza es el número de casillas hasta el borde
	{
		if ((alfil.coordenadas.getX()) > alfil.coordenadas.getY())
			var3 = alfil.coordenadas.getY() - 1;
		else 	var3 = alfil.coordenadas.getY() - 1;
	
	}


	encontrado = false; //Se prepara para la siguiente búsqueda
	int c4 = 1;
	//Se comprueba dónde se encuentra la pieza más próxima en el 4 cuadrante
	for (int i = alfil.coordenadas.getY() - 1; i >= 1; i--) {
		coordenadas_de_consulta.setXY(alfil.coordenadas.getX() + c4, i);
		c4++;
		//Comprobaciones de si hay una pieza del mismo color
		if (alfil.getColor() && consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var4 = alfil.coordenadas.getY() - i - 1;
		}
		else if (!alfil.getColor() && consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var4 = alfil.coordenadas.getY() - i - 1;
		}

		//Comprobaciones de si hay una pieza de distinto color
		if (!alfil.getColor() && consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var4 = alfil.coordenadas.getY() - i;
		}
		else if (alfil.getColor() && consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var4 = alfil.coordenadas.getY() - i;
		}
	}
	if (!encontrado)
	{
		if (alfil.coordenadas.getY() > (8 - alfil.coordenadas.getX()))//siempre tiene dominancia en el numero maximo de posiciones la coordenada menor
			var4 = 8 - alfil.coordenadas.getX();
		else var4 = alfil.coordenadas.getY() - 1;
	}



	//Ya se ha calculado el número de coordenadas que hay que guardar por
	//Coords* coordenadas_disponibles = new Coords[var1 + var2 + var3 + var4];

	for (int i = 0; i < var1; i++) //primer cuadrante
	{
		alfil.coordenadas_disponibles[i].setX(alfil.coordenadas.getX() + i + 1);
		alfil.coordenadas_disponibles[i].setY(alfil.coordenadas.getY() + i + 1);
	};
	for (int i = 0; i < var2; i++) //Segundo cuadrante
	{
		alfil.coordenadas_disponibles[var1 + i].setX(alfil.coordenadas.getX() - i - 1);
		alfil.coordenadas_disponibles[var1 + i].setY(alfil.coordenadas.getY() + i + 1);

	};
	for (int i = 0; i < var3; i++) //tercer caudrante
	{
		alfil.coordenadas_disponibles[var1 + var2 + i].setX(alfil.coordenadas.getX() - i - 1);
		alfil.coordenadas_disponibles[var1 + var2 + i].setY(alfil.coordenadas.getY() - i - 1);
	};

	for (int i = 0; i < var4; i++) //Cuarto Cuadrante
	{
		alfil.coordenadas_disponibles[var1 + var2 + var3 + i].setX(alfil.coordenadas.getX() + i + 1);
		alfil.coordenadas_disponibles[var1 + var2 + var3 + i].setY(alfil.coordenadas.getY() - i - 1);
	};

}


void Interacciones::movimientos(Caballo& caballo) {

	Coords coordenadas_de_consulta;
	Coords coordenadas_inservibles = {10, 10};
	//Se recomienda ver la imagen del modelo para entender la estuctura de la funcion
	//arriba
	coordenadas_de_consulta.setY(caballo.coordenadas.getY() + 2);  //Sube dos posiciones
		//izq
			coordenadas_de_consulta.setX(caballo.coordenadas.getX() - 1); //Nos movemos uno a la izq (casilla modelo 1)
			if (coordenadas_de_consulta.getY() > 8 || coordenadas_de_consulta.getX() < 1) {//Si me salgo por arriba o por la izquierda
				//significa que no es un movimiento disponible y en el espacio del vector ponemos algo especial//conocido
				caballo.coordenadas_disponibles[0] = coordenadas_inservibles;
			}
			else {//Si no me salgo por arriba o por la izquierda
				//significa que puede ser un movimiento disponible, dependiendo de si en la casilla hay un amigo o no
				tuPetitInteraccion(coordenadas_de_consulta, coordenadas_inservibles, caballo, 0);
			}

		//derecha
			coordenadas_de_consulta.setX(coordenadas_de_consulta.getX() + 2); //Nos movemos 2 casillas a la derecha (casilla modelo 2)
			if (coordenadas_de_consulta.getY() > 8 || coordenadas_de_consulta.getX() > 8) {//Si me salgo por arriba o por la derecha
				//significa que no es un movimiento disponible y en el espacio del vector ponemos algo especial//conocido
				caballo.coordenadas_disponibles[1] = coordenadas_inservibles;
			}
			else {//Si no me salgo por arriba o por la derecha
				//significa que puede ser un movimiento disponible, dependiendo de si en la casilla hay un amigo o no
				tuPetitInteraccion(coordenadas_de_consulta, coordenadas_inservibles, caballo, 1);
			}

	//derecha
		//arriba
			coordenadas_de_consulta.setXY(coordenadas_de_consulta.getX() + 1, coordenadas_de_consulta.getY() - 1); //Nos movemos una a la derecha y una abajo(casilla modelo 3)
			if (coordenadas_de_consulta.getY() > 8 || coordenadas_de_consulta.getX() > 8) {//Si me salgo por arriba o por la derecha
				//significa que no es un movimiento disponible y en el espacio del vector ponemos algo especial//conocido
				caballo.coordenadas_disponibles[2] = coordenadas_inservibles;
			}
			else {//Si no me salgo por arriba o por la derecha
				//significa que puede ser un movimiento disponible, dependiendo de si en la casilla hay un amigo o no
				tuPetitInteraccion(coordenadas_de_consulta, coordenadas_inservibles, caballo, 2);
			}
		//abajo
			coordenadas_de_consulta.setY(coordenadas_de_consulta.getY() - 2); //Nos movemos 2 abajo (casilla modelo 4)
			if (coordenadas_de_consulta.getY() < 1 || coordenadas_de_consulta.getX() > 8) {//Si me salgo por abajo o por la derecha
				//significa que no es un movimiento disponible y en el espacio del vector ponemos algo especial//conocido
				caballo.coordenadas_disponibles[3] = coordenadas_inservibles;
			}
			else {//Si no me salgo por abajo o por la derecha
				//significa que puede ser un movimiento disponible, dependiendo de si en la casilla hay un amigo o no
				tuPetitInteraccion(coordenadas_de_consulta, coordenadas_inservibles, caballo, 3);
			}

	//abajo
		//derecha
			coordenadas_de_consulta.setXY(coordenadas_de_consulta.getX() - 1, coordenadas_de_consulta.getY() - 1);//Nos movemos uno a la izq y uno abajo(casilla modelo 5)
			if (coordenadas_de_consulta.getY() < 1 || coordenadas_de_consulta.getX() > 8) {//Si me salgo por abajo o por la derecha
				//significa que no es un movimiento disponible y en el espacio del vector ponemos algo especial//conocido
				caballo.coordenadas_disponibles[4] = coordenadas_inservibles;
			}
			else {//Si no me salgo por abajo o por la derecha
				//significa que puede ser un movimiento disponible, dependiendo de si en la casilla hay un amigo o no
				tuPetitInteraccion(coordenadas_de_consulta, coordenadas_inservibles, caballo, 4);
			}

		//izquierda
			coordenadas_de_consulta.setX(coordenadas_de_consulta.getX() - 2); //Nos movemos 2 a la izq, (casilla modelo 6)
			if (coordenadas_de_consulta.getY() < 1 || coordenadas_de_consulta.getX() < 1) {//Si me salgo por abajo o por la izquierda
				//significa que no es un movimiento disponible y en el espacio del vector ponemos algo especial//conocido
				caballo.coordenadas_disponibles[5] = coordenadas_inservibles;
			}
			else {//Si no me salgo por abajo o por la izquierda
				//significa que puede ser un movimiento disponible, dependiendo de si en la casilla hay un amigo o no
				tuPetitInteraccion(coordenadas_de_consulta, coordenadas_inservibles, caballo, 5);
			}

	//izquierda
		//abajo
			coordenadas_de_consulta.setXY(coordenadas_de_consulta.getX() - 1, coordenadas_de_consulta.getY() + 1);//Nos movemos 1 a la izq y 1 arriba(casilla modelo 7)
			if (coordenadas_de_consulta.getY() < 1 || coordenadas_de_consulta.getX() < 1) {//Si me salgo por abajo o por la izquierda
				//significa que no es un movimiento disponible y en el espacio del vector ponemos algo especial//conocido
				caballo.coordenadas_disponibles[6] = coordenadas_inservibles;
			}
			else {//Si no me salgo por abajo o por la izquierda
				//significa que puede ser un movimiento disponible, dependiendo de si en la casilla hay un amigo o no
				tuPetitInteraccion(coordenadas_de_consulta, coordenadas_inservibles, caballo, 6);
			}

		//arriba
			coordenadas_de_consulta.setY(coordenadas_de_consulta.getY() + 2);//Nos movemos 2 arriba (casilla modelo 8)
			if (coordenadas_de_consulta.getY() > 8 || coordenadas_de_consulta.getX() < 1) {//Si me salgo por arriba o por la izquierda
				//significa que no es un movimiento disponible y en el espacio del vector ponemos algo especial//conocido
				caballo.coordenadas_disponibles[7] = coordenadas_inservibles;
			}
			else {//Si no me salgo por arriba o por la izquierda
				//significa que puede ser un movimiento disponible, dependiendo de si en la casilla hay un amigo o no
				tuPetitInteraccion(coordenadas_de_consulta, coordenadas_inservibles, caballo, 7);
			}
}

void Interacciones::tuPetitInteraccion(Coords coordenadas_de_consulta,Coords coordenadas_inservibles, Caballo& caballo, int i) {

	if (caballo.getColor() == true) { //si el caballo es blanco
		if (consultaBlancas(coordenadas_de_consulta) == true) {	//Si ya habia una pieza blanca(aliada) en la casilla
			//significa que no es un movimiento disponible y en el espacio del vector ponemos algo especial//conocido
			caballo.coordenadas_disponibles[i] = coordenadas_inservibles;
		}
		else {//Si no habia una pieza blanca en la casilla(vacia o pieza negra)
			//significa que es un movimiento disponible, y lo incluimos en el vector
			caballo.coordenadas_disponibles[i] = coordenadas_de_consulta;
		}
	}
	else { //si el caballo es negro
		if (consultaNegras(coordenadas_de_consulta) == true) {	//Si ya habia una pieza negra(aliada) en la casilla
			//significa que no es un movimiento disponible y en el espacio del vector ponemos algo especial//conocido
			caballo.coordenadas_disponibles[i] = coordenadas_inservibles;
		}
		else {//Si no habia una pieza negra en la casilla(vacia o pieza blanca)
			//significa que es un movimiento disponible, y lo incluimos en el vector
			caballo.coordenadas_disponibles[i] = coordenadas_de_consulta;
		}
	}

}