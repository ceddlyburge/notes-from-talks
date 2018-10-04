
#include "Sensor.h"

	
Sensor::Sensor(const std::string& id, 
			   const std::string& location, 
			   Type type)
: id(id), location(location), type(type), tripped(false)
{
}


std::string Sensor::getID () const
{
	return id;
}

std::string Sensor::getLocation () const
{
	return location;
}

Sensor::Type Sensor::getType () const
{
	return type;
}

bool Sensor::isTripped () const
{
	return tripped;
}

void Sensor::trip() 
{
	tripped = true;
}

void Sensor::reset()
{
	tripped = false;
}


