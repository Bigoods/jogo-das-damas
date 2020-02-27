#pragma once
#include"Peca.h"
#include"Tabuleiro.h"
class Jogador
{
private:
	int horizontal = 1, vertical = 1, vertical1 = 1, horizontal1 = 1;
	bool cont = false;
public:
	Jogador();
	virtual ~Jogador();

	//Funcoes jogador
	void pedecoordenadaspretas(int &x, Peca &p, Tabuleiro t);
	void pedecoordenadasbrancas(int &x, Peca &p, Tabuleiro t);
};