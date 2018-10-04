

#ifndef TIMESERVICES_H
#define TIMESERVICES_H

#include "Date.h"

class TimeServices
{
public:
	static bool isPastDue(Date date);
	static bool isWorkday(Date date);
	static bool isHoliday(Date date);

};
#endif