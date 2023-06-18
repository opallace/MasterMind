#ifndef _JOGADOR_
#define _JOGADOR_

#include <string>
using namespace std;

namespace Trabalho{
	class Jogador{
		protected:
			string nome;
			int pontos;
		
		public:
			/* Setters */
				void setNome(string nome);

				void setPontos(int pontos);

			/* Getters */
				string getNome();

				int getPontos();
	};
}

#endif