
#pragma once


#include <string>

class Sensor
{
public:
	enum Type { DOOR, WINDOW, MOTION, FIRE, NONE };

	Sensor(const std::string& id, 
			const std::string& location, 
			Type type);

	std::string getID () const;
	std::string getLocation() const;
	Type getType() const;

	bool isTripped() const;
	void trip();
	void reset();

private:
	std::string id;
	std::string location;
	Type type;
	bool tripped;
};
