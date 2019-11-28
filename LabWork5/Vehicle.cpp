#include "pch.h"
#include "Vehicle.h"
#include "Coach.h"
#include "TextTable.h"
#include "InputValidator.h"

Vehicle::Vehicle()
{
	std::cout << "Vehicle constructor\n";
}


Vehicle::~Vehicle()
{
	delete this->_vehicleInfo._vechicleCategory;
	delete this->_vehicleInfo._vechicleName;
	delete this->_vehicleInfo._vechicleRegNumber;

	std::cout << "Vehicle destructor\n";
}

char* Vehicle::GetName()
{
	return this->_vehicleInfo._vechicleName;
}

char* Vehicle::GetRegNumber()
{
	return this->_vehicleInfo._vechicleRegNumber;
}

char* Vehicle::GetCategory()
{
	return this->_vehicleInfo._vechicleCategory;
}

double Vehicle::GetFuelLevel()
{
	return this->_vehicleInfo._vechicleFuelLevel;
}

double Vehicle::GetDistanceTreveled()
{
	return this->_vehicleInfo._vechicleDistanceTreveled;
}

double Vehicle::GetMaxSpeed()
{
	return this->_vehicleInfo._vehicleMaxSpeed;
}

double Vehicle::GetFuelConsumption()
{
	return this->_vehicleInfo._fuelConsumption;
}

void Vehicle::SetName(const char* name)
{
	int size = strlen(name) + 1;
	this->_vehicleInfo._vechicleName = new char[size];
	strcpy_s(this->_vehicleInfo._vechicleName, size, name);
}

void Vehicle::SetRegNumber(const char* number)
{
	int size = strlen(number) + 1;
	this->_vehicleInfo._vechicleRegNumber = new char[size];
	strcpy_s(this->_vehicleInfo._vechicleRegNumber, size, number);
}

void Vehicle::SetCategory(const char* category)
{
	int size = strlen(category) + 1;
	this->_vehicleInfo._vechicleCategory = new char[size];
	strcpy_s(this->_vehicleInfo._vechicleCategory, size, category);
}

void Vehicle::SetFuelLevel(double fuelLevel)
{
	this->_vehicleInfo._vechicleFuelLevel = fuelLevel;
}

void Vehicle::SetFuelConsumption(double fuelConsumption)
{
	this->_vehicleInfo._fuelConsumption = fuelConsumption;
}

void Vehicle::SetDistanceTreveled(double distance)
{
	this->_vehicleInfo._vechicleDistanceTreveled = distance;
}

void Vehicle::SetMaxSpeed(double maxSpeed)
{
	this->_vehicleInfo._vehicleMaxSpeed = maxSpeed;
}

std::ostream & operator << (std::ostream &out, Vehicle& vehicle)
{
	texttable::TextTable t;

	t.add("Name");
	t.add("Category");
	t.add("Max speed");
	t.add("Fuel consumption");
	t.add("Current fuel level");
	t.add("Distance treveled");
	t.add("Registration number");
	t.endRow();

	t.add(vehicle.GetName());
	t.add(vehicle.GetCategory());
	t.add(std::to_string(vehicle.GetFuelConsumption()).c_str());
	t.add(std::to_string(vehicle.GetFuelLevel()).c_str());
	t.add(std::to_string(vehicle.GetDistanceTreveled()).c_str());
	t.add(vehicle.GetRegNumber());
	t.endRow();

	std::cout << t;

	return out;
}

std::istream & operator >> (std::istream &in, Vehicle& vehicle)
{
	char* name = new char[80];
	char* category = new char[20];
	int maxSpeed;
	int fuelCons;
	int curFuelLvl;
	int dist;
	int regNumber;

	std::cout << "Name: ";
	InputValidator::IsInputCorrect(in, name);
	std::cout << "\nCategory: ";
	InputValidator::IsInputCorrect(in, category);
	std::cout << "\nMax speed: ";
	InputValidator::IsNumberInputCorrect(in, 10, 300, maxSpeed);
	std::cout << "\nFuel consumption: ";
	InputValidator::IsNumberInputCorrect(in, 0, 100, fuelCons);
	std::cout << "\nCurrent fuel level: ";
	InputValidator::IsNumberInputCorrect(in, 0, 100, curFuelLvl);
	std::cout << "\nDistance treveled: ";
	InputValidator::IsNumberInputCorrect(in, 0, 30000, dist);
	std::cout << "\nRegistration number: ";
	InputValidator::IsNumberInputCorrect(in, 0, 100000, regNumber);

	vehicle.SetName(name);
	vehicle.SetCategory(category);
	vehicle.SetMaxSpeed(maxSpeed);
	vehicle.SetFuelConsumption(fuelCons);
	vehicle.SetFuelLevel(curFuelLvl);
	vehicle.SetDistanceTreveled(dist);

	vehicle.SetRegNumber(std::to_string(regNumber).c_str());

	return in;
}

Vehicle& Vehicle::operator = (const Vehicle& obj)
{
	this->SetCategory(obj._vehicleInfo._vechicleCategory);
	this->_vehicleInfo._vechicleDistanceTreveled = obj._vehicleInfo._vechicleDistanceTreveled;
	this->_vehicleInfo._fuelConsumption = obj._vehicleInfo._fuelConsumption;
	this->_vehicleInfo._vechicleFuelLevel = obj._vehicleInfo._vechicleFuelLevel;
	this->_vehicleInfo._vehicleMaxSpeed = obj._vehicleInfo._vehicleMaxSpeed;
	this->SetName(obj._vehicleInfo._vechicleName);
	this->SetRegNumber(obj._vehicleInfo._vechicleRegNumber);

	return *this;
}

void Vehicle::SetBaseHeader(texttable::TextTable& t)
{
	t.add("Name");
	t.add("Category");
	t.add("Max speed");
	t.add("Fuel consumption");
	t.add("Current fuel level");
	t.add("Distance treveled");
	t.add("Registration number");
}

void Vehicle::SetBaseData(texttable::TextTable& t)
{
	t.add(this->GetName());
	t.add(this->GetCategory());
	t.add(std::to_string(this->GetMaxSpeed()).c_str());
	t.add(std::to_string(this->GetFuelConsumption()).c_str());
	t.add(std::to_string(this->GetFuelLevel()).c_str());
	t.add(std::to_string(this->GetDistanceTreveled()).c_str());
	t.add(this->GetRegNumber());
}
