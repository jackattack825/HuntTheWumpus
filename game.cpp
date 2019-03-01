/*********************************************************************
** Program Filename: game.cpp
** Author: Jackson Perry
** Date: 2/21/19
** Description: contains defintions for game class
*********************************************************************/

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "event.hpp"
#include "game.hpp"
#include "bats.hpp"
#include "gold.hpp"
#include "pit.hpp"
#include "room.hpp"
#include "wumpus.hpp"


using namespace std;
/*********************************************************************
** Function: Game
** Description: constructor
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
Game::Game(int len) {
	this->length = len;
	for (int i = 0; i < length; i++) {
		vector<Room> row;
		for (int j = 0; j < length; j++) {
			Room r;
			row.push_back(r);
		}
		rooms.push_back(row);
	}

	srand(time(NULL));
	addEvent(new Gold());
	addEvent(new Wumpus());
	addEvent(new Pit());
	addEvent(new Bat());
	addEvent(new Pit());
	addEvent(new Bat());


	this->currX = rand() % this->length;
	this->currY = rand() % this->length;

	this->runGame();
}

/*********************************************************************
** Function: runGame
** Description: runs and manages game
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Game::runGame() {
	while (this->wumpusAlive && !this->endOfGame) {
		cout << "The wumpus needs to be slayed" << endl;
		drawMap();
		takeTurn();
	}
	if (this->endOfGame)
		endGame(2);
	while (!this->hasGold && !this->endOfGame) {
		cout << "Find the hidden gold and escape to win" << endl;
		drawMap();
		takeTurn();
	}
	if (this->endOfGame)
		endGame(2);
	while (this->currX != this->startX && this->currY != this->startY && !this->endOfGame) {
		cout << "Return to your starting room to escape" << endl;
		drawMap();
		takeTurn();
	}
	if (this->endOfGame)
		endGame(2);
	endGame(1);
}

/*********************************************************************
** Function: drawMap
** Description: draws map for cave system
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Game::drawMap() {
	/*
	for (int i = 0; i < this->length; i++) {
		cout << "+---+---+---+---+\n";
		for (int j = 0; j < this->length+1; j++) {
			if (this->currX == i && this->currY == j)
				cout << "| * \t";
			else
				cout << "| \t";
			for (int k = 0; k < 3; k++) {
				cout << "| \t";
			}
		}
	}
	cout << "+---+---+---+---+\n\n";
}
*/
	for (int i = 0; i < this->length; i++) {
		cout << endl << "+";
		for (int j = 0; j < this->length; j++) {
			cout << "---+";
		}
		cout << endl << "|";
		for (int j = 0; j < this->length; j++) {
			cout << " ";
			if (i == this->currX && j == this->currY) {
				cout << "X";
			}
			else {
				cout << " ";
			}
			cout << " |";
		}
	}
	cout << endl << "+";
	for (int j = 0; j < this->length; j++) {
		cout << "---+";
	}
	cout << endl;


}

