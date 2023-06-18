#ifndef _BOT_
#define _BOT_

#include "CodeMaker.hpp"
#include "Cores.hpp"

#include <ctime>
#include <algorithm>

using namespace Trabalho;

namespace Trabalho{
	class Bot: public CodeMaker{
		public:
			enum cores* cria_codigo(int tamanho_codigo, int quantidade_cores, int cores_repetidas) override;
	};
}

#endif