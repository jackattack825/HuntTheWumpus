/*********************************************************************
** Program Filename: main.cpp
** Author: Jackson Perry
** Date: 2/21/19
** Description: main controller
*********************************************************************/
#include <iostream>
#include <stdlib.h>
#include "game.hpp"

using namespace std;

int main(int argc, char *argv[]) {
	if (atoi(argv[1]) < 4) {
		cout << "Size must be at least 4 " << endl;
		exit(0);
	}

	cout << "Welcome to Hunt the Wumpus. You will control a player in a square maze of rooms.\nYour goal is to find and kill the Wumpus while avoiding obstacles.\nGood Luck" << endl;
	Game g(atoi(argv[1]));

	return 0;
}