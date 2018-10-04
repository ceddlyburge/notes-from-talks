
#pragma warning(disable:4786)

#include <map>
#include <string>

#include "Date.h"
using namespace std;

#ifdef WINDOWS
#include "windows.h"
void sleep(int milliseconds)
{
	::Sleep(milliseconds);
}
#else
void sleep(int milliseconds) {}
#endif




map<Date,string>  notes;

void set_note(Date date, const std::string& content)
{
	notes[date] = content;	
}



std::string get_note(Date date)
{
	for(int n = 0; n < 10; n++) {
#ifndef DEVELOPING
		sleep(2000);
		printf("Connecting to database... (retry %d)\n", n +1);
#endif
	}
	return notes[date];
}
