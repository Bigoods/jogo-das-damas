#include<iostream>
#include<Windows.h>
#include"Tabuleiro.h"
#include"Peca.h"
#include"Jogador.h"

using namespace std;

int main()
{
	bool flag=FALSE;
	int h;
	char aux = '\0';
	char escolha;
	bool EscolhaTrigger = true;
	Tabuleiro tab;
	Peca p;
	Jogador j;
	//SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	do
	{
		tab.Desenho();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << "Escolha uma opcao" << endl << "1) Jogar uma partida" << endl << "2) Jogar uma partida contra bot" << endl << "3) Manual de utilizador" << endl << "4) Regras basicas de jogo" << endl << "5) Sair" << endl;
		cout << "A sua opcao: ";
		cin >> escolha;
		cin.clear();
		cin.ignore(999999, '\n');
		switch (escolha)
		{
		case '1':
			system("cls");
			tab.DrawRect(105, 25, 20, 3);
			tab.setxy(106, 26);
			cout << "Jogar uma partida\n";
			tab.setxy(106, 27);
			cout << "Preparando partida" << endl;
			Sleep(2000);
			EscolhaTrigger = false;
			break;
		case '2':
			system("cls");
			tab.DrawRect(105, 25, 29, 3);
			tab.setxy(106, 26);
			cout << "Jogar uma partida contra bot\n";
			tab.setxy(106, 27);
			cout << "Preparando partida" << endl;
			Sleep(2000);
			EscolhaTrigger = false;
			break;
		case '3':
			system("cls");
			cout << "Manual de utilizador" << endl;
			cout << "\nDeseja voltar ao menu inicial?\nA sua resposta: ";
			do
			{
				cin >> aux;
				if (aux == 'n' || aux == 'N')
					EscolhaTrigger = false;
				else if (aux == 's' || aux == 'S')
					EscolhaTrigger = true;
				else
					cout << "Opcao invalida, tente outra vez";
			} while (aux != 'n' && aux != 'N' && aux == 's' && aux == 'S');
			break;
		case '4':
			system("cls");
			tab.setxy(1, 1);
			cout << "\t********************MODO DE JOGO NORMAL********************** " << endl;
			cout << "\n";
			cout << "INSTRUCOES PARA JOGAR DAMAS EM C++ A PARTIDA COMECA COM AS FICHAS 'X'" << endl;
			cout << "PARA FAZER UM MOVIMENTO DEVE SELECIONAR PRIMEIRO A COORDENADA HORIZONTAL" << endl;
			cout << "DEPOIS A COORDENADA VERTICAL E DEPOIS ESCOLHER A DIRECAO DA PECA" << endl;
			cout << "O JOGO TERMINA QUANDO NAO HA FICHAS PRA COMER." << endl;
			cout << "\n";
			cout << "\t********************MODO CONTRA COMPUTADOR ******************** " << endl;
			cout << "\n";
			cout << "SE NAO TENS COM QUEM JOGAR PODES JOGAR CONTRA O COMPUTADOR " << endl;
			cout << "E ASSIM TREINAR AS TUAS JOGADAS " << endl;
			cout << "\nDeseja voltar ao menu inicial?\nA sua resposta: ";
			do
			{
				cin >> aux;
				if (aux == 'n' || aux == 'N')
					EscolhaTrigger = false;
				else if (aux == 's' || aux == 'S')
					EscolhaTrigger = true;
				else
					cout << "Opcao invalida, tente outra vez";
			} while (aux != 'n' && aux != 'N' && aux == 's' && aux == 'S');
			break;
		case '5':
			cout << "Sair" << endl;
			exit(-1);
			break;
		default:
			break;
		}
		system("CLS");
	} while (EscolhaTrigger);
	if (escolha == '1')
	{
		tab.apresentacao();
		int x = 0, y = 0;
		tab.primeiraapresentacao(x, y, p);
		do 
		{
			tab.apresentacao();
			tab.PreencherTabuleiro(p);
			tab.preencherpecas(x, y, p, tab);
			x = y = 0;
			j.pedecoordenadasbrancas(x, p, tab);
			system("cls");
			tab.apresentacao();
			tab.PreencherTabuleiro(p);
			tab.preencherpecas(x, y, p, tab);
			x = y = 0;
			j.pedecoordenadaspretas(y, p, tab);
			system("cls");
			cout << endl << endl << endl;
			cout << endl << endl << endl;
			cout << endl << endl << endl;
			for (h = 0; h < 24; h++)
			{
				if (p.GetBrancas(h) != 0)
				{
					flag = TRUE;
					break;
				}
			}
			for (h = 0; h < 24; h++)
			{
				if (p.GetPretas(h) != 0)
				{
					flag = TRUE;
					break;
				}
			}
		} while (flag);
	}
	if (escolha == '2')
	{
		cout << "Em manutencao";
	}
	cout << endl << endl;
	system("pause");
	return 0;
}