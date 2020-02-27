#include "Tabuleiro.h"



Tabuleiro::Tabuleiro()
{
}

Tabuleiro::Tabuleiro(int _contador, int _contapretas, int _contabrancas, int _i, int _j)
{
	contador = _contador;
	contapretas = _contapretas;
	contabrancas = _contabrancas;
	i = _i;
	j = _j;
}

Tabuleiro::~Tabuleiro()
{
}

bool Tabuleiro::GetTabuleiroB(int &horizontal, int &vertical, bool cont, Peca &p, int &x)
{
	if (cont == true)
		return true;
	if (tabuleiro[horizontal][vertical] == 'X' || tabuleiro[horizontal][vertical] == 'O')
	{
		return true;
	}
	else
	{
		p.SetBrancas(horizontal, x);
		p.SetBrancas(vertical, x);
		x = 0;
		return false;
	}
}

bool Tabuleiro::GetTabuleiroP(int &horizontal, int &vertical, bool cont, Peca &p, int &x)
{
	if (cont == true)
		return true;
	if (tabuleiro[horizontal][vertical] == 'X' || tabuleiro[horizontal][vertical] == 'O')
	{
		return true;
	}
	else
	{
		p.SetPretas(horizontal, x);
		p.SetPretas(vertical, x);
		x = 0;
		return false;
	}
}

void Tabuleiro::Desenho()const
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cout << R"(
                                                                                                                                                                                                                                         
                                                                                          dddddddd                                                                                                                                       
          JJJJJJJJJJJ                                                                     d::::::d                                       DDDDDDDDDDDDD                                                                                   
          J:::::::::J                                                                     d::::::d                                       D::::::::::::DDD                                                                                
          J:::::::::J                                                                     d::::::d                                       D:::::::::::::::DD                                                                              
          JJ:::::::JJ                                                                     d:::::d                                        DDD:::::DDDDD:::::D                                                                             
            J:::::J   ooooooooooo      ggggggggg   ggggg   ooooooooooo            ddddddddd:::::d   aaaaaaaaaaaaa      ssssssssss          D:::::D    D:::::D  aaaaaaaaaaaaa      mmmmmmm    mmmmmmm     aaaaaaaaaaaaa      ssssssssss   
            J:::::J oo:::::::::::oo   g:::::::::ggg::::g oo:::::::::::oo        dd::::::::::::::d   a::::::::::::a   ss::::::::::s         D:::::D     D:::::D a::::::::::::a   mm:::::::m  m:::::::mm   a::::::::::::a   ss::::::::::s  
            J:::::Jo:::::::::::::::o g:::::::::::::::::go:::::::::::::::o      d::::::::::::::::d   aaaaaaaaa:::::ass:::::::::::::s        D:::::D     D:::::D aaaaaaaaa:::::a m::::::::::mm::::::::::m  aaaaaaaaa:::::ass:::::::::::::s 
            J:::::jo:::::ooooo:::::og::::::ggggg::::::ggo:::::ooooo:::::o     d:::::::ddddd:::::d            a::::as::::::ssss:::::s       D:::::D     D:::::D          a::::a m::::::::::::::::::::::m           a::::as::::::ssss:::::s
            J:::::Jo::::o     o::::og:::::g     g:::::g o::::o     o::::o     d::::::d    d:::::d     aaaaaaa:::::a s:::::s  ssssss        D:::::D     D:::::D   aaaaaaa:::::a m:::::mmm::::::mmm:::::m    aaaaaaa:::::a s:::::s  ssssss 
