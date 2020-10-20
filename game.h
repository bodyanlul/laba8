#pragma once
#include <string>
#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

struct Board
{
	char value[3][3];
};

struct Cross
{
	static const char getType()
	{
		return 'x';
	}
};

struct Zero
{
	static const char getType()
	{
		return '0';
	}
};


class Game
{
public:
	Game();
	void showBoard();
	void creatBoard();
	template<typename T>
	bool makeStep(int x, int y)
	{
		if (board.value[x][y] == '#')
		{
			board.value[x][y] = T::getType();
			return true;
		}
		return false;
	}
	bool isBoardFilled();
	Board& getBoard();
	bool PlayBoardIsEnd();
	/*void serialize(int* count, string* first, string* second);
	bool deserialize();*/
	void serialize(const char c);
	bool deserialize();
	friend ostream& operator<<(ostream& os, Board& dt);
	friend istream& operator>>(istream& os, Board& dt);
private:
	Board board;
};

