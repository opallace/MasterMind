#include "headers/Cores.hpp"

enum cores Trabalho::Cores::intToColors(int cor){
	enum cores corr;

	switch(cor){
		case 0:
			corr = branco;
			break;
		case 1:
			corr = preto;
			break;
		case 2:
			corr = cinza;
			break;
		case 3:
			corr = azul;
			break;
		case 4:
			corr = vermelho;
			break;
		case 5:
			corr = dourado;
			break;
		case 6:
			corr = sepia;
			break;
		case 7:
			corr = rosa;
			break;
		case 8:
			corr = laranja;
			break;
		case 9:
			corr = marrom;
			break;
		case 10:
			corr = turquesa;
			break;
	}

	return corr;
}
enum cores Trabalho::Cores::charToColor(char cor){
	enum cores corr;

	switch(cor){
		case 'B':
			corr = branco;
			break;
		case 'P':
			corr = preto;
			break;
		case 'C':
			corr = cinza;
			break;
		case 'A':
			corr = azul;
			break;
		case 'V':
			corr = vermelho;
			break;
		case 'D':
			corr = dourado;
			break;
		case 'S':
			corr = sepia;
			break;
		case 'R':
			corr = rosa;
			break;
		case 'L':
			corr = laranja;
			break;
		case 'M':
			corr = marrom;
			break;
		case 'T':
			corr = turquesa;
			break;
	}

	return corr;
}

string Trabalho::Cores::colorsToChar(enum cores cor){
	string corr;

	switch(cor){
		case branco:
			corr.append("B");
			break;
		case preto:
			corr.append("P");
			break;
		case cinza:
			corr.append("C");
			break;
		case azul:
			corr.append("A");
			break;
		case vermelho:
			corr.append("V");
			break;
		case dourado:
			corr.append("D");
			break;
		case sepia:
			corr.append("S");
			break;
		case rosa:
			corr.append("R");
			break;
		case laranja:
			corr.append("L");
			break;
		case marrom:
			corr.append("M");
			break;
		case turquesa:
			corr.append("T");
			break;
		case null:
			corr.append("-");
			break;
	}

	return corr;
}

string Trabalho::Cores::colorsToString(enum cores cor){
	string corr;

	switch(cor){
		case branco:
			corr.append("Branco");
			break;
		case preto:
			corr.append("Preto");
			break;
		case cinza:
			corr.append("Cinza");
			break;
		case azul:
			corr.append("Azul");
			break;
		case vermelho:
			corr.append("Vermelho");
			break;
		case dourado:
			corr.append("Dourado");
			break;
		case sepia:
			corr.append("Sépia");
			break;
		case rosa:
			corr.append("Rosa");
			break;
		case laranja:
			corr.append("Laranja");
			break;
		case marrom:
			corr.append("Marrom");
			break;
		case turquesa:
			corr.append("Turquesa");
			break;
		case null:
			corr.append("-");
			break;
	}

	return corr;
}