#include "Alfil.h"
#include "Tablero.h"


Alfil::Alfil(bool color, int x, int y, Tablero* t) {
	this->color = color;
	coordenadas.setX(x);
	coordenadas.setY(y);
	tab = t;
	id = ALFIL;
}


void Alfil::movimientos() {
	int var1 = 0, var2 = 0, var3 = 0, var4 = 0; //Se definen tantas variables como direcciones de movimiento
	//posibles haya para la pieza. En el caso de la torre son 4 direcciones posibles.
	bool encontrado = false;
	Coords coordenadas_de_consulta;
	//Primero se comprueba d?nde se encuentra la pieza m?s pr?xima en el PRIMER CUADRANTE
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
	if (!encontrado) //Si no encuentra ninguna pieza es el n?mero de casillas hasta el borde
	{
		if ((8 - coordenadas.getX()) <= (8 - coordenadas.getY())) var1 = (8 - coordenadas.getX());
		else var1 = (8 - coordenadas.getY());
	}

	encontrado = false; //Se prepara para la siguiente b?squeda
	int c2 = 1;
	//Se comprueba d?nde se encuentra la pieza m?s pr?xima en el SEGUNDO CUADRANTE
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
		if ((coordenadas.getX()) <= (8 - coordenadas.getY())) var2 = (coordenadas.getX())-1;
		else var2 = (8 - coordenadas.getY());
	}

	encontrado = false; //Se prepara para la siguiente b?squeda
	int c3 = 1;
	//Comprobaci?n del TERCER CUADRANTE
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
	if (!encontrado) //Si no encuentra ninguna pieza es el n?mero de casillas hasta el borde
	{
		if ((coordenadas.getX()) > coordenadas.getY())
			var3 = coordenadas.getY() - 1;
		//else if ()
		else 	var3 = coordenadas.getX() - 1;

	}


	encontrado = false; //Se prepara para la siguiente b?squeda
	int c4 = 1;
	//Se comprueba d?nde se encuentra la pieza m?s pr?xima en el 4 cuadrante
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



	//Ya se ha calculado el n?mero de coordenadas que hay que guardar por
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
	for (int i = (var1 + var2 + var3 + var4); i < MAX_MOV; i++)
		coordenadas_disponibles[i] = { 9,9 };

}


void Alfil::dibuja(int opc) {
	if (opc == 0)
	{

		if (color == true) {
			alfilBlancas.setCenter(-coordenadas.getX() + 1, -coordenadas.getY() + 1);
			alfilBlancas.setSize(1, 1);
			alfilBlancas.draw();
		}
		else {
			alfilNegras.setCenter(-coordenadas.getX() + 1, -coordenadas.getY() + 1);
			alfilNegras.setSize(1, 1);
			alfilNegras.draw();
		}
	}
	else if (opc == 1)
	{

		if (color == false) {
			alfilDorado.setCenter(-coordenadas.getX() + 1, -coordenadas.getY() + 1);
			alfilDorado.setSize(1, 1);
			alfilDorado.draw();
		}
		else {
			alfilPlata.setCenter(-coordenadas.getX() + 1, -coordenadas.getY() + 1);
			alfilPlata.setSize(1, 1);
			alfilPlata.draw();
		}
	}
}