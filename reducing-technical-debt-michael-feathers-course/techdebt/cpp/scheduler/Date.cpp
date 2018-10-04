
#include "Date.h"


Date::Date(const std::string& dateString)
: representation(dateString)
{
}


bool operator==(const Date& left,const Date& right)
{
	return left.getText() == right.getText();
}

bool operator<(const Date& left, const Date& right)
{
	return left.getText() < right.getText();
}


std::string Date::getText() const
{
	return representation;
}


ostream& operator<<(ostream& o, const Date& date)
{
	o << date.getText();
	return o;
}