#include <iostream>
#include <string>

#include "headers/MasterMind.hpp"
#include "headers/CodeMaker.hpp"
#include "headers/CodeBreaker.hpp"
#include "headers/Bot.hpp"

using namespace std;
using namespace Trabalho;

int main(){

	cout << "==============================================" << endl;
	cout << "=                                            =" << endl;
	cout << "=                 MASTERMIND                 =" << endl;
	cout << "=                                            =" << endl;
	cout << "==============================================" << endl << endl;

	cout << "1 - Jogar" << endl;
	cout << "2 - Configurar" << endl;
	cout << "3 - Regras" << endl;
	cout << "4 - Sair" << endl;

	MasterMind jogo = MasterMind();
	CodeMaker codemaker;
	CodeBreaker codebreaker;
	Bot bot;

	int exit = 1;
	
	while(exit){
		int option;

		cout << endl << "> ";
		cin >> option;

		switch(option){
			case 1:
				jogo.load_game();

				switch(jogo.getPvp()){
					case true:
						{
							
							string nomeCodeMaker;
							string nomeCodeBreaker;

							cout << "Insira o nome do codemaker: ";
							cin >> nomeCodeMaker;

							cout << "Insira o nome do codebreaker: ";
							cin >> nomeCodeBreaker;

							codemaker.setNome(nomeCodeMaker);
							codemaker.setPontos(0);

							codebreaker.setNome(nomeCodeBreaker);
							codebreaker.setPontos(0);

							jogo.start_game(&codemaker, &codebreaker);
								
						}break;

					case false:
						{
							bot.setNome("[BOT] Wagner");
							bot.setPontos(0);

							string nomeCodeBreaker;

							cout << "Insira o nome do codebreaker: ";
							cin >> nomeCodeBreaker;

							codebreaker.setNome(nomeCodeBreaker);
							codebreaker.setPontos(0);

							jogo.start_game(&bot, &codebreaker);
						
						}break;
				}

				break;
			case 2:
				jogo.set_config();
				break;
			case 3:
				cout << endl;
				cout << "Regras " << endl << endl;
				cout << "1 - O jogador 1(codemaker) escolhe uma sequência de cores que o jogador 2 (codebreaker) tem que adivinhar." << endl;
				cout << "2 - O codebreaker dá um palpite, escolhendo sua própria sequência de cores. O objetivo do codebreaker é adivinhar tanto as cores quanto as posições" << endl;
				cout << "3 - A cada palpite, o codemaker retorna uma sequência com o mesmo número de peças da sequência a ser descoberta, indicando o quão correto está o palpite dado. Nesta sequência, uma peça preta indica cor e posição corretos, uma peça branca indica cor correta em posição errada e uma peça cinza indica que ambas cor e posição estão erradas." << endl;
				cout << "4 - O codebreaker deve usar essa informação para tentar novamente um novo palpite, até ele acerte a sequência de cores na ordem correta ou o número de palpites acabem." << endl;

				break;
			case 4:
				exit = 0;
				break;
		}
	}
	
	return 0;
}