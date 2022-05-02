#include "Peon.h"
#include "Tablero.h"


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


bool Peon::mover(Coords destino) {
	for (int i = 0; i < MAX_MOV; i++) {
		if (destino == coordenadas_disponibles[i]) {
			coordenadas = destino;
			return true;
		}
	}
	return false;
}