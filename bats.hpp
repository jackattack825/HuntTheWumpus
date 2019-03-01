/*********************************************************************
** Program Filename: bats.hpp
** Author: Jackson Perry
** Date: 2/21/19
** Description: class definition for bats
*********************************************************************/
#ifndef bats
#define bats

#include <string>
#include "event.hpp"

using namespace std;

class Bat: public Event {
private:
	string percept;

public:
	Bat();
	void getPercept();
	int encounter();
	bool isWumpus();
	int getType();
};

#endif