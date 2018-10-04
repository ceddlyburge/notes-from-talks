
#pragma once

class MockAudibleAlarm : public AudibleAlarm
{
public:
	virtual void sound();
	virtual void silence();
};