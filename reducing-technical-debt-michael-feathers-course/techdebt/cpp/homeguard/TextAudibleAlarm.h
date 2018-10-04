
#pragma once

#include "AudibleAlarm.h"

class TextAudibleAlarm : public AudibleAlarm
{
public:
	virtual void sound();
	virtual void silence();
};