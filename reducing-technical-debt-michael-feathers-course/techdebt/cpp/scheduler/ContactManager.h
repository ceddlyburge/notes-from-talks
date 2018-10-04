

#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include <string>
using namespace std;

class Contact;
class RemoteContactService;

class ContactManager
{
public:
				ContactManager();
				~ContactManager();

	Contact		getContact(const string& name);



private:
	RemoteContactService   *service;


};


#endif