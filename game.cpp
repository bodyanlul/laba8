#include <string>
#include <iostream>
#include "game.h"

using namespace std;


Game::Game()
{
}
void Game::creatBoard()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j= 0; j < 3; j++)
		{
			board.value[i][j] = '#';
		}
	}
}

void Game::showBoard()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << board.value[i][j];
		}
		cout << endl;
	}
	
}

bool Game::isBoardFilled()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board.value[i][j] == 'x' )
			{
				return false;
			}
		}
	}
	return true;
}

Board& Game::getBoard()
{
	return board;
}



//проверка игры на окончание
bool Game::PlayBoardIsEnd()
{
	for (int i = 0; i < 3; i++)
	{
		//если хоть один игрок заполнил строку крестиками или ноликами
		if ((board.value[i][0] == board.value[i][1]) && (board.value[i][0] == board.value[i][2]) && (board.value[i][0] != '#'))
		{
			if (board.value[i][0] == 'x')
			{
				cout << "ѕобедили крестики!" << endl;
			}
			else
			{
				cout << "ѕобедили нолики! " << endl;
			}
			return true;
		}
		//если хоть один игрок заполнил столбец крестиками или ноликами

		if ((board.value[0][i] == board.value[1][i]) && (board.value[0][i] == board.value[2][i]) && (board.value[0][i] != '#'))

		{

			if (board.value[0][i] == 'x')
			{
				cout << "ѕобедили крестики!" << endl;
			}
			else
			{
				cout << "ѕобедили нолики! " << endl;
			}
			return true;
		}
	}

	//если заполнена главна€ диагональ

	if ((board.value[0][0] == board.value[1][1]) && (board.value[0][0] == board.value[2][2]) && (board.value[0][0] != '#'))

	{
		if (board.value[0][0] == 'x')
		{
			cout << "ѕобедили крестики!" << endl;
		}
		else
		{
			cout << "ѕобедили нолики! " << endl;
		}
		return true;

	}

	//если заполнена побочна€ диагональ

	if ((board.value[0][2] == board.value[1][1]) && (board.value[0][2] == board.value[2][0]) && (board.value[0][2] != '#'))

	{

		if (board.value[0][2] == 'x')
		{
			cout << "ѕобедили крестики!" << endl;
		}
		else
		{
			cout << "ѕобедили нолики! " << endl;
		}
		return true;
	}

	//если заполнены все €чейки, но никто не победил

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board.value[i][j] == '#')
			{
				return false;
			}
		}
	}
	cout << "Ќичь€!" << endl;

	return true;
}


ostream& operator<<(ostream& os,Board& dt)
{
	for(int i = 0; i < 3; i++)
	{
	  for (int j = 0; j < 3; j++)
		  {
			os << dt.value[i][j];
		  }
				
	}
	return os;
}

istream& operator>>(istream& os, Board& dt)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			os >> dt.value[i][j];
		}

	}
	return os;
}

void Game::serialize(const char c)
{
	ofstream fstream("entry.txt");
	fstream << board <<c;
}

bool Game::deserialize()
{
	ifstream fstream("entry.txt");
	if (!fstream.is_open()) return false;
	fstream >> board;
	
	return true;
}
