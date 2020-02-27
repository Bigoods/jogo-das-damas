#include "Peca.h"



Peca::Peca()
{
}

Peca::~Peca()
{
}

void Peca::PosicaoBrancas(int i, int j, int &x)
{
	SetBrancas(i, x);
	SetBrancas(j, x);
}

void Peca::PosicaoPretas(int i, int j, int &x)
{
	SetPretas(i, x);
	SetPretas(j, x);
}

void Peca::Show(Peca p)
{
	cout << endl << endl << endl;
	int x;
	cout << "Pretas: ";
	for (x = 0; x < 24; x++)
		cout << Pretas[x] << ", ";
	cout << "\nBrancas: ";
	for (x = 0; x < 24; x++)
		cout << Brancas[x] << ", ";
}