
#ifndef CLIENTAPPOINTMENT_H
#define CLIENTAPPOINTMENT_H

#include <string>

#include "DayTime.h"
#include "Meeting.h"

class ContactManager;

class ClientAppointment : public Meeting
{
public:
						ClientAppointment(
							Date date, 
							DayTime slot, 
							const std::string& description,
							string clientName);
	virtual				~ClientAppointment();
	virtual bool		isPastDue() { return false; }
	virtual operator string() const;



private:
	string				clientName;
	ContactManager		*manager;
	string				text;
};


#endif