#include "Dama.h"
#include "Tablero.h"


Dama::Dama(bool color, int x, int y, Tablero* t) {
	this->color = color;
	coordenadas.setX(x);
	coordenadas.setY(y);
	tab = t;
	id = DAMA;
}

void Dama::movimientos()
{
		int var1 = 0, var2 = 0, var3 = 0, var4 = 0,var5=0,var6=0,var7=0,var8=0; //Se definen tantas variables como direcciones de movimiento
		//posibles haya para la pieza. En el caso de la torre son 4 direcciones posibles.
		bool encontrado = false;
		Coords coordenadas_de_consulta;
		//Primero se comprueba dónde se encuentra la pieza más próxima en el PRIMER CUADRANTE
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
		if (!encontrado) //Si no encuentra ninguna pieza es el número de casillas hasta el borde
		{
			if ((8 - coordenadas.getX()) <= (8 - coordenadas.getY())) var1 = (8 - coordenadas.getX());
			else var1 = (8 - coordenadas.getY());
		}

		encontrado = false; //Se prepara para la siguiente búsqueda
		int c2 = 1;
		//Se comprueba dónde se encuentra la pieza más próxima en el SEGUNDO CUADRANTE
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
			if ((coordenadas.getX()) <= (8 - coordenadas.getY())) var2 = (coordenadas.getX()) - 1;
			else var2 = (8 - coordenadas.getY());
		}

		encontrado = false; //Se prepara para la siguiente búsqueda
		int c3 = 1;
		//Comprobación del TERCER CUADRANTE
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
		if (!encontrado) //Si no encuentra ninguna pieza es el número de casillas hasta el borde
		{
			if ((coordenadas.getX()) > coordenadas.getY())
				var3 = coordenadas.getY() - 1;
			else 	var3 = coordenadas.getY() - 1;

		}


		encontrado = false; //Se prepara para la siguiente búsqueda
		int c4 = 1;
		//Se comprueba dónde se encuentra la pieza más próxima en el 4 cuadrante
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


		//Primero se comprueba dónde se encuentra la pieza más próxima en el semieje horizontal positivo
		for (int i = coordenadas.getX() + 1; i <= 8; i++) {
			coordenadas_de_consulta.setXY(i, coordenadas.getY());

			//Comprobaciones de si hay una pieza del mismo color
			if (getColor() && tab->consultaBlancas(coordenadas_de_consulta) && !encontrado) {
				encontrado = true;
				var5 = i - coordenadas.getX() - 1;
			}
			else if (!getColor() && tab->consultaNegras(coordenadas_de_consulta) && !encontrado) {
				encontrado = true;
				var5 = i - coordenadas.getX() - 1;
			}

			//Comprobaciones de si hay una pieza de distinto color
			if (!getColor() && tab->consultaBlancas(coordenadas_de_consulta) && !encontrado) {
				encontrado = true;
				var5 = i - coordenadas.getX();
			}
			else if (getColor() && tab->consultaNegras(coordenadas_de_consulta) && !encontrado) {
				encontrado = true;
				var5 = i - coordenadas.getX();
			}
		}
		if (!encontrado) //Si no encuentra ninguna pieza es el número de casillas hasta el borde
			var5 = 8 - coordenadas.getX();

		encontrado = false; //Se prepara para la siguiente búsqueda
		//Se comprueba dónde se encuentra la pieza más próxima en el semieje horizontal negativo
		for (int i = coordenadas.getX() - 1; i >= 1; i--) {
			coordenadas_de_consulta.setXY(i, coordenadas.getY());

			//Comprobaciones de si hay una pieza del mismo color
			if (getColor() && tab->consultaBlancas(coordenadas_de_consulta) && !encontrado) {
				encontrado = true;
				var6 = coordenadas.getX() - i - 1;
			}
			else if (!getColor() && tab->consultaNegras(coordenadas_de_consulta) && !encontrado) {
				encontrado = true;
				var6 = coordenadas.getX() - i - 1;
			}

			//Comprobaciones de si hay una pieza de distinto color
			if (!getColor() && tab->consultaBlancas(coordenadas_de_consulta) && !encontrado) {
				encontrado = true;
				var6 = coordenadas.getX() - i;
			}
			else if (getColor() && tab->consultaNegras(coordenadas_de_consulta) && !encontrado) {
				encontrado = true;
				var6 = i - coordenadas.getX() - i;
			}
		}
		if (!encontrado)
			var6 = coordenadas.getX() - 1;


		encontrado = false; //Se prepara para la siguiente búsqueda
		//Comprobación del semieje vertical positivo
		for (int i = coordenadas.getY() + 1; i <= 8; i++) {
			coordenadas_de_consulta.setXY(coordenadas.getX(), i);

			//Comprobaciones de si hay una pieza del mismo color
			if (getColor() && tab->consultaBlancas(coordenadas_de_consulta) && !encontrado) {
				encontrado = true;
				var7 = i - coordenadas.getY() - 1;
			}
			else if (!getColor() && tab->consultaNegras(coordenadas_de_consulta) && !encontrado) {
				encontrado = true;
				var7 = i - coordenadas.getY() - 1;
			}

			//Comprobaciones de si hay una pieza de distinto color
			if (!getColor() && tab->consultaBlancas(coordenadas_de_consulta) && !encontrado) {
				encontrado = true;
				var7 = i - coordenadas.getY();
			}
			else if (getColor() && tab->consultaNegras(coordenadas_de_consulta) && !encontrado) {
				encontrado = true;
				var7 = i - coordenadas.getY();
			}
		}
		if (!encontrado) //Si no encuentra ninguna pieza es el número de casillas hasta el borde
			var7 = 8 - coordenadas.getY();


		encontrado = false; //Se prepara para la siguiente búsqueda
		//Se comprueba dónde se encuentra la pieza más próxima en el semieje vertical negativo
		for (int i = coordenadas.getY() - 1; i >= 1; i--) {
			coordenadas_de_consulta.setXY(coordenadas.getX(), i);

			//Comprobaciones de si hay una pieza del mismo color
			if (getColor() && tab->consultaBlancas(coordenadas_de_consulta) && !encontrado) {
				encontrado = true;
				var8 = coordenadas.getY() - i - 1;
			}
			else if (!getColor() && tab->consultaNegras(coordenadas_de_consulta) && !encontrado) {
				encontrado = true;
				var8 = coordenadas.getY() - i - 1;
			}

			//Comprobaciones de si hay una pieza de distinto color
			if (!getColor() && tab->consultaBlancas(coordenadas_de_consulta) && !encontrado) {
				encontrado = true;
				var8 = coordenadas.getY() - i;
			}
			else if (getColor() && tab->consultaNegras(coordenadas_de_consulta) && !encontrado) {
				encontrado = true;
				var8 = i - coordenadas.getY() - i;
			}
		}
		if (!encontrado)
			var8 = coordenadas.getY() - 1;


		//Ya se ha calculado el número de coordenadas que hay que guardar por
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

		for (int i = 0; i < var5; i++) //Semieje horizontal positivo
			coordenadas_disponibles[var1 + var2 + var3 + var4+ i].setXY(coordenadas.getX() + i + 1, coordenadas.getY());
		for (int i = 0; i < var6; i++) //Semieje horizontal negativo
			coordenadas_disponibles[i + var1 + var2 + var3 + var4 + var5].setXY(coordenadas.getX() - i - 1, coordenadas.getY());
		for (int i = 0; i < var7; i++) //Semieje vertical positivo
			coordenadas_disponibles[i + var1 + var2 + var3 + var4 + var5+ var6].setXY(coordenadas.getX(), coordenadas.getY() + i + 1);
		for (int i = 0; i < var8; i++) //Semieje vertical negativo
			coordenadas_disponibles[i + var1 + var2 + var3 + var4 + var5 + var6 + var7].setXY(coordenadas.getX(), coordenadas.getY() - i - 1);

		for (int i = (var1 + var2 + var3 + var4 + var5 + var6 + var7 + var8); i < MAX_MOV; i++)
			coordenadas_disponibles[i] = { 9,9 };
}

bool Dama::mover(Coords destino) {
	for (int i = 0; i < MAX_MOV; i++) {
		if (destino == coordenadas_disponibles[i]) {
			coordenadas = destino;
			return true;
		}
	}
	return false;
}