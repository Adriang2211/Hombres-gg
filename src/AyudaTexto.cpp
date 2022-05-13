#include "AyudaTexto.h"

void AyudaTexto::tu_texto(string txt, int x, int y, float sep) {

	int i = txt.length(); //almacenamos en i la longitud de la cadena
	//ahora hay que darle la vuelta
	string reves(txt);//le asignamos el texto a una nueva string que se llama reves
	reverse(reves.begin(), reves.end()); //le damos la vuelta
	for (int n = 0; n < i; n++) {
		string aux, prev, post;
		aux = reves[n];
		const char* texto = aux.c_str();
		if (n != 0 && n!= i) { //si no estamos en las posicoines extremas
			post = reves[n - 1];
			prev = reves[n + 1];
				if ((aux == "l" || aux == "i" || aux == "I") && prev == " ") {
					tu_print(texto, x - (n * sep) + 0.3, y);
				}
				else if ((aux == "l" || aux == "i" || aux == "I") && post == " ") {
					tu_print(texto, x - (n * sep) - 0.05, y);
				}
				else if ((aux == "l" || aux == "i" || aux == "I") && post != " " && prev != " ") {
					tu_print(texto, x - (n * sep) + 0.1, y);
				}
				else if (aux == "m") {
					tu_print(texto, x - (n * sep) - 0.05, y);
				}
				else {
					tu_print(texto, x - (n * sep), y);
				}

		}
		else { //Si estamos en las posiciones extremas
			tu_print(texto, x - (n * sep), y);
		}
		
	}

}

void AyudaTexto::tu_print(const char* txt, float x, float y) {

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glTranslated(x, y, 0);
	ETSIDI::print(txt);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glPopMatrix();
}