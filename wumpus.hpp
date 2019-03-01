/*********************************************************************
** Program Filename: wupus.hpp
** Author: Jackson Perry
** Date: 2/21/19
** Description: class definition for wumpus
*********************************************************************/
#ifndef wumpus
#define wumpus

#include <string>
#include "event.hpp"

using namespace std;

class Wumpus : public Event {
private:
	string percept;

public:
	Wumpus();
	void getPercept();
	int encounter();
	bool isWumpus();
	int getType();
};

#endif