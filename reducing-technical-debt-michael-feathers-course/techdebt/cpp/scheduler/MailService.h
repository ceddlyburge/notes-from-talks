

#ifndef MAILSERVICE_H
#define MAILSERVICE_H

#include <string>

using namespace std;

class MailService
{
public:
	static MailService		*getInstance();

	void					sendMail(const string& address, const string& subject, const string& message);

private:
							MailService();
	static MailService		instance;
};


#endif