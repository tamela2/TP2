#include <stdlib.h>

#include "cwindow_.h"

int main() {

	CWindow_ janela1 (1, 1, 100, 200);
	CWindow_ janela2 (110, 220, 120, 100);

	Color_ c1(255, 0, 0); // RGB ==> vermelho
	janela1.setTextColor(c1);
	janela1.textOut(3, 5, "Alo Mundo com Janelas Orientadas a Objetos");

	system("pause");

	return EXIT_SUCCESS;
}