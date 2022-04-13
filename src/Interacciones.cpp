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


Coords Interacciones::movimientos(Torre& const torre) {
	int var1=0, var2=0, var3=0, var4=0; //Se definen tantas variables como direcciones de movimiento
	//posibles haya para la pieza. En el caso de la torre son 4 direcciones posibles.
	bool encontrado = false;
	Coords coordenadas_de_consulta;
	//Primero se comprueba dónde se encuentra la pieza más próxima en el semieje horizontal positivo
	for (int i = torre.coordenadas.getX(); i <= 8; i++) {
		coordenadas_de_consulta.setXY(i, torre.coordenadas.getY());

		//Comprobaciones de si hay una pieza del mismo color
		if (torre.getColor() && consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var1 = i - torre.coordenadas.getX()-1;
		}
		else if (!torre.getColor() && consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var1 = i - torre.coordenadas.getX()-1;
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
	for (int i = torre.coordenadas.getX(); i >= 1; i--) {
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
	for (int i = torre.coordenadas.getY(); i <= 8; i++) {
		coordenadas_de_consulta.setXY(torre.coordenadas.getX(), i);

		//Comprobaciones de si hay una pieza del mismo color
		if (torre.getColor() && consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var1 = i - torre.coordenadas.getY() - 1;
		}
		else if (!torre.getColor() && consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var1 = i - torre.coordenadas.getY() - 1;
		}

		//Comprobaciones de si hay una pieza de distinto color
		if (!torre.getColor() && consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var1 = i - torre.coordenadas.getY();
		}
		else if (torre.getColor() && consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var1 = i - torre.coordenadas.getY();
		}
	}
	if (!encontrado) //Si no encuentra ninguna pieza es el número de casillas hasta el borde
		var1 = 8 - torre.coordenadas.getY();


	encontrado = false; //Se prepara para la siguiente búsqueda
	//Se comprueba dónde se encuentra la pieza más próxima en el semieje vertical negativo
	for (int i = torre.coordenadas.getY(); i >= 1; i--) {
		coordenadas_de_consulta.setXY(torre.coordenadas.getY(), i);

		//Comprobaciones de si hay una pieza del mismo color
		if (torre.getColor() && consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var2 = torre.coordenadas.getY() - i - 1;
		}
		else if (!torre.getColor() && consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var2 = torre.coordenadas.getY() - i - 1;
		}

		//Comprobaciones de si hay una pieza de distinto color
		if (!torre.getColor() && consultaBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var2 = torre.coordenadas.getY() - i;
		}
		else if (torre.getColor() && consultaNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var2 = i - torre.coordenadas.getY() - i;
		}
	}
	if (!encontrado)
		var2 = torre.coordenadas.getY() - 1;


	//Ya se ha calculado el número de coordenadas que hay que guardar por
	Coords* coordenadas_disponibles = new Coords[var1 + var2 + var3 + var4];

	for (int i = 0; i < var1; i++) //Semieje horizontal positivo
		(coordenadas_disponibles + i)->setXY(torre.coordenadas.getX()+i+1, torre.coordenadas.getY());
	for (int i = 0; i < var2; i++) //Semieje horizontal negativo
		(coordenadas_disponibles + var1 + i)->setXY(torre.coordenadas.getX() - i -1, torre.coordenadas.getY());
	for (int i = 0; i < var3; i++) //Semieje vertical positivo
		(coordenadas_disponibles + var1 + var2 + i)->setXY(torre.coordenadas.getX(), torre.coordenadas.getY() + i +1);
	for (int i = 0; i < var4; i++) //Semieje vertical negativo
		(coordenadas_disponibles + var1 + var2 + var3 + i)->setXY(torre.coordenadas.getX(), torre.coordenadas.getY() - i -1);

	return *coordenadas_disponibles;
}
