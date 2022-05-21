#include "ListaPiezas.h"
#include "Posicionamiento.h"
#include "Piezas.h"

ListaPiezas::ListaPiezas() {
	for (int i = 0; i < NUMERO_DE_PIEZAS; i++)
		piezas[i] = nullptr;
	numero = 0;
}

Pieza* ListaPiezas::getPiezaEn(Coords const coordenada)
{
	for (int i = 0; i < numero; i++) {
		if (piezas[i]->getCoordenadas() == coordenada)
			return piezas[i]; //devuelve puntero a la pieza
	}
	return nullptr; //No devuelve nada si en esa casilla no hay ninguna pieza.
}

bool ListaPiezas::agregarPieza(Pieza* p) {
	if (numero < NUMERO_DE_PIEZAS) {
		piezas[numero++] = p;
		return true;
	}
	else
		return false;
}

void ListaPiezas::eliminarPieza(int index) {
	delete piezas[index];
	for (int i = index; i < numero; i++) {
		piezas[i] = piezas[i + 1];
	}
	numero--;
}

int ListaPiezas::getIndexPiezaEn(Coords const coordenada) {
	for (int i = 0; i < numero; i++) {
		if (piezas[i]->getCoordenadas() == coordenada)
			return i; //devuelve puntero a la pieza
	}
	return NULL; //No devuelve nada si en esa casilla no hay ninguna pieza.
}

void ListaPiezas::eliminar() {
	for (int i = numero  - 1; i > 0; i--)
		delete piezas[i];
	numero = 0;
}