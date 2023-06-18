#include "headers/MasterMind.hpp"

MasterMind::MasterMind(){
	setQuantidadeCores(8);
	setTamanhoCodigo(5);
	setQuantidadePalpites(10);
	setCoresRepetidas(true);
	setPvp(false);
	setGameOver(false);
}

void Trabalho::MasterMind::setQuantidadeCores(int quantidade_cores){
	this->quantidade_cores = quantidade_cores;
}

void Trabalho::MasterMind::setTamanhoCodigo(int tamanho_codigo){
	this->tamanho_codigo = tamanho_codigo;
}

void Trabalho::MasterMind::setQuantidadePalpites(int quantidade_palpites){
	this->quantidade_palpites = quantidade_palpites;
}

void Trabalho::MasterMind::setDifficulty(int difficulty){
	this->difficulty = difficulty;
}

void Trabalho::MasterMind::setCoresRepetidas(bool cores_repetidas){
	this->cores_repetidas = cores_repetidas;
}

void Trabalho::MasterMind::setPvp(bool pvp){
	this->pvp = pvp;
}

void Trabalho::MasterMind::setGameOver(bool gameover){
	this->gameover = gameover;
}

int Trabalho::MasterMind::getQuantidadeCores(){
	return this->quantidade_cores;
}

int Trabalho::MasterMind::getTamanhoCodigo(){
	return this->tamanho_codigo;
}

int Trabalho::MasterMind::getQuantidadePalpites(){
	return this->quantidade_palpites;
}

int Trabalho::MasterMind::getDifficulty(){
	return this->difficulty;
}

bool Trabalho::MasterMind::getCoresRepetidas(){
	return this->cores_repetidas;
}

bool Trabalho::MasterMind::getPvp(){
	return this->pvp;
}

bool Trabalho::MasterMind::getGameOver(){
	return this->gameover;
}

void Trabalho::MasterMind::set_config(){
	int quantidade_cores;
	int tamanho_codigo;
	int quantidade_palpites;
	int difficulty;

	bool cores_repetidas;
	bool pvp;

	cout << "Insira a quantidade de cores (4 - 10): ";
	cin >> quantidade_cores;

	cout << "Insira o tamanho do código (4 - 6): ";
	cin >> tamanho_codigo;

	cout << "Insira a quantidade de palpites (4 - 10): ";
	cin >> quantidade_palpites;

	cout << "Insira se o código terá cores repetidas (1=sim,0=não): ";
	cin >> cores_repetidas;

	cout << "Insira se o jogo será pvp ou pve (1=pvp,0=pve): ";
	cin >> pvp;

	setQuantidadeCores(quantidade_cores);
	setTamanhoCodigo(tamanho_codigo);
	setQuantidadePalpites(quantidade_palpites);
	setCoresRepetidas(cores_repetidas);
	setPvp(pvp);
	setGameOver(false);
}

bool Trabalho::MasterMind::checkPalpite(int round){
	for (int i = 0; i < this->tamanho_codigo; ++i){
		if(this->codigo[i] != this->palpite[round][i]){
			return false;
		}
	}

	return true;
}

void Trabalho::MasterMind::setFeedBack(int round){
	bool *aux = (bool *)calloc(false, this->tamanho_codigo);

	for (int i = 0; i < this->tamanho_codigo; ++i){
		if(this->palpite[round][i] == this->codigo[i]){
			this->feedback[round][i] = preto;
			aux[i] = true;
		}else {
			this->feedback[round][i] = null;
		}
	}

	for (int i = 0; i < this->tamanho_codigo; ++i){
		for (int j = 0; j < this->tamanho_codigo; ++j){
			if((this->palpite[round][i] == this->codigo[j]) && aux[j] == false){
				this->feedback[round][i] = branco;
				aux[j] = true;
			}
		}

		if(this->feedback[round][i] == null){
			this->feedback[round][i] = cinza;
			aux[i] = true;
		}
	}
}

void Trabalho::MasterMind::load_game(){
	this->cores    = (enum cores *)malloc(sizeof(enum cores *) * this->quantidade_cores);
	this->codigo   = (enum cores *)malloc(sizeof(enum cores *) * this->tamanho_codigo);
	this->palpite  = (enum cores **)malloc(sizeof(enum cores **) * this->quantidade_palpites);
	this->feedback = (enum cores **)malloc(sizeof(enum cores **) * this->quantidade_palpites);

	for (int i = 0; i < this->quantidade_cores; ++i){
		this->cores[i] = cores[i];
	}

	for (int i = 0; i < this->quantidade_palpites; ++i){
		this->palpite[i] = (enum cores *)malloc(sizeof(enum cores *) * this->tamanho_codigo);
		this->feedback[i] = (enum cores *)malloc(sizeof(enum cores *) * this->tamanho_codigo);

		for (int j = 0; j < this->tamanho_codigo; ++j){
			this->palpite[i][j] = null;
			this->feedback[i][j] = null;
		}
	}
}

void Trabalho::MasterMind::start_game(CodeMaker *codemaker, CodeBreaker *codebreaker){
	show_board();
	this->codigo = codemaker->cria_codigo(this->tamanho_codigo, this->quantidade_cores, this->cores_repetidas);

	for (int round = 0; round < this->quantidade_palpites; ++round){
		
		this->palpite[round] = codebreaker->cria_palpite(this->tamanho_codigo);

		setFeedBack(round);
		show_board();

		if(checkPalpite(round)){
			cout << endl << "O jogador(codebreaker): " << codebreaker->getNome() << " venceu!!!" << endl;
			cout << "Pontos: " << round + 1 << endl;
			break;
		}
	}

	cout << "O jogador(codemaker): " << codemaker->getNome() << " venceu!!!" << endl;
}

void Trabalho::MasterMind::show_board(){
	system("clear");
	
	cout << "Cores: " << endl;
	
	for (int i = 0; i < quantidade_cores; ++i){
		cout << "   " << Cores::colorsToChar(Cores::intToColors(i)) << " - " << Cores::colorsToString(Cores::intToColors(i)) << endl;
	}

	cout << endl;

	cout << "| Rounds \t| Palpites \t| Feedback \t|" << endl;
	for (int round = this->quantidade_palpites; round >= 1 ; round--){
		cout << "| " << round << " \t\t| ";
		for (int i = 0; i < this->tamanho_codigo; ++i){
			cout << Cores::colorsToChar(this->palpite[round - 1][i]) << " ";
		}

		cout << " \t| ";
		for (int i = 0; i < this->tamanho_codigo; ++i){
			cout << Cores::colorsToChar(this->feedback[round - 1][i]) << " ";
		}
		cout << "\t|" << endl;
	}
}