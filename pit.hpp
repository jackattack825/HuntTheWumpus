/*********************************************************************
** Program Filename: pit.hpp
** Author: Jackson Perry
** Date: 2/21/19
** Description: class definition for pit
*********************************************************************/
#ifndef pit
#define pit

#include <string>
#include "event.hpp"

using namespace std;

class Pit : public Event {
private:
	string percept;

public:
	Pit();
	void getPercept();
	int encounter();
	bool isWumpus();
	int getType();
};


#endif