/*********************************************************************
** Function: takeTurn
** Description: manages turns
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Game::takeTurn() {
	int res = 0;
	cout << "New turn! Checking percepts." << endl;
	if (this->currX + 1 <= rooms.size() && this->currX + 1 >=0 && this->currY <= rooms.at(currX).size() && rooms.at(this->currX + 1).at(this->currY).hasEvent())
		rooms.at(this->currX + 1).at(this->currY).getEvent()->getPercept();
	if (this->currX - 1 <= rooms.size() && this->currX - 1 >= 0 && this->currY <= rooms.at(currX).size() && rooms.at(this->currX - 1).at(this->currY).hasEvent())
		rooms.at(this->currX - 1).at(this->currY).getEvent()->getPercept();
	if (this->currX <= rooms.size() && this->currY + 1 <= rooms.at(currX).size() && this->currY + 1 >= 0 && rooms.at(this->currX + 1).at(this->currY).hasEvent())
		rooms.at(this->currX).at(this->currY + 1).getEvent()->getPercept();
	if (this->currX <= rooms.size() && this->currY - 1 <= rooms.at(currX).size() && this->currY - 1 >= 0 && rooms.at(this->currX + 1).at(this->currY).hasEvent())
		rooms.at(this->currX).at(this->currY - 1).getEvent()->getPercept();

	cout << "You can now fire an arrow(1) or move(2)." << endl;
	cin >> res;

	if (res == 1) {
		if (arrows >0) {
			shootArrow();
		}
		else {
			cout << "out of arrows, moving char" << endl;
			moveChar();
		}
	}
	else if (res == 2)
		moveChar();
}

/*********************************************************************
** Function: shootArrow
** Description: shoots and manages arrow
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Game::shootArrow() {
	int res = 0;
	cout << "You have chosen to shoot an arrow! Now choose a direction: North(3), South(4), East(1), West(2)" << endl;
	cin >> res;

	switch (res) {
	case 1:
		for (int i = 0; i < 3; i++) {
			if (this->currX + i <= rooms.size() && rooms.at(this->currX + i).at(this->currY).isWumpus())
				this->wumpusAlive = false;
			cout << "You have killed the wumpus, now find the gold and escape" << endl;
		}
		break;
	case 2:
		for (int i = 0; i < 3; i++) {
			if (this->currX - i >=0 && rooms.at(this->currX - i).at(this->currY).isWumpus())
				this->wumpusAlive = false;
			cout << "You have killed the wumpus, now find the gold and escape" << endl;
		}
		break;
	case 3:
		for (int i = 0; i < 3; i++) {
			if (this->currY + i <= rooms.at(this->currX).size() && rooms.at(this->currX).at(this->currY + i).isWumpus())
				this->wumpusAlive = false;
			cout << "You have killed the wumpus, now find the gold and escape" << endl;
		}
		break;
	case 4:
		for (int i = 0; i < 3; i++) {
			if (this->currY - i >= 0 && rooms.at(this->currX).at(this->currY - i).isWumpus())
				this->wumpusAlive = false;
			cout << "You have killed the wumpus, now find the gold and escape" << endl;
		}
		break;
	}

	if (this->wumpusAlive) {
		Room r;
		cout << "You have missed the wumpus and awoken it. It may have moved to a new location." << endl;
		if (rand() % 100 < 75) {
			cout << "Wumpus is changing locations" << endl;
			//doesnt work rooms.at(wumpusX).at(wumpusY).setEvent(new Event);
			rooms.at(wumpusX).at(wumpusY)= r;
			int tempX = 0, tempY = 0;
			tempX = rand() % this->length;
			tempY = rand() % this->length;
			while (rooms.at(tempX).at(tempY).hasEvent()) {
				tempX = rand() % this->length;
				tempY = rand() % this->length;
			}
			rooms.at(tempX).at(tempY).setEvent(new Wumpus);
		}
	}
}

/*********************************************************************
** Function: moveChar
** Description: move character
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Game::moveChar() {
	int res = 0;
	int end = -1;
	cout << "You have decided to move your character. Now choose a direction: North(3), South(4), East(1), West(2)" << endl;
	cin >> res;

	switch (res) {
	case 1:
		if (this->currY + 1 <= rooms.size()) {
			currY += 1;
			cout << "Moved east" << endl;
			if (rooms.at(currX).at(currY).hasEvent()) {
				end = rooms.at(currX).at(currY).getEvent()->encounter();
				this->encounter(end);
			}
		}
		else
			cout << "The direction you chose doesn't have space to go and you have forfeited your turn." << endl;
		break;
	case 2:
		if (this->currY -1 >= 0) {
			currY -= 1;
			cout << "Moved west" << endl;
			if (rooms.at(currX).at(currY).hasEvent()) {
				end = rooms.at(currX).at(currY).getEvent()->encounter();
				this->encounter(end);
			}
		}
		else
			cout << "The direction you chose doesn't have space to go and you have forfeited your turn." << endl;
		break;
	case 3:
		if (this->currX - 1 >= 0) {
			currX -= 1;
			cout << "Moved north" << endl;
			if (rooms.at(currX).at(currY).hasEvent()) {
				end = rooms.at(currX).at(currY).getEvent()->encounter();
				this->encounter(end);
			}
		}
		else
			cout << "The direction you chose doesn't have space to go and you have forfeited your turn." << endl;
		break;
	case 4:
		if (this->currX + 1 >= 0) {
			currX += 1;
			cout << "Moved south" << endl;
			if (rooms.at(currX).at(currY).hasEvent()) {
				end = rooms.at(currX).at(currY).getEvent()->encounter();
				this->encounter(end);
			}
		}
		else
			cout << "The direction you chose doesn't have space to go and you have forfeited your turn." << endl;
		break;
	}

}

/*********************************************************************
** Function: endGame
** Description: end game info
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Game::endGame(int num) {
	if (num == 1) {
		cout << "You have completed the game. Thanks for playing" << endl;
	}
	else {
		int res = 0;
		cout << "You have lost. Start over with same config(1), new  random config(2), or quit(3)." << endl;
		cin >> res;
		switch (res) {
		case 1:
			Game(this->length);
			break;
		case 2:
			Game(rand() % 10);
			break;
		case 3:
			exit(0);
			break;
		}
	}
}

/*********************************************************************
** Function: encounter
** Description: manages encounters
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Game::encounter(int num) {
	int tempX = 0, tempY = 0;
	switch (num) {
	case 1:
		cout << "Encountered a pit. You have lost the game." << endl;
		this->endOfGame = true;
		break;
	case 2:
		cout << "Encountered a wumpus. You have lost the game and been killed savagely." << endl;
		this->endOfGame = true;
		break;
	case 3:
		cout << "Encountered a bat. You are being transported to a new cave." << endl;
		tempX = rand() % this->length;
		tempY = rand() % this->length;
		if (rooms.at(tempX).at(tempY).hasEvent()) {
			this->encounter(rooms.at(tempX).at(tempY).getEvent()->encounter());
		}
		break;
	case 4:
		cout << "Encountered gold." << endl;
		this->hasGold = true;
		break;
	}
}
