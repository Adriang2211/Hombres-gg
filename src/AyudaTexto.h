#pragma once
#include <string>
#include "freeglut.h"
#include "ETSIDI.h"

using namespace std;

class AyudaTexto {
	public:
		static void tu_texto(string txt, int x, int y, float sep); //Escribir de izquierda a derecha
		static void tu_print(const char* txt, float x, float y);
};