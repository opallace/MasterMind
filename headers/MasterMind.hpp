#ifndef _MASTERMIND_
#define _MASTERMIND_

#include <iostream>
#include <cstdlib>

using namespace std;

#include "Cores.hpp"
#include "CodeMaker.hpp"
#include "CodeBreaker.hpp"

using namespace Trabalho;

namespace Trabalho{
	class MasterMind {
		enum cores *cores;
		enum cores *codigo;
		enum cores **palpite;
		enum cores **feedback;

		int quantidade_cores;
		int tamanho_codigo;
		int quantidade_palpites;
		int difficulty;

		bool cores_repetidas;
		bool pvp;
		bool gameover;

		public:
			MasterMind();

			/* Setters */
				void setQuantidadeCores(int quantidade_cores);

				void setTamanhoCodigo(int tamanho_codigo);

				void setQuantidadePalpites(int quantidade_palpites);

				void setDifficulty(int difficulty);

				void setCoresRepetidas(bool cores_repetidas);

				void setPvp(bool pvp);

				void setGameOver(bool gameover);

			/* Getters */
				int getQuantidadeCores();

				int getTamanhoCodigo();

				int getQuantidadePalpites();

				int getDifficulty();

				bool getCoresRepetidas();

				bool getPvp();

				bool getGameOver();

			void set_config();

			bool checkPalpite(int round);

			void setFeedBack(int round);

			void load_game();

			void start_game(CodeMaker *codemaker, CodeBreaker *codebreaker);

			void show_board();
	};
}

#endif