#include "Interacciones.h"
#include "Piezas.h"

bool Interacciones::consultaBlancas(Coords& const coordenada) {
	for (int i = 0; i < 16; i++) {
		if (casillas_ocupadas_blancas[i].getX() == coordenada.getX() && casillas_ocupadas_blancas[i].getX() == coordenada.getX())
			return true;
	}
	return false;
}

bool Interacciones::consultaNegras(Coords& const coordenada) {
	for (int i = 0; i < 16; i++) {
		if (casillas_ocupadas_negras[i].getX() == coordenada.getX() && casillas_ocupadas_negras[i].getX() == coordenada.getX())
			return true;
	}
	return false;
}

/*
Coords Interacciones::movimientos(Torre& const torre) {
	int var1=0, var2=0, var3=0, var4=0;
	bool encontrado = false;

	//Primero se comprueba dónde se encuentra la pieza más próxima en el semieje horizontal positivo
	for (int i = torre.coordenadas.getX(); i <= 8; i++) {
		Coords coordenadas_de_consulta = {i, torre.coordenadas.getY() };

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
		Coords coordenadas_de_consulta = {i, torre.coordenadas.getY() };

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
		Coords coordenadas_de_consulta = { torre.coordenadas.getX(), i };

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
		Coords coordenadas_de_consulta = { torre.coordenadas.getX(), i };

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
	for (int i = 0; i < var1; i++)
		(coordenadas_disponibles + i)->setXY(torre.coordenadas.getX()+i, torre.coordenadas.getY());
	for (int i = 0; i < var2; i++)
		(coordenadas_disponibles + var1 + i)->setXY(torre.coordenadas.getX() - i, torre.coordenadas.getY());
	for (int i = 0; i < var3; i++)
		(coordenadas_disponibles + var1 + var2 + i)->setXY(torre.coordenadas.getX(), torre.coordenadas.getY() + i);
	for (int i = 0; i < var4; i++)
		(coordenadas_disponibles + var1 + var2 + var3 + i)->setXY(torre.coordenadas.getX(), torre.coordenadas.getY() - i);

	return *coordenadas_disponibles;
}
*/