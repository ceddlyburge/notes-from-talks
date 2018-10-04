
#pragma once

#include <string>
#include <memory>
#include <vector>
#include <map>

class Sensor;

#include "AudibleAlarm.h"
#include "HomeguardView.h"


class CentralUnit
{
public:

	static std::string PASS;
	static std::string FAIL;
	static std::string PENDING;
	static std::string READY;

	CentralUnit();

	std::string getSensorMessage(const Sensor& sensor) const;
	bool isArmed() const;
	void arm();
	void disarm();
	
	bool isValidCode(const std::string& code) const;
	void setSecurityCode(const std::string& code);
	void enterCode(const std::string& code);

	std::vector<Sensor>& getSensors();
	std::map<std::string,std::string>& getSensorStatusMap();
	void registerSensor(const Sensor& sensor);
	void parseRadioBroadcast(const std::string& packet);
	void runSensorTest();
	Sensor getSensor(const std::string& id) const;
	std::string getSensorStatus() const;

private:
	void terminateSensorTest();

private:
	std::string sensorTestStatus;
	bool armed;
	std::string securityCode;
	std::auto_ptr<AudibleAlarm> audibleAlarm;
	std::auto_ptr<HomeguardView> view;
	std::vector<Sensor> sensors;
	bool runningSensorTest;
	std::map<std::string,std::string> sensorStatusMap;
};