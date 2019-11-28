#include "pch.h"
#include "Coach.h"
#include "TextTable.h"

Coach::Coach(double fuelConsumption, int maxNumberOfPersons, double ticketCost, const char* name, int countOfSections)
	: PassengerVehicle(fuelConsumption, maxNumberOfPersons, ticketCost)
{
	int size = strlen(name) + 1;
	this->_vehicleInfo._vechicleName = new char[size];
	strcpy_s(this->_vehicleInfo._vechicleName, size, name);

	this->CountOfSections = countOfSections;

	std::cout << "Coach Connstructor \n";
}

int Coach::GetCountOfSections()
{
	return this->CountOfSections;
}

void Coach::SetCountOfSections(int sections)
{
	this->CountOfSections = sections;
}

Coach::~Coach()
{
	std::cout << "Coach destructor! \n";
}

Coach::Coach(const Coach & coach)
{
	this->CountOfSections = coach.CountOfSections;
	this->_maxNumberOfPersons = coach._maxNumberOfPersons;
	this->_vehicleInfo._fuelConsumption = coach._vehicleInfo._fuelConsumption;
	this->_vehicleInfo._vechicleCategory = new char[10];
	strcpy_s(this->_vehicleInfo._vechicleCategory, 10, coach._vehicleInfo._vechicleCategory);
	this->_vehicleInfo._vechicleName = new char[10];
	strcpy_s(this->_vehicleInfo._vechicleName, 10, coach._vehicleInfo._vechicleName);
	this->_vehicleInfo._vechicleRegNumber = new char[10];
	strcpy_s(this->_vehicleInfo._vechicleRegNumber, 10, coach._vehicleInfo._vechicleRegNumber);
	this->_vehicleInfo._vechicleDistanceTreveled = coach._vehicleInfo._vechicleDistanceTreveled;
	this->_vehicleInfo._vechicleFuelLevel = coach._vehicleInfo._vechicleFuelLevel;
	this->_vehicleInfo._vehicleMaxSpeed = coach._vehicleInfo._vehicleMaxSpeed;
}

void Coach::Move(double km)
{
	if (this->_vehicleInfo._vechicleFuelLevel == 0)
	{
		std::cout << "Fuel tank is empty! \n";
		return;
	}

	double maxTrevelDist = this->_vehicleInfo._vechicleFuelLevel / this->_vehicleInfo._fuelConsumption;

	if (maxTrevelDist < km)
	{
		std::cout << "Coach drove " << maxTrevelDist << " Km \n";
		this->_vehicleInfo._vechicleFuelLevel = 0;
		this->_vehicleInfo._vechicleDistanceTreveled += km;
	}
	else
	{
		std::cout << "Coach drove " << km << " Km";
		this->_vehicleInfo._vechicleFuelLevel -= this->_vehicleInfo._fuelConsumption * km;
		this->_vehicleInfo._vechicleDistanceTreveled += km;
	}
}

double Coach::GetProfit()
{
	return this->_ticketCost*this->_maxNumberOfPersons;
}

std::ostream & operator << (std::ostream &out, Coach& vehicle)
{	
	vehicle.SetHeader();
	//std::cout << dynamic_cast<PassengerVehicle&>(vehicle);
	return out;
}

std::istream & operator >> (std::istream &in, Coach& vehicle)
{
	int countOfSections;
	std::cout << "\nCount of sections: ";
	InputValidator::IsNumberInputCorrect(in, 1, 2, countOfSections);
	vehicle.SetCountOfSections(countOfSections);
	std::cin >> dynamic_cast<PassengerVehicle&>(vehicle);
	return in;
}

Coach& Coach::operator = (Coach& obj)
{
	if (this == &obj)
	{
		delete &obj;
		return *this;
	}

	this->CountOfSections = obj.CountOfSections;

	dynamic_cast<PassengerVehicle&>(*this) = dynamic_cast<PassengerVehicle&>(obj);

	return *this;
}

void Coach::SetHeader()
{
	texttable::TextTable t;

	t.add("Count of sections");
	PassengerVehicle::SetPassengerVehicleHeader(t);
	t.endRow();
	this->SetData(t);
}

void Coach::SetData(texttable::TextTable& t)
{
	t.add(std::to_string(this->GetCountOfSections()).c_str());
	PassengerVehicle::SetPessengerVehicleData(t);	
	t.endRow();
	std::cout << t;
}