#include "headers/Cores.hpp"
#include "headers/CodeBreaker.hpp"

enum cores* Trabalho::CodeBreaker::cria_palpite(int tamanho_codigo){
	enum cores *palpite  = (enum cores *)malloc(sizeof(enum cores *) * tamanho_codigo);

	cout << "Digite o palpite: " << endl;

	for (int i = 0; i < tamanho_codigo; ++i){
		char cor;
		cin >> cor;

		palpite[i] = Cores::charToColor(cor);
	}

	return palpite;
}