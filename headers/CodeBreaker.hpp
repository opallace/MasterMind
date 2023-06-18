#ifndef _CODEBREAKER_
#define _CODEBREAKER_

#include <iostream>

using namespace std;

#include "Jogador.hpp"
#include "Cores.hpp"

using namespace Trabalho;

namespace Trabalho{
	class CodeBreaker: public Jogador{
		public:
			enum cores* cria_palpite(int tamanho_codigo);
	};
}

#endif