/*********************************************************************
** Program Filename: gold.hpp
** Author: Jackson Perry
** Date: 2/21/19
** Description: class definition for gold
*********************************************************************/
#ifndef gold
#define gold

#include <string>
#include "event.hpp"

using namespace std;

class Gold : public Event {
private:
	string percept;

public:
	Gold();
	void getPercept();
	int encounter();
	bool isWumpus();
	int getType();
};

#endif