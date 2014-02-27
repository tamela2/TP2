#include <iostream>
#include <stdlib.h>
#include <string>
#include <map>
#include "inteiro_gigante.h"

int main() {
	
	typedef std::map<std::string, InteiroGigante> TipoMapaInteirosGigantes;
	typedef TipoMapaInteirosGigantes::const_iterator IteradorInteirosGigantes;

	TipoMapaInteirosGigantes inteiros_gigantes;

	unsigned int opcao_escolhida = 0;

	enum Menu {
		/* Digite 0 para */ kSair,
		/* Digite 1 para */ kLerInteiroGigante,
		/* Digite 2 para */ kImprimirInteiroGigante,
		/* Digite 3 para */ kAdicionarInteiroGigante,
		/* Digite 4 para */ kSubtrairInteiroGigante,
		/* Digite 5 para */ kCompararInteirosGigantes,
	};
	
	do {
		std::cout << "= INTEIROS GIGANTES =" << std::endl;

		std::cout << std::endl << "Escolha uma opcao: ";
		std::cout << std::endl << "- Digite " << kSair << " para sair;";
		std::cout << std::endl << "- Digite " << kLerInteiroGigante << " para ler um inteiro gigante;";
		std::cout << std::endl << "- Digite " << kImprimirInteiroGigante << " para imprimir um inteiro gigante;";
		std::cout << std::endl << "- Digite " << kAdicionarInteiroGigante << " para adicionar um inteiro gigante a outro;";
		std::cout << std::endl << "- Digite " << kSubtrairInteiroGigante << " para subtrair dois inteiros gigantes;";
		std::cout << std::endl << "- Digite " << kCompararInteirosGigantes << " para comparar dois inteiros gigantes;";
		std::cout << std::endl;
		std::cout << std::endl << ">>>>>>>>>";

		std::cin >> opcao_escolhida;

		if (opcao_escolhida == kSair) {
			std::cout << std::endl << "Tchau!" << std::endl;
			system("pause");
			return EXIT_SUCCESS;
		}

		std::cout << std::endl << "Estas sao as variaveis atualmente criadas por voce: " << std::endl;

		for(IteradorInteirosGigantes i = inteiros_gigantes.begin(); i != inteiros_gigantes.end(); ++i) {
			std::cout << std::endl << i->first << '\t';
			inteiros_gigantes[i->first].ImprimaInteiroGigante();
		}

		std::cout << std::endl;

		if (opcao_escolhida == kLerInteiroGigante) {
			
			std::string nome_variavel, valor_variavel;

			std::cout << "Por favor, digite um nome para a variavel que armazenara o inteiro gigante" << std::endl;
			std::cout << ">>> ";
			std::cin >> nome_variavel;

			std::cout << "Por favor, digite agora o valor do numero gigante" << std::endl;
			std::cout << ">>> ";
			std::cin >> valor_variavel;

			inteiros_gigantes[nome_variavel] = valor_variavel;

			std::cout << std::endl << "Sua variavel foi criada. Imprimindo: ";
			inteiros_gigantes[nome_variavel].ImprimaInteiroGigante();
			std::cout << std::endl;
		}

		else if(opcao_escolhida == kImprimirInteiroGigante) {

			std::string nome_variavel;
			std::cout << "Por favor, digite o nome da variavel que deseja imprimir." << std::endl;
			std::cout << ">>> ";
			std::cin >> nome_variavel;

			std::cout << std::endl << "Imprimindo " << nome_variavel << ": ";
			inteiros_gigantes[nome_variavel].ImprimaInteiroGigante();
			std::cout << std::endl;

		}

		else if(opcao_escolhida == kAdicionarInteiroGigante) {

			std::string nome_parcela1;
			std::cout << std::endl << "Por favor, digite o nome da variavel da primeira parcela." << std::endl;
			std::cout << ">>> ";
			std::cin >> nome_parcela1;
			std::cout << nome_parcela1 << "=";
			inteiros_gigantes[nome_parcela1].ImprimaInteiroGigante();

			std::string nome_parcela2;
			std::cout << std::endl << "Por favor, digite o nome da variavel da primeira parcela." << std::endl;
			std::cout << ">>> ";
			std::cin >> nome_parcela2;
			std::cout << nome_parcela2 << "=";
			inteiros_gigantes[nome_parcela2].ImprimaInteiroGigante();

			std::cout << std::endl;
			inteiros_gigantes[nome_parcela1].ImprimaInteiroGigante();
			std::cout << " + ";
			inteiros_gigantes[nome_parcela2].ImprimaInteiroGigante();
			std::cout << " = ";

			inteiros_gigantes[nome_parcela1].AdicioneInteiroGigante(inteiros_gigantes[nome_parcela2]);
			inteiros_gigantes[nome_parcela1].ImprimaInteiroGigante();

		}

		else if(opcao_escolhida == kSubtrairInteiroGigante) {

			std::string nome_minuendo;
			std::cout << std::endl << "Por favor, digite o nome da variavel do minuendo." << std::endl;
			std::cout << ">>> ";
			std::cin >> nome_minuendo;
			std::cout << nome_minuendo << "=";
			inteiros_gigantes[nome_minuendo].ImprimaInteiroGigante();

			std::string nome_subtraendo;
			std::cout << std::endl << "Por favor, digite o nome da variavel do subtraendo." << std::endl;
			std::cout << ">>> ";
			std::cin >> nome_subtraendo;
			std::cout << nome_subtraendo << "=";
			inteiros_gigantes[nome_subtraendo].ImprimaInteiroGigante();

			std::cout << std::endl;
			inteiros_gigantes[nome_minuendo].ImprimaInteiroGigante();
			std::cout << " - ";
			inteiros_gigantes[nome_subtraendo].ImprimaInteiroGigante();
			std::cout << " = ";

			inteiros_gigantes[nome_minuendo].SubtraiaInteiroGigante(inteiros_gigantes[nome_subtraendo]);
			inteiros_gigantes[nome_minuendo].ImprimaInteiroGigante();

		}
		
		else if(opcao_escolhida == kCompararInteirosGigantes) {

			std::string nome_variavel1;
			std::cout << std::endl << "Por favor, digite o nome da primeira variaval a ser comparada." << std::endl;
			std::cout << ">>> ";
			std::cin >> nome_variavel1;
			std::cout << nome_variavel1 << "=";
			inteiros_gigantes[nome_variavel1].ImprimaInteiroGigante();

			std::string nome_variavel2;
			std::cout << std::endl << "Por favor, digite o nome da segunda variaval a ser comparada." << std::endl;
			std::cout << ">>> ";
			std::cin >> nome_variavel2;
			std::cout << nome_variavel2 << "=";
			inteiros_gigantes[nome_variavel2].ImprimaInteiroGigante();

			if(inteiros_gigantes[nome_variavel1].EIgualA(inteiros_gigantes[nome_variavel2])) {
				std::cout << std::endl << nome_variavel1 << " e igual a " << nome_variavel2;
			}
			if(inteiros_gigantes[nome_variavel1].NaoEIgualA(inteiros_gigantes[nome_variavel2])) {
				std::cout << std::endl << nome_variavel1 << " nao e igual a " << nome_variavel2;
			}
			if(inteiros_gigantes[nome_variavel1].EMaiorQue(inteiros_gigantes[nome_variavel2])) {
				std::cout << std::endl << nome_variavel1 << " e maior que " << nome_variavel2;
			}
			if(inteiros_gigantes[nome_variavel1].EMenorQue(inteiros_gigantes[nome_variavel2])) {
				std::cout << std::endl << nome_variavel1 << " e menor que " << nome_variavel2;
			}
			if(inteiros_gigantes[nome_variavel1].EMaiorOuIgualA(inteiros_gigantes[nome_variavel2])) {
				std::cout << std::endl << nome_variavel1 << " e maior ou igual a " << nome_variavel2;
			}
			if(inteiros_gigantes[nome_variavel1].EMenorOuIgualA(inteiros_gigantes[nome_variavel2])) {
				std::cout << std::endl << nome_variavel1 << " e menor ou igual a " << nome_variavel2;
			}

		}

		else {
			std::cout << std::endl << "Opcao invalida." << std::endl;
		}

		std::cout << std::endl;
		system("pause");
		system("cls");

	} while(opcao_escolhida != kSair);
	
	return EXIT_SUCCESS;

}