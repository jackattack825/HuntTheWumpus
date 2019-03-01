/*********************************************************************
** Program Filename: pit.cpp
** Author: Jackson Perry
** Date: 2/21/19
** Description:  definition for event
*********************************************************************/

#include <iostream>
#include "pit.hpp"
#include "event.hpp"


using namespace std;

/*********************************************************************
** Function: Pit
** Description: constructor
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
Pit::Pit() {
	this->percept = "You feel a breeze";
}

/*********************************************************************
** Function: getPercept
** Description: returns percept
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Pit::getPercept() {
	cout << this->percept << endl;
}

/*********************************************************************
** Function: isWumpus
** Description: returns if is wumpus
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
bool Pit::isWumpus() {
	return false;
}

/*********************************************************************
** Function: encounter
** Description: result of encountering
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
int Pit::encounter() {
	return 1;
}

/*********************************************************************
** Function: getType
** Description: returns type
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
int Pit::getType() {
	return 1;
}
