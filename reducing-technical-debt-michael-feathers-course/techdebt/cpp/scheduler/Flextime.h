
#ifndef FLEXTIME_H
#define FLEXTIME_H

#include <string>

#include "Date.h"
#include "DayTime.h"
#include "Event.h"


using namespace std;

enum FlextimeType
{
	DoctorsAppt,
	Emergency,
	GoofingOff,
	Personal,
};

class Flextime : public Event
{
public:
					Flextime(Date date, DayTime slot, FlextimeType type, const string& owner);
	virtual			~Flextime();

	virtual void	added();


private:
	FlextimeType	type;
	string			owner;

};


#endif
