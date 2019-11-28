#include "pch.h"
#include "FreightVehicle.h"
#include "GarbageTruck.h"
#include "Coach.h"
#include "TextTable.h"

FreightVehicle::FreightVehicle()
{
	std::cout << "Freight Vehicle Connstructor \n";
}

FreightVehicle::FreightVehicle(double fuelConsumption = 0, double maxCapacity = 0)
{
	int catSize = strlen("Freight") + 1;
	this->_maxCarryingCapacity = maxCapacity;
	this->_vehicleInfo._vechicleCategory = new char[catSize];
	strcpy_s(this->_vehicleInfo._vechicleCategory, catSize, "Freight");


	this->_vehicleInfo._fuelConsumption = fuelConsumption;
	this->_vehicleInfo._vechicleFuelLevel = 100;
	this->_vehicleInfo._vechicleDistanceTreveled = 0;

	std::cout << "Freight Vehicle Connstructor \n";
}

FreightVehicle::~FreightVehicle()
{
	std::cout << "Freight vehicle destructor\n";
}

double FreightVehicle::GetMaxCarryingCapacity()
{
	return this->_maxCarryingCapacity;
}

void FreightVehicle::SetMaxCarryingCapacity(double maxCapacity)
{
	this->_maxCarryingCapacity = maxCapacity;
}

FreightVehicle& FreightVehicle::operator = (FreightVehicle& obj)
{
	if (this == &obj)
	{
		delete &obj;
		return *this;
	}
		
	this->SetMaxCarryingCapacity(obj._maxCarryingCapacity);
	dynamic_cast<Vehicle&>(*this) = dynamic_cast<Vehicle&>(obj);

	return *this;
}

std::ostream & operator << (std::ostream &out, FreightVehicle& vehicle)
{	
	texttable::TextTable t;
	vehicle.SetFreightVehicleHeader(t);
	//std::cout << dynamic_cast<Vehicle&>(vehicle);

	return out << std::endl;
}

std::istream & operator >> (std::istream &in, FreightVehicle& vehicle)
{
	int carCap;

	std::cout << "\nMax carrying capacity: ";
	InputValidator::IsNumberInputCorrect(in, 0, 2000, carCap);

	vehicle.SetMaxCarryingCapacity(carCap);
	std::cin >> dynamic_cast<Vehicle&>(vehicle);
	return in;
}

void FreightVehicle::SetFreightVehicleHeader(texttable::TextTable& t)
{		
	t.add("Max carrying capacity");	
	Vehicle::SetBaseHeader(t);
}

void FreightVehicle::SetFreightVehicleData(texttable::TextTable& t)
{
	t.add(std::to_string(this->GetMaxCarryingCapacity()).c_str());
	Vehicle::SetBaseData(t);
}
