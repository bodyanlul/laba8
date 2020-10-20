#pragma once
#include <string>
#include <iostream>
#include "game.h"
#include "PLAYER.h"
using namespace std;

class RandomPlayer: public Player
{
public:
	RandomPlayer(string name);
	string getName();
	bool doStep(int& x, int& y, Game& game) override;
private:
	string m_name;
	int x;
	int y;
	
}; 
