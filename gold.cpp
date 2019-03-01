/*********************************************************************
** Program Filename: gold.cpp
** Author: Jackson Perry
** Date: 2/21/19
** Description: definition for gold
*********************************************************************/

#include <iostream>
#include "event.hpp"
#include "gold.hpp"


using namespace std;

/*********************************************************************
** Function: Gold
** Description: constructor
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
Gold::Gold() {
	this->percept = "You see a glimmer nearby";
}

/*********************************************************************
** Function: getPercept
** Description: returns percept
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Gold::getPercept() {
	cout << this->percept << endl;
}

/*********************************************************************
** Function: isWumpus
** Description: returns if is wumpus
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
bool Gold::isWumpus() {
	return false;
}

/*********************************************************************
** Function: encounter
** Description: result of encountering
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
int Gold::encounter() {
	return 4;
}

/*********************************************************************
** Function: getType
** Description: returns type
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
int Gold::getType() {
	return 2;
}

