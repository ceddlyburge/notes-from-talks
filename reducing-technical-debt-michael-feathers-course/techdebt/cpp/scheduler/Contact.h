

#ifndef CONTACT_H
#define CONTACT_H

#include <string>
using namespace std;

class Contact
{
public:
				Contact(const string& type, 
					int securityLevel, 
					const string& source);

	void setInfo(const string& contactInfo);
	string getInfo() const;

private:
	string text;
};

#endif
