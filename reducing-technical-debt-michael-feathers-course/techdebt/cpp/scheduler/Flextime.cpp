
#include "Flextime.h"
#include "MailService.h"
#include "GlobalScheduler.h"
#include "Job.h"

Flextime::Flextime(Date date, DayTime slot, FlextimeType type, const string& owner)
: Event(date, slot), type(type), owner(owner)
{
}

Flextime::~Flextime()
{}


void Flextime::added()
{
	if (type == GoofingOff) {
		if (gs_hasClient(owner) 
				&& gs_jobExistsFor(getDate(), getSlot())) {

			Job  job = gs_getJob(getDate(), getSlot());
			string address = gs_emailAddressForClient(owner);
			string subject = "Hey, could you take care of this for me?";
			string message = "I need " + job.description() + " done as soon as possible.  Please help me out.\n\nMark Marcus CEO";
			MailService::getInstance()->sendMail(address, subject, message);
		}
	}
}




