
#ifndef GLOBALSCHEDULER_H
#define GLOBALSCHEDULER_H


#include <string>
#include "DayTime.h"
using namespace std;

class Job;
class Date;

bool		gs_hasClient(const string& client);
bool		gs_jobExistsFor(Date date, DayTime slot);
Job			gs_getJob(Date date, DayTime slot);
string		gs_emailAddressForClient(const string& owner);


#endif
