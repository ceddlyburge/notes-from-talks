
#include "Contact.h"


Contact::Contact(const string& type, int securityLevel, const string& source)
{
}

void Contact::setInfo(const string& contactInfo)
{
	text = contactInfo;
}

string Contact::getInfo() const
{
	return text;
}