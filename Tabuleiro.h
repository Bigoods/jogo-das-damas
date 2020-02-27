#pragma once
#include<iostream>
#include<Windows.h>
#include"Peca.h"
using namespace std;
class Tabuleiro
{
private:
	int contador = 1, contapretas = 12, contabrancas = 12, i = 0, j = 0;
	char tabuleiro[9][9];
public:
	Tabuleiro();
	Tabuleiro(int _contador, int _contapretas, int _contabrancas, int _i, int _j);
	virtual ~Tabuleiro();

	//Metodos de acesso ao tabuleiro
	bool GetTabuleiroB(int &horizontal, int &vertical, bool cont, Peca &p, int &x);
	bool GetTabuleiroP(int &horizontal, int &vertical, bool cont, Peca &p, int &x);
	void SetTabuleirobranco(int horizontal, int vertical) { tabuleiro[horizontal][vertical] = 'O'; }
	void SetTabuleiropreto(int horizontal, int vertical) { tabuleiro[horizontal][vertical] = 'X'; }

	//Funcoes graficas
	void Desenho()const;
	int setxy(short x, short y)const;
	void DrawRect(int x, int y, int width, int height);
	void apresentacao();

	//Funcoes tabuleiro
	void primeiraapresentacao(int &x, int &y, Peca &p);
	void PreencherTabuleiro(Peca &p);
	void preencherpecas(int &x, int &y, Peca &p, Tabuleiro &t);
	void cleantabuleiro();
};