/*********************************************************************
** Program Filename: game.hpp
** Author: Jackson Perry
** Date: 2/21/19
** Description: game class
*********************************************************************/
#ifndef game
#define game

#include <stdlib.h>
#include <vector>
#include <string>
#include "room.hpp"
#include "gold.hpp"
using namespace std;


class Game {
private:
	vector<vector<Room> > rooms;
	int length;
	int startX, startY, currX, currY;
	int arrows;
	bool wumpusAlive;
	int wumpusX = 0, wumpusY = 0;
	bool hasGold = false;
	bool endOfGame = false;


public:
	Game(int length);

	void encounter(int num);
	void checkPercepts();
	void runGame();
	void shootArrow();
	void moveChar();
	void drawMap();
	void takeTurn();
	void endGame(int num);
	void addEvent(Event* e) {
		int tempX = 0, tempY = 0;
		tempX = rand() % this->length;
		tempY = rand() % this->length;
		while (rooms.at(tempX).at(tempY).hasEvent()) {
			tempX = rand() % this->length;
			tempY = rand() % this->length;
		}
		if (e->isWumpus()) {
			this->wumpusX = tempX;
			this->wumpusY = tempY;
		}
		rooms.at(tempX).at(tempY).setEvent(e);
	}
};

#endif