#include "headers/Cores.hpp"
#include "headers/CodeMaker.hpp"

enum cores* Trabalho::CodeMaker::cria_codigo(int tamanho_codigo, int quantidade_cores, int cores_repetidas){
	enum cores* codigo = (enum cores *)malloc(sizeof(enum cores *) * tamanho_codigo);



	cout << "Digite as cores do código: " << endl;

	for (int i = 0; i < tamanho_codigo; i++){
		char cor;
		cin >> cor;

		codigo[i] = Cores::charToColor(cor);
	}

	return codigo;
}

bool Trabalho::CodeMaker::tem_cores_repetidas(enum cores* codigo, int tamanho_codigo){
	for (int i = 0; i < tamanho_codigo; ++i){
		for (int j = i + 1; j < tamanho_codigo; ++j){
			if(codigo[i] == codigo[j]){
				return true;
			}
		}
	}

	return false;
}