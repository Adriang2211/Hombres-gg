#include "Peon.h"
#include "Tablero.h"

Peon::Peon(bool color, int x, int y, Tablero* t) {
	this->color = color;
	coordenadas.setX(x);
	coordenadas.setY(y);
	tab = t;
	primer_movimiento = true;
	id = PEON;
}


void Peon::movimientos()
{
	for (int i = 0; i < MAX_MOV; i++)
		coordenadas_disponibles[i] = { 9, 9 };
	int mov1 = 0;// 3 direecciones posibles para el peon
	Coords coordenas_de_consulta, coordenadas_de_consulta2;
	
	//Avanzar dos casillas
	if (primer_movimiento)
	{
		if (color)
		{
			coordenas_de_consulta.setXY(coordenadas.getX(), coordenadas.getY() + 2);
			coordenadas_de_consulta2.setXY(coordenadas.getX(), coordenadas.getY() + 1);
			if (!tab->consultaCasilla(coordenas_de_consulta) && !tab->consultaCasilla(coordenadas_de_consulta2))
			{
				coordenadas_disponibles[mov1].setXY(coordenadas.getX(), coordenadas.getY() + 2);//adelante
				mov1++;
			}
		}
		else if (!color)
		{
			coordenas_de_consulta.setXY(coordenadas.getX(), coordenadas.getY() - 2);
			coordenadas_de_consulta2.setXY(coordenadas.getX(), coordenadas.getY() - 1);
			if (!tab->consultaCasilla(coordenas_de_consulta) && !tab->consultaCasilla(coordenadas_de_consulta2))
			{
				coordenadas_disponibles[mov1].setXY(coordenadas.getX(), coordenadas.getY() - 2);//adelante
				mov1++;
			}
		}
	}

	//Avanzar una casilla
	if (color == true)
	{

		coordenas_de_consulta.setXY(coordenadas.getX(), coordenadas.getY() + 1);
		if (!tab->consultaCasilla(coordenas_de_consulta))
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


bool Peon::mover(Coords destino) {
	for (int i = 0; i < MAX_MOV; i++) {
		if (destino == coordenadas_disponibles[i]) {
			coordenadas = destino;
			return true;
		}
	}
	if (primer_movimiento)
		primer_movimiento = false;
	return false;
}

void Peon::dibuja() {
	if (color == true) {
		peonBlancas.setCenter(-coordenadas.getX()+1, -coordenadas.getY()+1);
		peonBlancas.setSize(1, 1);
		peonBlancas.draw();
	}
	else {
		peonNegras.setCenter(-coordenadas.getX()+1, -coordenadas.getY()+1);
		peonNegras.setSize(1, 1);
		peonNegras.draw();
	}
}