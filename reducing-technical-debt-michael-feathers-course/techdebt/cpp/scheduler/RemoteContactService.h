

#ifndef REMOTECONTACTSERVICE_H
#define REMOTECONTACTSERVICE_H

#include <string>

using namespace std;

class RemoteContactService
{
public:
	string getSubscriberBase(const string& name, const string& department);
	string getContactInfo(const string& name);

};

#endif