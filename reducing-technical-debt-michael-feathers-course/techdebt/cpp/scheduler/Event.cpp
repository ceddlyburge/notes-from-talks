
#include <sstream>
#include "Event.h"
#include "Date.h"



Event::Event(Date date, DayTime slot)
: date(date), slot(slot)
{
}


void Event::added()
{
}

Date Event::getDate() const
{
	return date;
}

DayTime Event::getSlot() const
{
	return slot;
}

Event::operator string() const
{
	std::stringstream buffer;

	buffer << date << " @" << slot << ":00 hours";
	return buffer.str();
}


