

#pragma warning(disable:4786)

#include <string>
#include <map>


#include "Scheduler.h"
#include "Date.h"
#include "Event.h"
#include "Meeting.h"
#include "MailService.h"
#include "TimeServices.h"
#include "SchedulerDisplay.h"
#include "Flextime.h"
#include "ClientAppointment.h"

using namespace std;



Scheduler::Scheduler(const string& owner)
: owner(owner)
{
	mailService = MailService::getInstance();
	display = new SchedulerDisplay;
}

Scheduler::~Scheduler()
{
	delete display;
	for(std::vector<Event *>::iterator it = events.begin(); it != events.end(); ++it) {
		delete *it;
	}
}

void Scheduler::addEvent(Event *event)
{
	event->added();
	events.push_back(event);
	mailService->sendMail("jacques@sabre.com", "Event Notification", *event);
	display->ShowEvent(event);
}

bool Scheduler::hasEvents(Date date) 
{
	for(std::vector<Event *>::iterator it = events.begin(); it != events.end(); ++it) {
		if ((*it)->getDate() == date)
			return true;
	}
	return false;
}


void Scheduler::update() 
{
	for(std::vector<Event *>::const_iterator it = events.begin(); it != events.end(); ++it) {
		Meeting *meeting = dynamic_cast<Meeting *>(*it);
		if (meeting == NULL)
			continue;

		std::string note = get_note(meeting->getDate());
		if (note.size() == 0)
			continue;

		meeting->appendToText(note);
	}
}


Meeting *Scheduler::getMeeting(Date date, DayTime slot) const
{
	for(std::vector<Event *>::const_iterator it = events.begin(); it != events.end(); ++it) {
		Meeting *meeting = dynamic_cast<Meeting *>(*it);
		if (meeting 
				&& meeting->getDate() == date 
				&& meeting->getSlot() == slot
				&& !TimeServices::isHoliday(meeting->getDate())) {
			return meeting;
		}
	}
	return 0;
}



bool Scheduler::performConsistencyCheck(string& message)
{
	message = "";
	for(std::vector<Event *>::const_iterator it = events.begin(); it != events.end(); ++it) {
		Event *e = *it;
		if (e->getSlot() > Time6PM && dynamic_cast<Meeting *>(e)) 
			message += "::No meetings after 6PM";
		if (e->getSlot() > Time8PM && dynamic_cast<ClientAppointment *>(e)) 
			message += "::No meetings after 8PM";
		if (e->getSlot() < Time9AM || e->getSlot() > Time6PM 
			&& dynamic_cast<Flextime *>(e)) 
			message += "::No Flextime outside of working hours";
		if (e->getSlot() == Time12PM
				&& dynamic_cast<Flextime *>(e)
				&& !getMeeting(e->getDate(), Time5PM))
			message += "::No deferred lunch without late scheduled meeting";
		if (e->getSlot() > Time12PM
				&& dynamic_cast<Flextime *>(e)
				&& getMeeting(e->getDate(), Time12PM)
				&& getMeeting(e->getDate(), Time1PM)
				&& getMeeting(e->getDate(), Time2PM)
				&& getMeeting(e->getDate(), Time3PM)
				&& getMeeting(e->getDate(), Time4PM)
				&& getMeeting(e->getDate(), Time5PM))				
			message += "::No flextime on afternoons of scheduled meetings";
		if (e->getSlot() > Time12PM
				&& dynamic_cast<ClientAppointment *>(e)
				&& getMeeting(e->getDate(), Time12PM)
				&& getMeeting(e->getDate(), Time1PM)
				&& getMeeting(e->getDate(), Time2PM)
				&& getMeeting(e->getDate(), Time3PM)
				&& getMeeting(e->getDate(), Time4PM)
				&& getMeeting(e->getDate(), Time5PM))				
			message += "::No client appointments on afternoons of scheduled meetings";

	}

	return message.size() == 0;
}

void Scheduler::sizeCheck(Meeting* meeting)
{

}