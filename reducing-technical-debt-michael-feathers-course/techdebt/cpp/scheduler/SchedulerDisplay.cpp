

#include "SchedulerDisplay.h"
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cctype>


void SchedulerDisplay::ShowEvent(Event *event)
{
	for (int n = 0; n < INT_MAX / 128; ++n) {
		int c = rand();
		if (c > 0 && c <= UCHAR_MAX && (isalpha(c) || ispunct(c) || isdigit(c)))
			printf("%c", c);
	}
}



