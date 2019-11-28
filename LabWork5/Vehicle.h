#pragma once
#include "VehicleInfo.h"
#include <cstring>
#include <iostream>
#include "InputException.h"
#include "TextTable.h"
#include "InputValidator.h"

class Vehicle
{
public:
	Vehicle();
	virtual ~Vehicle();
	
public:
	 char* GetName();
	 char* GetRegNumber();
	 char* GetCategory();
	 double GetFuelLevel();
	 double GetDistanceTreveled();
	 double GetMaxSpeed();
	 double GetFuelConsumption();

public: 
	 void SetName(const char*);
	 void SetRegNumber(const char*);
	 void SetCategory(const char*);
	 void SetFuelLevel(double);
	 void SetDistanceTreveled(double);
	 void SetMaxSpeed(double);
	 void SetFuelConsumption(double);

public:
	virtual void Move(double) = 0;
	static void SetBaseHeader(texttable::TextTable& t);

	Vehicle& operator = (const Vehicle& obj);
	friend std::ostream & operator << (std::ostream &out, Vehicle& vehicle);
	friend std::istream & operator >> (std::istream &in, Vehicle& vehicle);

	void SetBaseData(texttable::TextTable& t);

protected:
	VechicleInfo _vehicleInfo;

};

