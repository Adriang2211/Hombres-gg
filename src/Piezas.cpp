#include "Piezas.h"
#include "Posicionamiento.h"
#include "Tablero.h"





void Alfil::movimientos() {
	int var1 = 0, var2 = 0, var3 = 0, var4 = 0; //Se definen tantas variables como direcciones de movimiento
	//posibles haya para la pieza. En el caso de la torre son 4 direcciones posibles.
	bool encontrado = false;
	Coords coordenadas_de_consulta;
	//Primero se comprueba d�nde se encuentra la pieza m�s pr�xima en el PRIMER CUADRANTE
	int c1 = 1;
	for (int i = coordenadas.getX() + 1; i <= 8; i++) {
		coordenadas_de_consulta.setXY(i, coordenadas.getY() + c1);
		c1++;
		//Comprobaciones de si hay una pieza del mismo color
		if (getColor() && tab->consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var1 = i - coordenadas.getX() - 1;
		}
		else if (!getColor() && tab->consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var1 = i - coordenadas.getX() - 1;
		}

		//Comprobaciones de si hay una pieza de distinto color
		if (!getColor() && tab->consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var1 = i - coordenadas.getX();
		}
		else if (getColor() && tab->consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var1 = i - coordenadas.getX();
		}
	}
	if (!encontrado) //Si no encuentra ninguna pieza es el n�mero de casillas hasta el borde
	{
		if (coordenadas.getX() == 8 && coordenadas.getY() == 1)
			var1 = 0;
		else if (coordenadas.getY() == 1)
			var1 = 8 - coordenadas.getX();
		else if (coordenadas.getY() == 8)
			var1 = 0;
	}

	encontrado = false; //Se prepara para la siguiente b�squeda
	int c2 = 1;
	//Se comprueba d�nde se encuentra la pieza m�s pr�xima en el SEGUNDO CUADRANTE
	for (int i = coordenadas.getX() - 1; i >= 1; i--) {
		coordenadas_de_consulta.setXY(i, coordenadas.getY() + c2);
		c2++;

		//Comprobaciones de si hay una pieza del mismo color
		if (getColor() && tab->consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var2 = coordenadas.getX() - i - 1;
		}
		else if (!getColor() && tab->consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var2 = coordenadas.getX() - i - 1;
		}

		//Comprobaciones de si hay una pieza de distinto color
		if (!getColor() && tab->consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var2 = coordenadas.getX() - i;
		}
		else if (getColor() && tab->consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var2 = coordenadas.getX() - i;

		}
	}
	if (!encontrado)
	{
		if (coordenadas.getX() == 1 && coordenadas.getY() == 1)
			var2 = 0;
		else if (coordenadas.getY() == 1)
			var2 = coordenadas.getX() - 1;
		else if (coordenadas.getY() == 8)
			var2 = 0;
	}

	encontrado = false; //Se prepara para la siguiente b�squeda
	int c3 = 1;
	//Comprobaci�n del TERCER CUADRANTE
	for (int i = coordenadas.getY() - 1; i >= 1; i--) {
		coordenadas_de_consulta.setXY(coordenadas.getX() - c3, i);
		c3++;
		//Comprobaciones de si hay una pieza del mismo color
		if (getColor() && tab->consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var3 = coordenadas.getY() - i - 1;
		}
		else if (!getColor() && tab->consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var3 = coordenadas.getY() - i - 1;
		}

		//Comprobaciones de si hay una pieza de distinto color
		if (!getColor() && tab->consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var3 = coordenadas.getY() - i;
		}
		else if (getColor() && tab->consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var3 = coordenadas.getY() - i;
		}
	}
	if (!encontrado) //Si no encuentra ninguna pieza es el n�mero de casillas hasta el borde
	{
		if ((coordenadas.getX()) > coordenadas.getY())
			var3 = coordenadas.getY() - 1;
		else 	var3 = coordenadas.getY() - 1;

	}


	encontrado = false; //Se prepara para la siguiente b�squeda
	int c4 = 1;
	//Se comprueba d�nde se encuentra la pieza m�s pr�xima en el 4 cuadrante
	for (int i = coordenadas.getY() - 1; i >= 1; i--) {
		coordenadas_de_consulta.setXY(coordenadas.getX() + c4, i);
		c4++;
		//Comprobaciones de si hay una pieza del mismo color
		if (getColor() && tab->consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var4 = coordenadas.getY() - i - 1;
		}
		else if (!getColor() && tab->consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var4 = coordenadas.getY() - i - 1;
		}

		//Comprobaciones de si hay una pieza de distinto color
		if (!getColor() && tab->consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var4 = coordenadas.getY() - i;
		}
		else if (getColor() && tab->consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var4 = coordenadas.getY() - i;
		}
	}
	if (!encontrado)
	{
		if (coordenadas.getY() > (8 - coordenadas.getX()))//siempre tiene dominancia en el numero maximo de posiciones la coordenada menor
			var4 = 8 - coordenadas.getX();
		else var4 = coordenadas.getY() - 1;
	}



	//Ya se ha calculado el n�mero de coordenadas que hay que guardar por
	//Coords* coordenadas_disponibles = new Coords[var1 + var2 + var3 + var4];

	for (int i = 0; i < var1; i++) //primer cuadrante
	{
		coordenadas_disponibles[i].setX(coordenadas.getX() + i + 1);
		coordenadas_disponibles[i].setY(coordenadas.getY() + i + 1);
	};
	for (int i = 0; i < var2; i++) //Segundo cuadrante
	{
		coordenadas_disponibles[var1 + i].setX(coordenadas.getX() - i - 1);
		coordenadas_disponibles[var1 + i].setY(coordenadas.getY() + i + 1);

	};
	for (int i = 0; i < var3; i++) //tercer caudrante
	{
		coordenadas_disponibles[var1 + var2 + i].setX(coordenadas.getX() - i - 1);
		coordenadas_disponibles[var1 + var2 + i].setY(coordenadas.getY() - i - 1);
	};

	for (int i = 0; i < var4; i++) //Cuarto Cuadrante
	{
		coordenadas_disponibles[var1 + var2 + var3 + i].setX(coordenadas.getX() + i + 1);
		coordenadas_disponibles[var1 + var2 + var3 + i].setY(coordenadas.getY() - i - 1);
	};

}






