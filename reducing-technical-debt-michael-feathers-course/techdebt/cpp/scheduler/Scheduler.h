
#ifndef SCHEDULER_H
#define SCHEDULER_H


#include <vector>
#include <string>

using namespace std;

class Event;
class Date;
class Meeting;
class MailService;
class SchedulerDisplay;

#include "DayTime.h"
void			set_note(Date date, const std::string& content);
std::string		get_note(Date date);


class Scheduler
{
public:
		  Scheduler(const string& owner);
		 ~Scheduler();

	void addEvent(Event *event);
	bool hasEvents(Date date);
	bool performConsistencyCheck(string& message);

	void update();


	Meeting *getMeeting(Date date, DayTime slot) const;



private:
	vector<Event *>			events;
	MailService				*mailService;
	SchedulerDisplay		*display;
	string					owner;

	void sizeCheck(Meeting* meeting);
};


#endif
