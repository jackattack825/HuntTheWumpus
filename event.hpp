/*********************************************************************
** Program Filename: event.hpp
** Author: Jackson Perry
** Date: 2/21/19
** Description: class definition for event
*********************************************************************/
#ifndef event
#define event

#include <string>
using namespace std;

class Event {
private:
	string percept;

public:
	Event() {
		percept = "should never be used";
	}
	virtual void getPercept()=0;
	virtual int encounter()=0; // returns # for event type
	virtual bool isWumpus() = 0;
};


#endif