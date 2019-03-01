/*********************************************************************
** Program Filename: bats.cpp
** Author: Jackson Perry
** Date: 2/21/19
** Description:  definition for event
*********************************************************************/
#include <iostream>
#include "bats.hpp"
#include "event.hpp"


using namespace std;

/*********************************************************************
** Function: Bat
** Description: constructor
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
Bat::Bat() {
	this->percept = "You hear wings flapping";
}

/*********************************************************************
** Function: getPercept
** Description: returns percept
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Bat::getPercept() {
	cout << this->percept << endl;
}

/*********************************************************************
** Function: isWumpus
** Description: returns if is wumpus
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
bool Bat::isWumpus() {
	return false;
}

/*********************************************************************
** Function: encounter
** Description: result of encountering
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
int Bat::encounter() {
	return 3;
}