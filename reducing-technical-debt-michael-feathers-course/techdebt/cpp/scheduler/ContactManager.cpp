
#include "ContactManager.h"
#include "Contact.h"
#include "RemoteContactService.h"


ContactManager::ContactManager()
: service(new RemoteContactService)
{
}


ContactManager::~ContactManager()
{
	delete service;
}


Contact ContactManager::getContact(const string& clientName)
{
	string sub = service->getSubscriberBase(clientName, "TRE");	

	Contact c("default", 10, "ContactManager");

	if (sub == "PAX") {
			c.setInfo(service->getContactInfo(clientName));
	}
	else {
		c.setInfo("pass");
	}
	return c;

}