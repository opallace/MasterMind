#include "headers/Jogador.hpp"

void Trabalho::Jogador::setNome(string nome){
	this->nome = nome;
}

void Trabalho::Jogador::setPontos(int pontos){
	this->pontos = pontos;
}

string Trabalho::Jogador::getNome(){
	return this->nome;
}

int Trabalho::Jogador::getPontos(){
	return this->pontos;
}

