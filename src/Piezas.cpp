#include "Piezas.h"
#include "Posicionamiento.h"
#include "Tablero.h"
#include <iostream>
#include "Torre.h"
#include "caballo.h"
#include "Alfil.h"
#include "Dama.h"
#include "Peon.h"

bool Pieza::getColor()
{
	return color;
};

Coords Pieza::getCoordenadas()
{
	return coordenadas;
};

void Pieza::setCoordenadas(int x, int y)
{
	coordenadas.setXY(x, y);
};

void Pieza::setCoordenadas(Coords a) { coordenadas = a; }
void Pieza::setColor(bool _color) { color = _color; }


bool Pieza::mover(Coords destino) {
	//Esta función detecta si el movimiento introducido es válido.
	//Lo hace en función de los datos ya calculados con los movimientos posibles y comprueba
	//también si se producen jaques descubiertos, que son más difíciles de detectar antes de haber probado a hacer
	//el movimiento, cosa que se hace en esta función.
	Coords coordenadas_originales = coordenadas;
	Pieza* devolver = nullptr;
	int id_copia;
	Coords coordenadas_copia;
	bool color_copia;
	bool intenta_comer = false;
	for (int i = 0; i < MAX_MOV; i++) {
		if (destino == coordenadas_disponibles[i]) {
			if (tab->consultaCasilla(destino)) { //Comprueba si hay una pieza para comerla (eliminarla)
				id_copia = tab->getPiezaEn(destino)->id;
				coordenadas_copia = tab->getPiezaEn(destino)->getCoordenadas();
				color_copia = tab->getPiezaEn(destino)->getColor();
				intenta_comer = true;
				tab->lista_piezas.eliminarPieza(tab->getIndexPiezaEn(destino));
			}

			coordenadas = destino; //Actualiza la posición de la pieza

			//Comprobación de si es un enroque (debe hacerse antes de actualizar coordenadas disponibles)

			//Enorque corto blancas
			if (id == REY && destino == (Coords{ g, 1 }) && coordenadas_originales == (Coords{ e, 1 })) {
				tab->getPiezaEn({ h, 1 })->setCoordenadas({ f, 1 });
				tab->actualizarCasillasOcupadas();
				tab->actualizarMovimientosPosibles();
				return true; //Ya se hicieron el resto de comprobaciones al detectar la posibilidad de enrocar
			}
			//Enroque largo blancas
			if (id == REY && destino == (Coords{ c, 1 }) && coordenadas_originales == (Coords{ e, 1 })) {
				tab->getPiezaEn({ a, 1 })->setCoordenadas({ d, 1 });
				tab->actualizarCasillasOcupadas();
				tab->actualizarMovimientosPosibles();
				return true;
			}

			//Enroque corto negras
			if (id == REY && destino == (Coords{ g, 8 }) && coordenadas_originales == (Coords{ e, 8 })) {
				tab->getPiezaEn({ h, 8 })->setCoordenadas({ f, 8 });
				tab->actualizarCasillasOcupadas();
				tab->actualizarMovimientosPosibles();
				return true;
			}

			//Enroque largo negras
			if (id == REY && destino == (Coords{ c, 8 }) && coordenadas_originales == (Coords{ e, 8 })) {
				tab->getPiezaEn({ a, 8 })->setCoordenadas({ d, 8 });
				tab->actualizarCasillasOcupadas();
				tab->actualizarMovimientosPosibles();
				return true;
			}


			tab->actualizarCasillasOcupadas();
			tab->actualizarMovimientosPosibles();
			
			//En caso de jaque reestablecer la situación inicial y salir devolviendo false.
			if (tab->jaqueAlRey(getColor())) {
				coordenadas = coordenadas_originales;
				if (intenta_comer) {
					switch (id_copia) {
					case 1:
						devolver = new Torre(color_copia, coordenadas_copia.getX(), coordenadas_copia.getY(), this->tab);
						tab->lista_piezas.agregarPieza(devolver);
						break;
					case 2:
						devolver = new Caballo(color_copia, coordenadas_copia.getX(), coordenadas_copia.getY(), this->tab);
						tab->lista_piezas.agregarPieza(devolver);
						break;
					case 3:
						devolver = new Alfil (color_copia, coordenadas_copia.getX(), coordenadas_copia.getY(), this->tab);
						tab->lista_piezas.agregarPieza(devolver);
						break;
					case 4:
						devolver = new Dama(color_copia, coordenadas_copia.getX(), coordenadas_copia.getY(), this->tab);
						tab->lista_piezas.agregarPieza(devolver);
						break;
					case 6:
						devolver = new Peon(color_copia, coordenadas_copia.getX(), coordenadas_copia.getY(), this -> tab);
						tab->lista_piezas.agregarPieza(devolver);
						break;
					}
				}
					
				return false;
			}
			tab->actualizarCasillasOcupadas();
			tab->actualizarMovimientosPosibles();
			return true;
		}
	}
	return false;
}


void Pieza::dibuja(int opc) {
	;
}