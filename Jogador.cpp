#include "Jogador.h"



Jogador::Jogador()
{
}


Jogador::~Jogador()
{
}

void Jogador::pedecoordenadaspretas(int &x, Peca &p, Tabuleiro t)
{
	x = 0;
	int direcao, y;
	do
	{
		int i;
		do {
			cout << endl;
			t.setxy(0, 37);
			cout << "Pretas:";
			t.setxy(0, 38);
			cout << "                                                                                      \n                                                                                                   \n                                                                                                                    \n                                                                                                                                   \n                                                                                                                                                      \n                                                                                                                        \n";
			t.setxy(0, 38);
			cout << "Insira as coordenadas horizontais: ";
			cin >> horizontal;
			cin.clear();
			cin.ignore(999999, '\n');
			/*cin.clear();
			cin.get();*/
			t.setxy(0, 39);
			cout << "Insira as coordenadas verticais: ";
			if (horizontal > 0 && horizontal < 8)
			{
				cin >> vertical;
				cin.clear();
				cin.ignore(999999, '\n');
			}
			else
				cout << endl;
			/*cin.get();*/
			if(vertical <= 0 || vertical > 8 || horizontal <= 0 || horizontal > 8)
			{
				cout << "Coordenadas invalidas, tente outra vez em";
				cout << "3,";
				Sleep(1000);
				cout << "2,";
				Sleep(1000);
				cout << "1.";
				Sleep(1000);
			}
		} while (vertical <= 0 || vertical > 8 || horizontal <= 0 || horizontal > 8);
		for (i = 0; i < 12; i++)
		{
			if (horizontal == p.GetPretas(x) && vertical == p.GetPretas(x + 1) && x < 24)
			{
				do
				{
					cout << "[1]Esquerda-Baixo [2]Direita-Baixo\nA sua resposta: ";
					cin >> direcao;
					cin.clear();
					cin.get();
					if (direcao == 1 && horizontal + 1 < 9 && vertical - 1 > 0)
					{
						horizontal += 1;
						vertical -= 1;
						/*p.SetPretas(horizontal, x);
						p.SetPretas(vertical, x);*/
						cont = FALSE;
					}
					else if (direcao == 2 && horizontal + 1 < 9 && vertical + 1 < 9)
					{
						horizontal += 1;
						vertical += 1;
						/*p.SetPretas(horizontal, x);
						p.SetPretas(vertical, x);*/
						cont = FALSE;
					}
					else
					{
						cont = TRUE;
					}
				} while (cont);
				cont = FALSE;
				break;
			}
			else
			{
				cont = TRUE;
			}
			x += 2;
		}
		if (cont == TRUE)
		{
			cout << "Coordenadas invalidas, tente outra vez em";
			cout << "3,";
			Sleep(1000);
			cout << "2,";
			Sleep(1000);
			cout << "1.";
			Sleep(1000);
			x = 0;
		}
		p.Show(p);
	} while (cont || t.GetTabuleiroP(horizontal, vertical, cont, p, x));
	x = y = 0;
	t.PreencherTabuleiro(p);
	x = y = 0;
	t.preencherpecas(x, y, p, t);
}

void Jogador::pedecoordenadasbrancas(int & x, Peca & p, Tabuleiro t)
{
	x = 0;
	int direcao, y;
	t.setxy(0, 37);
	cout << "Brancas:";
	do
	{
		int i;
		do {
		cout << endl;
		t.setxy(0, 38);
		cout << "                                                                                      \n                                                                                                   \n                                                                                                                    \n                                                                                                                                   \n                                                                                                                                                      \n                                                                                                                        \n";
		t.setxy(0, 38);
		cout << "Insira as coordenadas horizontais: ";
		cin >> horizontal;
		cin.clear();
		cin.ignore(999999, '\n');
		//cin.get();
		t.setxy(0, 39);
		cout << "Insira as coordenadas verticais: ";
		if (horizontal > 0 && horizontal < 8)
		{
			cin >> vertical;
			cin.clear();
			cin.ignore(999999, '\n');
		}
		else
			cout << endl;
		//cin.get();
		if (vertical <= 0 || vertical > 8 || horizontal <= 0 || horizontal > 8)
		{
			cout << "Coordenadas invalidas, tente outra vez em";
			cout << "3,";
			Sleep(1000);
			cout << "2,";
			Sleep(1000);
			cout << "1.";
			Sleep(1000);
		}
		} while (vertical <= 0 || vertical > 8 || horizontal <= 0 || horizontal > 8);
		//if (vertical > 0 && vertical < 8 && horizontal>0 && horizontal < 8)
		for (i = 0; i < 12; i++)
		{
			if (horizontal == p.GetBrancas(x) && vertical == p.GetBrancas(x + 1) && x < 24)
			{
				do
				{
					cout << "[1]Esquerda-Cima [2]Direita-Cima\nA sua resposta: ";
					cin >> direcao;
					cin.clear();
					cin.get();
					if (direcao == 1 && horizontal - 1 > 0 && vertical - 1 > 0)
					{
						horizontal -= 1;
						vertical -= 1;
						/*p.SetBrancas(horizontal, x);
						p.SetBrancas(vertical, x);*/
						cont = FALSE;
					}
					else if (direcao == 2 && horizontal - 1 >0 && vertical + 1 < 9)
					{
						horizontal -= 1;
						vertical += 1;
						/*p.SetBrancas(horizontal, x);
						p.SetBrancas(vertical, x);*/
						cont = FALSE;
					}
					else
					{
						cont = TRUE;
					}
				} while (cont);
				cont = FALSE;
				break;
			}
			else
			{
				cont = TRUE;
			}
			x += 2;

		}
		if (cont == TRUE)
		{
			cout << "Coordenadas invalidas, tente outra vez em";
			cout << "3,";
			Sleep(1000);
			cout << "2,";
			Sleep(1000);
			cout << "1.";
			Sleep(1000);
			x = 0;
		}
		/*x = y = 0;*/
		p.Show(p);
	} while (cont || t.GetTabuleiroB(horizontal, vertical, cont, p, x));
	x = y = 0;
	t.PreencherTabuleiro(p);
	x = y = 0;
	t.preencherpecas(x, y, p, t);
}