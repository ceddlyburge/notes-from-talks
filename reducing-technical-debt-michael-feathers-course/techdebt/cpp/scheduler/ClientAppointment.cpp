
#include "ClientAppointment.h"
#include "ContactManager.h"
#include "Contact.h"


ClientAppointment::ClientAppointment(
							Date date, 
							DayTime slot, 
							const std::string& description,
							string clientName)
							: Meeting(date, slot, description),
							clientName(clientName)
{
	manager = new ContactManager;

	Contact contact = manager->getContact(clientName);

	text = contact.getInfo();
}

ClientAppointment::~ClientAppointment()
{
	delete manager;
}


ClientAppointment::operator string() const
{
	return formatText(text);
}
