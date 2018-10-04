
#include "GlobalScheduler.h"
#include "DayTime.h"
#include "Date.h"
#include "Job.h"


bool gs_hasClient(const string& client)
{
	return false;
}

bool gs_jobExistsFor(Date date, DayTime slot)
{
	return false;
}

Job gs_getJob(Date date, DayTime slot)
{
	Job j;
	return j; 
}

string gs_emailAddressForClient(const string& owner)
{
	return "";
}
