#pragma once
#include<iostream>
using namespace std;
class Peca
{
private:
	int Pretas[24] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, Brancas[24] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, DamaBrancas[24] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, DamaPretas[24] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
public:
	Peca();
	virtual ~Peca();

	//Funcoes peca
	void PosicaoBrancas(int i, int j, int &x);
	void PosicaoPretas(int i, int j, int &y);

	//Metodos de acesso
	void SetPretas(int i, int &x) { Pretas[x] = i; x++; }		//inline
	int GetPretas(int x)const { return Pretas[x]; }			//inline
	void SetDamaPretas(int i, int& x) { DamaPretas[x] = i; x++; }
	int GetDamaPretas(int x) const { return DamaPretas[x]; }
	void SetBrancas(int i, int &x) { Brancas[x] = i; x++; }//inline
	int GetBrancas(int x)const { return Brancas[x]; }		//inline
	void SetDamaBrancas(int i, int& x) { DamaBrancas[x] = i; x++; }
	int GetDamaBrancas(int x) const { return DamaBrancas[x]; }

	//Outras funcoes
	void Show(Peca p);
};