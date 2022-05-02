#include "Dama.h"
#include "Tablero.h"






bool Dama::mover(Coords destino) {
	for (int i = 0; i < MAX_MOV; i++) {
		if (destino == coordenadas_disponibles[i]) {
			coordenadas = destino;
			return true;
		}
	}
	return false;
}