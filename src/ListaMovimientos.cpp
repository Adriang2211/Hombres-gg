#include "ListaMovimientos.h"

ListaMovimientos::ListaMovimientos()
{
	numero = 0;
}

bool ListaMovimientos::agregar(Movimiento mov)
{
	if (numero >= MAX_MOVIMIENTOS)
		return false; //Sin espacio para nuevos movimientos
	for (int i = 0; i < numero; i++) {
		if (mov == *lista[i])
			return false; //Movimiento repetido
	}
	lista[numero++] = new Movimiento(mov);
	return false;
}


void ListaMovimientos::eliminar() {
	for (int i = numero; i > 0; i--)
		delete lista[i];
	numero=0;
}