
#ifndef MEETING_H
#define MEETING_H

#include <string>

#include "DayTime.h"
#include "Event.h"
#include "Date.h"

class Meeting : public Event
{
public:
						Meeting(
							Date date, 
							DayTime slot, 
							const std::string& description);
	virtual				~Meeting();

	std::string			getText() const;
	void				appendToText(const std::string& newText);
	virtual bool		isPastDue();

	virtual operator	string() const;

protected:
	string				formatText(const string& text) const;



private:
	std::string			description;
};

#endif