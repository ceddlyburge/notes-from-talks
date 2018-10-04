

#include <sstream>
#include <string>
#include "Meeting.h"
#include "TimeServices.h"

using namespace std;

Meeting::Meeting(Date date, DayTime slot, const std::string& description)
: Event(date, slot), description(description)
{
}


Meeting::~Meeting()
{
}

string Meeting::getText() const
{
	return description;
}

bool Meeting::isPastDue()
{
	return TimeServices::isPastDue(getDate());
};


Meeting::operator string() const
{
	int n = 0;
	std::stringstream buffer;
	buffer << Event::operator string();

	string result = formatText(description);

	buffer << "[" << result.size();
	for (n = 0; n < result.size(); n++)
		buffer << "{";

	buffer << formatText(description);

	for (n = 0; n < result.size(); n++)
		buffer << "}";
	buffer << result.size() << "]";

	return buffer.str();
}


void Meeting::appendToText(const std::string& newText)
{
	description += newText;
}


string Meeting::formatText(const string& text) const
{
	string result = "";
	for (int n = 0; n < text.size(); ++n) {
		int c = text[n];
		if (c == '<') {
			while(text[n] != '/' && text[n] != '>')
				n++;
			if (text[n] == '/')
				n+=4;
			else
				n++;
		}
		if (n < text.size())
			result.append(1, text[n]);
	}
	return result;
}



