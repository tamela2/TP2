#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <math.h>
#include "inteiro_gigante.h"

InteiroGigante::Indice InteiroGigante::ContaDigitos(const int& inteiro) {

	int temporario = inteiro;
	unsigned int contador = 0;

	if(temporario < 10) {
		return 1;
	}
	while (temporario != 0) {
		temporario /= 10; /* inteiro = inteiro / 10 */
		++contador;
	}
	return contador;
}

void InteiroGigante::LeiaInteiroGigante(int inteiro) {

	double tamanho = ContaDigitos(inteiro);
	tamanho_ = static_cast<unsigned int> (tamanho);
	double divisor = pow(10, tamanho - 1); /* se o numero tiver 6 digitos, por ex... o divisor sera 10 elevado a 5 */

	for(; tamanho > 0; --tamanho, divisor /= 10) {
		unsigned int algarismo = static_cast<int> (inteiro/divisor);
		vetor_.push_back(algarismo);
		inteiro -= static_cast<int> (algarismo*divisor);
	}
}

void InteiroGigante::LeiaInteiroGigante(const std::string& inteiro) {
	double tamanho = ContaDigitos(inteiro);
	tamanho_ = static_cast<unsigned int> (tamanho);

	for(unsigned int i = 0; i < tamanho; ++i) {
		std::string algarismo = inteiro.substr(i, 1);
		vetor_.push_back(std::stoi(algarismo));
	}
}

const void InteiroGigante::ImprimaInteiroGigante(void) {
	for(TipoVetor::const_iterator i = vetor_.begin(); i != vetor_.end(); ++i) {
		//if(i != vetor_.begin() || *i != 0) {
			std::cout << *i;
		//}
	}
}

InteiroGigante::TipoVetor InteiroGigante::ObterDigitos(const InteiroGigante& inteiro, const Indice& de, const Indice& quantidade) {

	TipoVetor temporario;
	if(quantidade == 0) { return temporario; }

	Indice contador=0;

	TipoVetor::const_iterator i = inteiro.vetor_.begin();

	for(; contador < quantidade && i != inteiro.vetor_.end(); ++contador, ++i) {
		temporario.push_back(*i);
	}

	return temporario;
}

void InteiroGigante::AdicioneInteiroGigante(const InteiroGigante& inteiro) {
	
	NumeroInterno soma = 0;
	NumeroInterno sobra = 0;

	TipoVetor temporario;
	TipoVetor::const_reverse_iterator i = vetor_.rbegin();
	TipoVetor::const_reverse_iterator j = inteiro.vetor_.rbegin();

	for(; i != vetor_.rend() && j != inteiro.vetor_.rend(); i++, j++) {
		soma = *i + *j + sobra;
		if(soma <= 9) {
			sobra = 0;
		}
		else {
			soma -= 10;
			sobra = 1;
		}
		temporario.push_back(soma);
	}

	std::reverse(temporario.begin(), temporario.end());

	Indice tamanho_parcela_1 = tamanho_;
	Indice tamanho_parcela_2 = inteiro.tamanho_;
	int diferenca_tamanho = tamanho_parcela_1 - tamanho_parcela_2;

	TipoVetor resultado;

	if(abs(diferenca_tamanho)) {
		if(diferenca_tamanho > 0) {
			resultado = ObterDigitos(*this, 0, abs(diferenca_tamanho));
		}
		else {
			resultado = inteiro.ObterDigitos(inteiro, 0, abs(diferenca_tamanho));
		}
		resultado.insert(resultado.end(), temporario.begin(), temporario.end());
		if(sobra > 0) {
			tamanho_++;
			resultado[abs(diferenca_tamanho)-1] += sobra;
		}
		vetor_ = resultado;
	}
	else {
		if(sobra>0) {
			temporario.push_back(sobra);
		}
		vetor_ = temporario;
	}
	vetor_ = temporario;
}

void InteiroGigante::SubtraiaInteiroGigante(const InteiroGigante& inteiro) {

	TipoVetor temporario;
	NumeroInterno diferenca = 0;
	NumeroInterno falta = 0;

	if(EIgualA(inteiro)) {
		temporario.push_back(diferenca);
		vetor_ = temporario;
		return;
	}
	
	TipoVetor::const_reverse_iterator i = vetor_.rbegin();
	TipoVetor::const_reverse_iterator j = inteiro.vetor_.rbegin();

	for(; i != vetor_.rend() && j != inteiro.vetor_.rend(); i++, j++) {
		diferenca = (*i - *j) - falta;
		if (diferenca < 10) {
			falta = 0;
		}
		else {
			diferenca += 10;
			falta = 1;
		}
		temporario.push_back(diferenca);
	}

	std::reverse(temporario.begin(), temporario.end());

	Indice tamanho_parcela_1 = tamanho_;
	Indice tamanho_parcela_2 = inteiro.tamanho_;
	int diferenca_tamanho = tamanho_parcela_1 - tamanho_parcela_2;

	TipoVetor resultado;

	if(abs(diferenca_tamanho)) {
		if(diferenca_tamanho > 0) {
			resultado = ObterDigitos(*this, 0, abs(diferenca_tamanho));
		}
		else {
			resultado = inteiro.ObterDigitos(inteiro, 0, abs(diferenca_tamanho));
		}
		resultado.insert(resultado.end(), temporario.begin(), temporario.end());
		resultado[abs(diferenca_tamanho)-1] -= falta;

		vetor_ = resultado;
	}
	else {
		if(falta>0) {
			--temporario[0];
		}

		vetor_ = temporario;
	}

	while(vetor_[0] == 0) {
		--tamanho_;
		vetor_.erase(vetor_.begin());
	}

}


std::string InteiroGigante::ToString() {
	std::string temporaria = "";
	long double algarismo;
	for(TipoVetor::const_iterator i = vetor_.begin(); i != vetor_.end(); ++i) {
		algarismo = static_cast<long int> (*i);
		temporaria += std::to_string(algarismo);
	}
	return temporaria;
}

const bool InteiroGigante::EIgualA(const InteiroGigante& inteiro) {
	
	if(tamanho_ != inteiro.tamanho_) { return false; }

	TipoVetor::const_iterator i, j;

	for(i = vetor_.begin(), j = inteiro.vetor_.begin(); i != vetor_.end() && j != inteiro.vetor_.end(); i++, j++) {
		if(*i != *j) {
			return false;
		}
	}

	return true;
}

const bool InteiroGigante::EMaiorQue(const InteiroGigante& inteiro) {

	if(EIgualA(inteiro)) { return false; }
	if(tamanho()>inteiro.tamanho_) { return true; }

	TipoVetor::const_iterator i, j;

	for(i = vetor_.begin(), j = inteiro.vetor_.begin(); i != vetor_.end() && j != inteiro.vetor_.end(); i++, j++) {
		if(*i > *j) {
			return true;
		}
		else if(*i < *j) {
			return false;
		}
		else {
			continue;
		}
	}

	return false;
}

const bool InteiroGigante::EMenorQue(const InteiroGigante& inteiro) {

	if(EIgualA(inteiro)) { return false; }
	if(tamanho()<inteiro.tamanho_) { return true; }

	TipoVetor::const_iterator i, j;

	for(i = vetor_.begin(), j = inteiro.vetor_.begin(); i != vetor_.end() && j != inteiro.vetor_.end(); i++, j++) {
		if(*i < *j) {
			return true;
		}
		else if(*i > *j) {
			return false;
		}
		else {
			continue;
		}
	}

	return false;
}