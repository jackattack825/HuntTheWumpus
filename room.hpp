/*********************************************************************
** Program Filename: room.hpp
** Author: Jackson Perry
** Date: 2/21/19
** Description: room class
*********************************************************************/
#ifndef room
#define room

#include <string>
#include "event.hpp"

using namespace std;

class Room {
private:
	Event* e;

public:
	Room();
	~Room();
	bool hasEvent();
	void setEvent(Event *e);
	Event* getEvent();
	bool isWumpus();
};

#endif