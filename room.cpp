/*********************************************************************
** Program Filename: room.cpp
** Author: Jackson Perry
** Date: 2/21/19
** Description: contains defintions for room class
*********************************************************************/
#include <string>
#include "event.hpp"
#include "room.hpp"


using namespace std;

/*********************************************************************
** Function: Room
** Description: constructor
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
Room::Room() {
	this->e = NULL;
}

/*********************************************************************
** Function: ~Room
** Description: deconstructor
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
Room::~Room() {
	delete this->e;
}

/*********************************************************************
** Function: hasEvent
** Description: returns if room has event
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
bool Room::hasEvent() {
	if (this->e == NULL)
		return false;
	return true;
}

/*********************************************************************
** Function: getEvent
** Description: returns event
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
Event* Room::getEvent() {
	return this->e;
}

/*********************************************************************
** Function: setEvent
** Description: sets event
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Room::setEvent(Event* e) {
	this->e = e;
}

/*********************************************************************
** Function: isWUmpus
** Description: checks if room has wumpus
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
bool Room::isWumpus() {
	return this->e->isWumpus();
}

