#ifndef INTEIRO_GIGANTE_H

#include <string>
#include <vector>

#define INTEIRO_GIGANTE_H

class InteiroGigante
{
private:
	typedef unsigned int Indice;
	Indice tamanho_;
	/* vetor que armazena inteiros de tamanho arbitrário */
	typedef short unsigned int NumeroInterno;
	typedef std::vector<NumeroInterno> TipoVetor;
	TipoVetor vetor_;
	static Indice ContaDigitos(const int&);
	inline static Indice InteiroGigante::ContaDigitos(std::string inteiro) { return inteiro.size(); }
	static TipoVetor ObterDigitos(const InteiroGigante&, const Indice& de, const Indice& quantidade);
public:
	inline const Indice tamanho(void) { return tamanho_; } /* acessor */
	inline InteiroGigante(void) {}
	inline InteiroGigante(const std::string& inteiro) { LeiaInteiroGigante(inteiro); }
	inline InteiroGigante(const int& inteiro) { LeiaInteiroGigante(inteiro); }
	inline ~InteiroGigante(void) { vetor_.clear(); }
	void LeiaInteiroGigante(int);
	void LeiaInteiroGigante(const std::string&);
	void AdicioneInteiroGigante(const InteiroGigante&);
	void SubtraiaInteiroGigante(const InteiroGigante&);
	const void ImprimaInteiroGigante(void);
	const bool EIgualA(const InteiroGigante&);
	inline const bool NaoEIgualA(const InteiroGigante& inteiro) { return (tamanho() != inteiro.tamanho_) || !EIgualA(inteiro); }
	const bool EMaiorQue(const InteiroGigante&);
	const bool EMenorQue(const InteiroGigante&);
	inline const bool EMaiorOuIgualA(const InteiroGigante& inteiro) { return EIgualA(inteiro) || !EMenorQue(inteiro); }
	inline const bool EMenorOuIgualA(const InteiroGigante& inteiro) { return EIgualA(inteiro) || !EMaiorQue(inteiro); }
	std::string ToString();
};

#endif