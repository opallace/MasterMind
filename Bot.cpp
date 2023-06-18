#include "headers/Cores.hpp"
#include "headers/Bot.hpp"

enum cores* Trabalho::Bot::cria_codigo(int tamanho_codigo, int quantidade_cores, int cores_repetidas){
	srand(time(NULL));
	
	enum cores* codigo = (enum cores *)malloc(sizeof(enum cores *) * tamanho_codigo);

	if(cores_repetidas){
		for (int i = 0; i < tamanho_codigo; ++i){
			codigo[i] = Cores::intToColors(rand() % quantidade_cores);
		}
	}else {
		for (int i = 0; i < tamanho_codigo; ++i){
			codigo[i] = Cores::intToColors(i);
		}

		for (int i = 0; i < tamanho_codigo; ++i){
			int j = rand() % quantidade_cores;
			enum cores temp = codigo[i];
			codigo[i] = codigo[j];
			codigo[j] = temp;
		}
	}

	return codigo;
}