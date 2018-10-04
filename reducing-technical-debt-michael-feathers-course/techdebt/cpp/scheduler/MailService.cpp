

#include "MailService.h"


MailService MailService::instance;

MailService::MailService()
{
}

MailService *MailService::getInstance()
{
	return &instance;
}


void MailService::sendMail(const string& address, const string& subject, const string& message) 
{
}

