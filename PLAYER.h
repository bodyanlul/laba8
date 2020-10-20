#pragma once
#include <string>
#include <iostream>
#include "game.h"
using namespace std;

class Player
{
public: 
	virtual bool doStep(int& x, int& y, Game& game) = 0;
private:
};