
#ifndef DATE_H
#define DATE_H

#include <string>
#include <ostream>

using namespace std;

class Date
{

public:
	Date(const std::string& dateString);
	std::string getText() const;

	friend bool operator==(const Date& left, const Date& other);
	friend bool operator<(const Date& left, const Date& other);
	friend ostream& operator<<(ostream& o, const Date& date);


private:
	string representation;

};
#endif