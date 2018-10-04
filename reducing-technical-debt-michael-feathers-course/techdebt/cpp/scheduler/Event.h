

#ifndef EVENT_H
#define EVENT_H

#include <string>

#include "Date.h"
#include "DayTime.h"


using namespace std;


class Event
{
public:
					Event(Date date, DayTime slot);
	virtual			~Event() {}

	virtual void	added();
	Date			getDate() const;
	DayTime			getSlot() const;

	virtual operator string() const;

private:

	string			stringForDayTime(DayTime dayTime) const;
	Date			date;
	DayTime			slot;
};


#endif
