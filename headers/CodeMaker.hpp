#ifndef _CODEMAKER_
#define _CODEMAKER_

#include <iostream>

using namespace std;

#include "Jogador.hpp"
#include "Cores.hpp"

using namespace Trabalho;

namespace Trabalho{
	class CodeMaker: public Jogador{
		public:
			virtual enum cores* cria_codigo(int tamanho_codigo, int quantidade_cores, int cores_repetidas);

			bool tem_cores_repetidas(enum cores* codigo, int tamanho_codigo);

	};
}

#endif