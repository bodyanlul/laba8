#pragma once
#include <string>
#include <iostream>
#include "game.h"
#include "PLAYER.h"
using namespace std;

class SmartPlayer : public Player 
{
public:
	SmartPlayer(string name);
	string getName();
	bool doStep(int& x, int& y, Game& game) override;
private:
	string m_name;
	int x;
	int y;
};

