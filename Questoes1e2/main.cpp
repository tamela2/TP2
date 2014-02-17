#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

int main ()
{

	const std::string kPedeNome = "Por favor, digite o nome do arquivo que voce deseja ler: ";

	std::cout << kPedeNome;

	/*! \var std::string nome_do_arquivo
		\brief Variável declarada para armazenar o nome do arquivo */
	std::string nome_do_arquivo;

	std::cin >> nome_do_arquivo;

	/* \var std::ifstream entrada
	   \brief */
	std::ifstream entrada(nome_do_arquivo.c_str(), std::ifstream::in);

	while(!entrada.is_open()) {

		std::cout << std::endl << "Este arquivo nao existe ou nao pode ser aberto" << std::endl;
		std::cout << kPedeNome;

		std::cin >> nome_do_arquivo;
		entrada.open(nome_do_arquivo.c_str(), std::ifstream::in);

	}

	std::cout << "[Questao 1] Por favor, digite a string a ser procurada no arquivo: ";
	std::string string_a_ser_procurada;
	std::cin >> string_a_ser_procurada;

	// Deixa a string a ser procurada minuscula
	std::transform(string_a_ser_procurada.begin(), string_a_ser_procurada.end(), string_a_ser_procurada.begin(), ::tolower);

	unsigned int correspondencias = 0;

	typedef std::vector <std::string> VetorDePalavras;

	VetorDePalavras palavras;

	{
		std::string temporaria = "";

		while(!entrada.eof()) {
			entrada >> temporaria;

			// Deixa a string minuscula
			std::transform(temporaria.begin(), temporaria.end(), temporaria.begin(), ::tolower);

			// Usa a biblioteca algorithm para "limpar" a string, tirando virgulas e outros sinais de pontuacao
			temporaria.erase(std::remove(temporaria.begin(), temporaria.end(), ','), temporaria.end());
			temporaria.erase(std::remove(temporaria.begin(), temporaria.end(), '('), temporaria.end());
			temporaria.erase(std::remove(temporaria.begin(), temporaria.end(), ')'), temporaria.end());

			// std::cout << temporaria << std::endl;

			if(std::find(palavras.begin(), palavras.end(), temporaria) == palavras.end()) {
				palavras.push_back(temporaria);
			}

			if(temporaria == string_a_ser_procurada) {
				++correspondencias;
			}
		}
	}

	entrada.close();

	// Organiza as palavras por ordem alfabética
	std::sort(palavras.begin(), palavras.end());

	// Retira as palavras repetidas
	std::unique(palavras.begin(), palavras.end());

	std::cout << std::endl << "A string fornecida ocorre no arquivo " << correspondencias << " vez(es)" << std::endl;

	std::cout << std::endl << "Questao [2]. Este e o vetor de palavras encontradas no arquivo: " << std::endl;

	for(VetorDePalavras::iterator i = palavras.begin(); i != palavras.end(); ++i) {
		std::cout << *i << '\t';
	}

	std::cout << '\n';

	system("pause");

	return EXIT_SUCCESS;
}
