#include "Torre.h"
#include "Tablero.h"


Torre::Torre(bool color, int x, int y, Tablero* t) {
	this->color = color;
	coordenadas.setX(x);
	coordenadas.setY(y);
	tab = t;
	primer_movimiento = true;
	id = TORRE;
}


void Torre::movimientos() {
	int var1 = 0, var2 = 0, var3 = 0, var4 = 0; //Se definen tantas variables como direcciones de movimiento
	//posibles haya para la pieza. En el caso de la torre son 4 direcciones posibles.
	bool encontrado = false;
	Coords coordenadas_de_consulta;

	//Primero se comprueba dónde se encuentra la pieza más próxima en el semieje horizontal positivo
	for (int i = coordenadas.getX() + 1; i <= 8; i++) {
		coordenadas_de_consulta.setXY(i, coordenadas.getY());

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
		var1 = 8 - coordenadas.getX();

	encontrado = false; //Se prepara para la siguiente búsqueda
	//Se comprueba dónde se encuentra la pieza más próxima en el semieje horizontal negativo
	for (int i = coordenadas.getX() - 1; i >= 1; i--) {
		coordenadas_de_consulta.setXY(i, coordenadas.getY());

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
			var2 = i - coordenadas.getX() - i;
		}
	}
	if (!encontrado)
		var2 = coordenadas.getX() - 1;


	encontrado = false; //Se prepara para la siguiente búsqueda
	//Comprobación del semieje vertical positivo
	for (int i = coordenadas.getY() + 1; i <= 8; i++) {
		coordenadas_de_consulta.setXY(coordenadas.getX(), i);

		//Comprobaciones de si hay una pieza del mismo color
		if (getColor() && tab->consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var3 = i - coordenadas.getY() - 1;
		}
		else if (!getColor() && tab->consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var3 = i - coordenadas.getY() - 1;
		}

		//Comprobaciones de si hay una pieza de distinto color
		if (!getColor() && tab->consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var3 = i - coordenadas.getY();
		}
		else if (getColor() && tab->consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var3 = i - coordenadas.getY();
		}
	}
	if (!encontrado) //Si no encuentra ninguna pieza es el número de casillas hasta el borde
		var3 = 8 - coordenadas.getY();


	encontrado = false; //Se prepara para la siguiente búsqueda
	//Se comprueba dónde se encuentra la pieza más próxima en el semieje vertical negativo
	for (int i = coordenadas.getY() - 1; i >= 1; i--) {
		coordenadas_de_consulta.setXY(coordenadas.getX(), i);

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
			var4 = i - coordenadas.getY() - i;
		}
	}
	if (!encontrado)
		var4 = coordenadas.getY() - 1;


	for (int i = 0; i < var1; i++) //Semieje horizontal positivo
		coordenadas_disponibles[i].setXY(coordenadas.getX() + i + 1, coordenadas.getY());
	for (int i = 0; i < var2; i++) //Semieje horizontal negativo
		coordenadas_disponibles[i + var1].setXY(coordenadas.getX() - i - 1, coordenadas.getY());
	for (int i = 0; i < var3; i++) //Semieje vertical positivo
		coordenadas_disponibles[i + var1 + var2].setXY(coordenadas.getX(), coordenadas.getY() + i + 1);
	for (int i = 0; i < var4; i++) //Semieje vertical negativo
		coordenadas_disponibles[i + var1 + var2 + var3].setXY(coordenadas.getX(), coordenadas.getY() - i - 1);


	//Comprobación de los enroques
	if (color) {
		Coords torre_enroque_corto_blancas = { h, 1 };
		Coords torre_enroque_largo_blancas = { a, 1 };

		if (tab->enroque_corto_blancas() && getCoordenadas()==torre_enroque_corto_blancas) {
			//Si el enroque de las blancas es posible y si la torre cuyos movimientos se están calculando es la de ese enroque...
			coordenadas_disponibles[var1 + var2 + var3 + var4] = { f, 1 };
			var4++;
		}
		if (tab->enroque_largo_blancas() && getCoordenadas() == torre_enroque_largo_blancas) {
			coordenadas_disponibles[var1 + var2 + var3 + var4] = { d, 1 };
			var4++;
		}
	}
	else if (!color) {
		Coords torre_enroque_corto_negras = { h, 8 };
		Coords torre_enroque_largo_negras = { a, 8 };
		if (tab->enroque_corto_negras() && getCoordenadas() == torre_enroque_corto_negras) {
			coordenadas_disponibles[var1 + var2 + var3 + var4] = { f, 8 };
			var4++;
		}
		if (tab->enroque_largo_negras() && getCoordenadas() == torre_enroque_largo_negras) {
			coordenadas_disponibles[var1 + var2 + var3 + var4] = { d, 8 };
			var4++;
		}
	}

	for (int i = var1 + var2 + var3 + var4; i < MAX_MOV; i++)
		coordenadas_disponibles[i].setXY(9, 9); //9 como simbolo de que esta vacio

}



bool Torre::mover(Coords destino) {
	for (int i = 0; i < MAX_MOV; i++) {
		if (destino == coordenadas_disponibles[i]) {
			coordenadas = destino;
			return true;
		}
	}
	if (primer_movimiento)
		primer_movimiento = false;
	tab->cambiarTurno();
	return false;
}

void Torre::dibuja() {
	if (color == true) {
		torreBlancas.setCenter(-coordenadas.getX() + 1, -coordenadas.getY() + 1);
		torreBlancas.setSize(1, 1);
		torreBlancas.draw();
	}
	else {
		torreNegras.setCenter(-coordenadas.getX() + 1, -coordenadas.getY() + 1);
		torreNegras.setSize(1, 1);
		torreNegras.draw();
	}
}