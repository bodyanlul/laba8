#include <string>
#include <iostream>
#include "player_smart.h"
#include "game.h"

SmartPlayer::SmartPlayer(string name)
{
	m_name = name;
}
string SmartPlayer::getName()
{
	return m_name;
}
bool SmartPlayer::doStep(int& x, int& y, Game& game)
{
	int count = 0;

	//подсчитываем количество крестиков в каждой строке
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (game.getBoard().value[i][j] == 'x')
			{
				count++;
			}
		}
		//если встречено два крестика
		if (count == 2)
		{
			
				for (int j = 0; j < 3; j++)
				{
					if ((game.getBoard().value[i][j] == '#') && (game.getBoard().value[i][j] != 'x'))
					{
						x = i;
						y = j;
						return true;
					}
				}
		
		}
		count = 0;
	}

	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (game.getBoard().value[i][j] == 'x')
			{
				count++;
			}
		}

		//если встречено два крестика
		if (count == 2)
		{
			
				for (int i = 0; i < 3; i++)
				{
					if (game.getBoard().value[i][j] == '#' && game.getBoard().value[i][j] != 'x')
					{
						x = i;
						y = j;
						return true;
					}
				}
			
		}
		count = 0;
	}

	for (int i = 0; i < 3; i++)
	{
		int j = i;
		if (game.getBoard().value[i][j] == 'x')
		{
			count++;
		}
	}
		//если встречено два крестика
		if (count == 2)
		{
			
				for (int i = 0; i < 3; i++)
				{
					int j = i;
					if (game.getBoard().value[i][j] == '#' && game.getBoard().value[i][j] != 'x')
					{
						x = i;
						y = j;
						return true;
					}
				}
			
		}
		count = 0;
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 2; j > 0; j--)
		{
			if (game.getBoard().value[i][j] == 'x')
			{
				count++;
			}
		}


		if (count == 2)
		{
		
				for (int i = 0; i < 3; i++)
				{
					for (int j = 2; j > 0; j--)
					{
						if (game.getBoard().value[i][j] == '#' && game.getBoard().value[i][j] != '0')
						{
							x = i;
							y = j;
							return true;
						}
					}
				}
			
		}
		count = 0;
	}
	srand(time(NULL));
	if (count == 0)
	{
		do
		{
			x = rand() % 3;
			y = rand() % 3;
			if (game.getBoard().value[x][y] == '#' && game.getBoard().value[x][y] != '0')
			{
				break;
			}
		}
		while (true);
	}


    return true;
}

  