JJJJJJJ     J:::::Jo::::o     o::::og:::::g     g:::::g o::::o     o::::o     d:::::d     d:::::d   aa::::::::::::a   s::::::s             D:::::D     D:::::D aa::::::::::::a m::::m   m::::m   m::::m  aa::::::::::::a   s::::::s      
J:::::J     J:::::Jo::::o     o::::og:::::g     g:::::g o::::o     o::::o     d:::::d     d:::::d  a::::aaaa::::::a      s::::::s          D:::::D     D:::::Da::::aaaa::::::a m::::m   m::::m   m::::m a::::aaaa::::::a      s::::::s   
J::::::J   J::::::Jo::::o     o::::og::::::g    g:::::g o::::o     o::::o     d:::::d     d:::::d a::::a    a:::::assssss   s:::::s        D:::::D    D:::::Da::::a    a:::::a m::::m   m::::m   m::::ma::::a    a:::::assssss   s:::::s 
J:::::::JJJ:::::::Jo:::::ooooo:::::og:::::::ggggg:::::g o:::::ooooo:::::o     d::::::ddddd::::::dda::::a    a:::::as:::::ssss::::::s     DDD:::::DDDDD:::::D a::::a    a:::::a m::::m   m::::m   m::::ma::::a    a:::::as:::::ssss::::::s
 JJ:::::::::::::JJ o:::::::::::::::o g::::::::::::::::g o:::::::::::::::o      d:::::::::::::::::da:::::aaaa::::::as::::::::::::::s      D:::::::::::::::DD  a:::::aaaa::::::a m::::m   m::::m   m::::ma:::::aaaa::::::as::::::::::::::s 
   JJ:::::::::JJ    oo:::::::::::oo   gg::::::::::::::g  oo:::::::::::oo        d:::::::::ddd::::d a::::::::::aa:::as:::::::::::ss       D::::::::::::DDD     a::::::::::aa:::am::::m   m::::m   m::::m a::::::::::aa:::as:::::::::::ss  
     JJJJJJJJJ        ooooooooooo       gggggggg::::::g    ooooooooooo           ddddddddd   ddddd  aaaaaaaaaa  aaaa sssssssssss         DDDDDDDDDDDDD         aaaaaaaaaa  aaaammmmmm   mmmmmm   mmmmmm  aaaaaaaaaa  aaaa sssssssssss    
                                                g:::::g                                                                                                                                                                                  
                                    gggggg      g:::::g                                                                                                                                                                                  
                                    g:::::gg   gg:::::g                                                                                                                                                                                  
                                     g::::::ggg:::::::g                                                                                                                                                                                  
                                      gg:::::::::::::g                                                                                                                                                                                   
                                        ggg::::::ggg                                                                                                                                                                                     
                                           gggggg                                                                                                                                                                                        
)" << "\n";
}

int Tabuleiro::setxy(short x, short y)const
{
	COORD c = { x,y };
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void Tabuleiro::DrawRect(int x, int y, int width, int height)
{

	setxy(x, y); cout << char(201);
	for (int i = 1; i < width; i++)cout << char(205);
	cout << char(187);
	setxy(x, height + y); cout << char(200);
	for (int i = 1; i < width; i++)cout << char(205);
	cout << char(188);
	for (int i = y + 1; i < height + y; i++)
	{
		setxy(x, i); cout << char(186);
		setxy(x + width, i); cout << char(186);
	}
}

void Tabuleiro::primeiraapresentacao(int &x, int &y, Peca &p)
{
	setxy(0, 0);
	Desenho();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	DrawRect(95, 25, 45, 12);
	setxy(96, 26);
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (i == 0)
			{
				cout << "0";
				for (j = 1; j < 9; j++)
				{
					cout << "   " << j << " ";
				}
			}
			if (i > 0)
			{
				cout << endl;
				contador--;
				setxy(96, 26 + i);
				cout << i << " ";
				for (j = 1; j < 9; j++)
				{
					contador++;
					if (contador % 2 != 0)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 119);
						cout << " " << " " << " " << " " << " ";
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					if (contador % 2 == 0)
					{
						if ((i == 8 || i == 6 || i == 7) && contabrancas > 0)
						{
							cout << " " << " ";
							contabrancas--;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
							cout << "O";
							cout << " " << " ";
							p.SetBrancas(i, x);
							p.SetBrancas(j, x);
						}
						else if ((i == 1 || i == 2 || i == 3) && contapretas > 0)
						{
							cout << " " << " ";
							contapretas--;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
							cout << "X";
							cout << " " << " ";
							p.SetPretas(i, y);
							p.SetPretas(j, y);
						}
						else
						{
							cout << " " << " " << " " << " " << " ";
						}
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					}
				}
			}
		}
	}
	setxy(96, 26 + i);
	cout << "Pretas='X'";
	setxy(96, 26 + 1 + i);
	cout << "Brancas='O'";
}

