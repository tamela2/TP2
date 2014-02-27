#include <cstdlib>
#include <iostream>

#include "cwindow_.h"

void CWindow_::show(void) {
	std::cout << "Janela desenhada na posicao (" << x_ << ", " << y_ << ") com largura " << cx_ << " e altura " << cy_ << std::endl;
}

void CWindow_::textOut(const int& x, const int& y, const std::string& text) const {
	std::cout << "Escrevendo texto '" << text.c_str();
	std::cout << "' na posicao (" << x << ", " << y << ")" << std::endl;
}