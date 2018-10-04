

#include "CentralUnit.h"
#include "Sensor.h"
#include "TextAudibleAlarm.h"
#include "TextView.h"


std::string CentralUnit::PASS = "PASS";
std::string CentralUnit::FAIL = "FAIL";
std::string CentralUnit::PENDING = "pending";
std::string CentralUnit::READY = "ready";


CentralUnit::CentralUnit()
: armed(false), audibleAlarm(new TextAudibleAlarm), 
view(new TextView), runningSensorTest(false)
{}

bool CentralUnit::isArmed() const
{
	return armed;
}


void CentralUnit::arm() 
{
	armed = true;
}


std::map<std::string,std::string>& CentralUnit::getSensorStatusMap() 
{
	return sensorStatusMap;
}
std::string CentralUnit::getSensorMessage(const Sensor& sensor) const
{
	std::string message = "default";
	if(!sensor.isTripped()) {
		if(sensor.getType() == Sensor::DOOR)
			return sensor.getLocation() + " is closed";
		else if(sensor.getType() == Sensor::WINDOW)
			return sensor.getLocation() + " is sealed";
		else if(sensor.getType() == Sensor::MOTION)
			return sensor.getLocation() + " is motionless";
		else if(sensor.getType() == Sensor::FIRE)
			return sensor.getLocation() + " temperature is normal";
	}
	else
	{
		if(sensor.getType() == Sensor::DOOR)
			return sensor.getLocation() + " is open";
		else if(sensor.getType() == Sensor::WINDOW)			return sensor.getLocation() + " is ajar";
		else if(sensor.getType() == Sensor::MOTION)
			return "Motion detected in " + sensor.getLocation();
		else if(sensor.getType() == Sensor::FIRE)
			return sensor.getLocation() + " is on FIRE!";
	}	
	return message;
}

bool CentralUnit::isValidCode(const std::string& code) const
{
	return code == securityCode;
}


void CentralUnit::setSecurityCode(const std::string& code)
{
	securityCode = code;
}

void CentralUnit::enterCode(const std::string& code)
{
	if(isValidCode(code))
	{
		armed = false;
		audibleAlarm->silence();
	}
}

std::vector<Sensor>& CentralUnit::getSensors()
{
	return sensors;
}

void CentralUnit::registerSensor(const Sensor& sensor)
{
	sensors.push_back(sensor);
}


// used during sensor test
void CentralUnit::terminateSensorTest()
{
	runningSensorTest = false;

	// look at individual sensor status to determine the overall test status
	sensorTestStatus = PASS;
	for(std::map<std::string,std::string>::iterator it = sensorStatusMap.begin(); it != sensorStatusMap.end(); ++it) {
		std::string status = it->second;
		if(status == PENDING)
		{
			sensorTestStatus = FAIL;
			break;
		}
	}
}


void CentralUnit::parseRadioBroadcast(const std::string& packet)
{
	std::string id;
	std::string status;

	// parse the packet
	size_t splitPosition = packet.find(',');
	if (splitPosition != std::string::npos) {
		id = packet.substr(0, splitPosition);
		status = packet.substr(splitPosition + 1);
	}

	// find sensor with id
	Sensor *sensor = 0;
	for(std::vector<Sensor>::iterator it = sensors.begin(); it != sensors.end(); ++it) {
		if (it->getID() == id) {
			sensor = &(*it); 
			break;
		}
	}
	
	//trip or reset sensor
	if(sensor != 0)
	{
		if("TRIPPED" == status)
			sensor->trip();
		else
			sensor->reset();
	}

	//get the message from the sensor and display it
	std::string message = getSensorMessage(*sensor);
	view->showMessage(message);

	// sound the alarm if armed
	if(isArmed())
		audibleAlarm->sound();

    // check if a sensor test is running and adjust status
	if(runningSensorTest)
	{
		if("TRIPPED" == status)
		{
			sensorStatusMap[id] = PASS;
		}

		// check to see if test is complete
		bool done = true;
		for(std::map<std::string,std::string>::iterator it = sensorStatusMap.begin(); it != sensorStatusMap.end(); ++it) {
			std::string testStatus = it->second;
			if(PENDING == testStatus)
			{
				done = false;
				break;
			}
		}

		//terminate test if complete
		if(done)
			terminateSensorTest();
	}
}


void CentralUnit::runSensorTest()
{
	runningSensorTest = true;
	sensorTestStatus = PENDING;

	// clear the status map
	sensorStatusMap.clear();

	for(std::vector<Sensor>::iterator it = sensors.begin(); it != sensors.end(); ++it) {
		sensorStatusMap[it->getID()] = PENDING;
	}
}


Sensor CentralUnit::getSensor(const std::string& id) const
{
	Sensor result("-1", "No place", Sensor::NONE);
	for(std::vector<Sensor>::const_iterator it = sensors.begin(); it != sensors.end(); ++it) {
		if (it->getID() == id)
			return *it;
	}
	return result;
}


// used during sensor test
std::string CentralUnit::getSensorStatus() const
{
	return sensorTestStatus;
}