void Tabuleiro::apresentacao()
{
	setxy(0, 0);
	Desenho();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	DrawRect(95, 25, 45, 12);
	setxy(96, 26);
	for (i = 0; i < 9; i++)
	{
		for (j = 1; j < 9; j++)
		{
			if (i == 0)
			{
				cout << "0";
				for (j = 1; j < 9; j++)
				{
					cout << "   " << j << " ";
				}
			}
			if (i > 0)
			{
				cout << endl;
				contador--;
				setxy(96, 26 + i);
				cout << i << " ";
				for (j = 1; j < 9; j++)
				{
					contador++;
					if (contador % 2 != 0)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 119);
						cout << " " << " " << " " << " " << " ";
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					if (contador % 2 == 0)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
						cout << " " << " " << " " << " " << " ";
						
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					}
				}
			}
		}
	}
	setxy(96, 26 + i);
	cout << "Pretas='X'";
	setxy(96, 26 + 1 + i);
	cout << "Brancas='O'";
}

void Tabuleiro::PreencherTabuleiro(Peca &p)
{
	cleantabuleiro();
	int x = 0, y = 0;
	do
	{
		i = p.GetBrancas(x);
		x++;
		j = p.GetBrancas(x);
		x++;
		tabuleiro[i][j] = 'O';
		i = p.GetPretas(y);
		y++;
		j = p.GetPretas(y);
		y++;
		tabuleiro[i][j] = 'X';
	} while (x < 24 && y < 24);
	y = x = 0;
}

void Tabuleiro::preencherpecas(int &x, int &y, Peca &p, Tabuleiro &t)
{
	bool controla=true;
	setxy(0, 0);
	Desenho();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	do{
		DrawRect(95, 25, 45, 12);
		setxy(96, 26);
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{		
				if (i == 0)
				{
					cout << "0";
					for (j = 1; j < 9; j++)
					{
						cout << "   " << j << " ";
					}
				}
				if (i > 0)
				{
					cout << endl;
					contador--;
					setxy(96, 26 + i);
					cout << i << " ";
					for (j = 1; j < 9; j++)
					{
						contador++;
						if (contador % 2 != 0)
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 119);						
							cout << " " << " " << " " << " " << " ";	
						}
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
						if (contador % 2 == 0)
						{ 
							if (i == 3)
								Sleep(1);
							if ((p.GetBrancas(x) == i && p.GetBrancas(x + 1) == j) || (tabuleiro[i][j] == 'O' && tabuleiro[i][j] != 'X'))
							{
								tabuleiro[i][j] = 'O';
								cout << " " << " ";
								contabrancas--;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
								cout << "O";
								cout << " " << " ";
								x += 2;
							}
							else if ((p.GetPretas(y)==i && p.GetPretas(y+1)==j) ||( tabuleiro[i][j] == 'X' && tabuleiro[i][j] != 'O'))
							{
								tabuleiro[i][j] = 'X';
								cout << " " << " ";
								contapretas--;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
								cout << "X";
								cout << " " << " ";
								y += 2;
							}
							else if (tabuleiro[i][j] != 'X' && tabuleiro[i][j] != 'O')
							{
								cout << " " << " " << " " << " " << " ";
							}
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
						}
					}
				}
			}
		}
		setxy(96, 26 + i);
		cout << "Pretas='X'";
		setxy(96, 26 + 1 + i);
		cout << "Brancas='O'";
	} while (x < 24 || y < 24);
}

void Tabuleiro::cleantabuleiro()
{
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			tabuleiro[i][j] = '\0';
		}
	}
}