void Rey::movimientos() {
	int var1 = 0, var2 = 0, var3 = 0, var4 = 0, var5 = 0, var6 = 0, var7 = 0, var8 = 0; //cada una de estas variables se usar� para cada direccion en la que puede moverse el rey
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
	//falta a�adir algun tipo de restriccion en el movimiento en los casos de jaque.

	for (int i = 0; i < var1; i++) { //Movimientos hacia delante
		coordenadas_disponibles[i].setXY(coordenadas.getX(), coordenadas.getY() + 1);
	}
	for (int i = 0; i < var2; i++) { //Movimientos hacia atras
		coordenadas_disponibles[i + var1].setXY(coordenadas.getX(), coordenadas.getY() - 1);
	}
	for (int i = 0; i < var3; i++) {
		coordenadas_disponibles[i + var1 + var2].setXY(coordenadas.getX() + 1, coordenadas.getY());
	}
}




void Peon::movimientos()
{
	for (int i = 0; i < MAX_MOV_PEON; i++)
	{
		coordenadas_disponibles[i] = { 0,0 };
	}
	int mov1 = 0;// 3 direecciones posibles para el peon
	Coords coordenas_de_consulta;
	//movimiento hacia delante
	if (primer_movimiento)
	{
		if (color)
		{
			coordenas_de_consulta.setXY(coordenadas.getX(), coordenadas.getY() + 2);
			if (!tab->consultaBlancas(coordenas_de_consulta) && !tab->consultaNegras(coordenas_de_consulta))
			{
				coordenadas_disponibles[mov1].setXY(coordenadas.getX(), coordenadas.getY() + 2);//adelante
				mov1++;
			}
		}
		else if (!color)
		{
			coordenas_de_consulta.setXY(coordenadas.getX(), coordenadas.getY() - 2);
			if (!tab->consultaBlancas(coordenas_de_consulta) && !tab->consultaNegras(coordenas_de_consulta))
			{
				coordenadas_disponibles[mov1].setXY(coordenadas.getX(), coordenadas.getY() - 2);//adelante
				mov1++;
			}
		}
	}
	if (color == true)
	{

		coordenas_de_consulta.setXY(coordenadas.getX(), coordenadas.getY() + 1);
		if (!tab->consultaBlancas(coordenas_de_consulta) && !tab->consultaNegras(coordenas_de_consulta))
		{
			coordenadas_disponibles[mov1].setXY(coordenadas.getX(), coordenadas.getY() + 1);//adelante
			mov1++;
		}
	}
	else if (color == false)
	{
		coordenas_de_consulta.setXY(coordenadas.getX(), coordenadas.getY() - 1);
		if (!tab->consultaBlancas(coordenas_de_consulta) && !tab->consultaNegras(coordenas_de_consulta))
		{
			coordenadas_disponibles[mov1].setXY(coordenadas.getX(), coordenadas.getY() - 1);
			mov1++;
		}

	}

	//movimiento diagonal derecha
	if (color == true)
	{
		coordenas_de_consulta.setXY(coordenadas.getX() + 1, coordenadas.getY() + 1);
		if (tab->consultaNegras(coordenas_de_consulta))
		{
			coordenadas_disponibles[mov1].setXY(coordenadas.getX() + 1, coordenadas.getY() + 1);
			mov1++;
		}
	}
	if (color == false)
	{
		coordenas_de_consulta.setXY(coordenadas.getX() - 1, coordenadas.getY() - 1);
		if (tab->consultaBlancas(coordenas_de_consulta))
		{
			coordenadas_disponibles[mov1].setXY(coordenadas.getX() - 1, coordenadas.getY() - 1);
			mov1++;
		}
	}
	//Movimiento diagonal izq
	if (color == true)
	{
		coordenas_de_consulta.setXY(coordenadas.getX() - 1, coordenadas.getY() + 1);
		if (tab->consultaNegras(coordenas_de_consulta))
		{
			coordenadas_disponibles[mov1].setXY(coordenadas.getX() - 1, coordenadas.getY() + 1);
			mov1++;
		}
	}
	if (color == false)
	{
		coordenas_de_consulta.setXY(coordenadas.getX() + 1, coordenadas.getY() - 1);
		if (tab->consultaBlancas(coordenas_de_consulta))
		{
			coordenadas_disponibles[mov1].setXY(coordenadas.getX() + 1, coordenadas.getY() - 1);
			mov1++;
		}
	}


}