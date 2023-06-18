#ifndef _CORES_
#define _CORES_

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

enum cores {
		branco,
		preto,
		cinza,
		azul,
		vermelho,
		dourado,
		sepia,
		rosa,
		laranja,
		marrom,
		turquesa,
		null
	};

namespace Trabalho{
	class Cores{
		public:
			static enum cores intToColors(int cor);
			
			static enum cores charToColor(char cor);

			static string colorsToString(enum cores cor);

			static string colorsToChar(enum cores cor);
	};
}

#endif