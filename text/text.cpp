
#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;


int main()
{
	int y_checker;
	int  x_checker;
	int  y_way;
	int  x_way;
	char color = '0';
	int counterX = 20;
	int counterO = 20;
	char contin;
	char buff[50];
	char game[8][8] = {
		{ ' ','X', ' ', 'X',' ', 'X', ' ', 'X' },
		{ 'X',' ','X', ' ', 'X',' ', 'X', ' ' },
		{ ' ','X', ' ', 'X',' ', 'X', ' ', 'X' },
		{ 'N', ' ','N', ' ','N', ' ','N', ' ' },
		{ ' ', 'N',' ', 'N',' ', 'N',' ', 'N' },
		{ '0',' ','0', ' ', '0',' ', '0', ' ' },
		{ ' ', '0',' ','0', ' ', '0',' ', '0' },
		{ '0',' ','0', ' ', '0',' ', '0', ' ' },
	};


	setlocale(LC_ALL, "rus");
	cout << "Нажмите q, чтобы продорлжить прерванную игру!" << endl << "Или w, чтобы начать новую";
	cin >> contin;
	if (contin == 'q') {

		ifstream fin("checkers.txt");
		if (!fin.is_open())
			cout << "Файл не может быть открыт!\n";
		else {
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					fin.getline(buff, 20);
					game[i][j] = buff[0];
				}
			}
		}
	}
		system("cls");
		cout << "  0 " << " 1 " << " 2 " << " 3 " << " 4 " << " 5 " << " 6 " << " 7 " << endl;
		for (int i = 0; i < 8; i++) {
			cout << i;
			for (int j = 0; j < 8; j++) {
				if (game[i][j] == 'N')
					cout << "[ ]";
				else
					if (game[i][j] != ' ') {
						cout << "[" << game[i][j] << "]";
					}
					else
						cout << "   ";
			}
			cout << endl;
		}
		


		while (counterX != 0 || counterO != 0) {



			cout << "Enter your coordinates: ";
			cin >> y_checker >> x_checker;
			cout << "Your move: ";
			cin >> y_way >> x_way;


			if (game[y_checker][x_checker] == '0' &&  y_way == (y_checker - 1) && x_way == (x_checker + 1) || (y_way == (y_checker - 1) && x_way == (x_checker - 1)) || game[y_checker - 1][x_checker + 1] == 'X' &&   y_way == (y_checker - 2) && x_way == (x_checker + 2) || game[y_checker - 1][x_checker - 1] == 'X' && (y_way == y_checker - 2 && x_way == x_checker - 2)) {
				if (color == '0') {
					char old = game[y_checker][x_checker];
					game[y_checker][x_checker] = 'N';
					game[y_way][x_way] = old;

					if (game[y_checker - 1][x_checker + 1] == 'X' &&   y_way == (y_checker - 2) && x_way == (x_checker + 2)) {
						game[y_checker - 1][x_checker + 1] = 'N';
						counterX--;
					}
					if (game[y_checker - 1][x_checker - 1] == 'X' && (y_way == y_checker - 2 && x_way == x_checker - 2)) {
						game[y_checker - 1][x_checker - 1] = 'N';
						counterX--;
					}

					system("cls");
					cout << "  0 " << " 1 " << " 2 " << " 3 " << " 4 " << " 5 " << " 6 " << " 7 " << endl;
					for (int i = 0; i < 8; i++) {
						cout << i;
						for (int j = 0; j < 8; j++) {
							if (game[i][j] == 'N')
								cout << "[ ]";
							else
								if (game[i][j] != ' ') {
									cout << "[" << game[i][j] << "]";
								}
								else
									cout << "   ";


						}
						cout << endl;
					}
					color = 'X';
				}
				else cout << "It isn't your turn/n";
			}


			if (game[y_checker][x_checker] == 'X' && y_way == (y_checker + 1) && x_way == (x_checker - 1) || y_way == (y_checker + 1) && x_way == (x_checker + 1) || game[y_checker + 1][x_checker + 1] == '0' &&  y_way == (y_checker + 2) && x_way == (x_checker + 2) || game[y_checker + 1][x_checker - 1] == '0' && y_way == (y_checker + 2) && x_way == (x_checker - 2)) {//если ходим черными
				if (color == 'X') {
					char old = game[y_checker][x_checker];
					game[y_checker][x_checker] = 'N';
					game[y_way][x_way] = old;

					if (game[y_checker + 1][x_checker + 1] == '0'&&  y_way == (y_checker + 2) && x_way == (x_checker + 2)) {
						game[y_checker + 1][x_checker + 1] = 'N';
						counterO--;
					}
					if (game[y_checker + 1][x_checker - 1] == '0' && (y_way == y_checker + 2 && x_way == x_checker - 2)) {
						game[y_checker + 1][x_checker - 1] = 'N';
						counterO--;
					}
					system("cls");
					cout << "  0 " << " 1 " << " 2 " << " 3 " << " 4 " << " 5 " << " 6 " << " 7 " << endl;
					for (int i = 0; i < 8; i++) {
						cout << i;
						for (int j = 0; j < 8; j++) {
							if (game[i][j] == 'N')
								cout << "[ ]";
							else
								if (game[i][j] != ' ') {
									cout << "[" << game[i][j] << "]";
								}
								else
									cout << "   ";
						}
						cout << endl;
					}

					ofstream fout("checkers.txt");
					for (int i = 0; i < 8; i++)
					{
						for (int j = 0; j < 8; j++) {
							fout << game[i][j] << endl;
						}
					}
					fout.close();


					color = '0';
				}
				else cout << "It isn't your turn/n";

			}
		}

	}




