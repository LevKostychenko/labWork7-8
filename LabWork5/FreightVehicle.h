#pragma once
#include "Vehicle.h"

class FreightVehicle : public Vehicle
{
public:
	FreightVehicle(double, double);
	FreightVehicle();
	virtual ~FreightVehicle();

public: 
	double GetMaxCarryingCapacity();
	void SetMaxCarryingCapacity(double);	

public:
	static void SetFreightVehicleHeader(texttable::TextTable& t);
	void SetFreightVehicleData(texttable::TextTable& t);
	FreightVehicle& operator = (FreightVehicle& obj);
	friend std::ostream & operator << (std::ostream &out, FreightVehicle& vehicle);
	friend std::istream & operator >> (std::istream &in, FreightVehicle& vehicle);

protected:
	double _maxCarryingCapacity{ 0 };
};

