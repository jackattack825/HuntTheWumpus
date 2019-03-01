/*********************************************************************
** Program Filename: wumpus.cpp
** Author: Jackson Perry
** Date: 2/21/19
** Description: definition for wumpus
*********************************************************************/

#include <iostream>
#include "wumpus.hpp"
#include "event.hpp"


using namespace std;

/*********************************************************************
** Function: Wumpus
** Description: constructor
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
Wumpus::Wumpus() {
	this->percept = "You smell a terrible stench";
}

/*********************************************************************
** Function: getPercept
** Description: returns percept
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Wumpus::getPercept() {
	cout << this->percept << endl;
}

/*********************************************************************
** Function: isWumpus
** Description: returns percept
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
bool Wumpus::isWumpus() {
	return true;
}

/*********************************************************************
** Function: encounter
** Description: result of encountering
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
int Wumpus::encounter() {
	return 2;
}

int Wumpus::getType() {
	return 4;
}
