#include "pch.h"
#include "TrolleyBus.h"
#include "TextTable.h"

TrolleyBus::TrolleyBus(double fuelConsumption, int maxNumberOfPersons, double ticketCost, const char* name, double chargeLevel)
	: PassengerVehicle(fuelConsumption, maxNumberOfPersons, ticketCost)
{
	int size = strlen(name) + 1;
	this->_vehicleInfo._vechicleName = new char[size];
	strcpy_s(this->_vehicleInfo._vechicleName, size, name);

	this->ChargeLevel;

	std::cout << "Trolley Bus Connstructor \n";
}

TrolleyBus::TrolleyBus(const TrolleyBus& trolleyBus)
{
	this->ChargeLevel = trolleyBus.ChargeLevel;
	this->_maxNumberOfPersons = trolleyBus._maxNumberOfPersons;
	this->_vehicleInfo._fuelConsumption = trolleyBus._vehicleInfo._fuelConsumption;
	this->_vehicleInfo._vechicleCategory = new char[10];
	strcpy_s(this->_vehicleInfo._vechicleCategory, 10, trolleyBus._vehicleInfo._vechicleCategory);
	this->_vehicleInfo._vechicleName = new char[10];
	strcpy_s(this->_vehicleInfo._vechicleName, 10, trolleyBus._vehicleInfo._vechicleName);
	this->_vehicleInfo._vechicleRegNumber = new char[10];
	strcpy_s(this->_vehicleInfo._vechicleRegNumber, 10, trolleyBus._vehicleInfo._vechicleRegNumber);
	this->_vehicleInfo._vechicleDistanceTreveled = trolleyBus._vehicleInfo._vechicleDistanceTreveled;
	this->_vehicleInfo._vechicleFuelLevel = trolleyBus._vehicleInfo._vechicleFuelLevel;
	this->_vehicleInfo._vehicleMaxSpeed = trolleyBus._vehicleInfo._vehicleMaxSpeed;
}

double TrolleyBus::GetChargeLevel()
{
	return this->ChargeLevel;
}

void TrolleyBus::SetChargeLevel(double level)
{
	this->ChargeLevel = level;
}

TrolleyBus::~TrolleyBus()
{
	std::cout << "Trolley Bus destructor! \n";
}

void TrolleyBus::Move(double km)
{
	if (this->_vehicleInfo._vechicleFuelLevel == 0)
	{
		std::cout << "Fuel tank is empty! \n";
		return;
	}

	double maxTrevelDist = this->_vehicleInfo._vechicleFuelLevel / this->_vehicleInfo._fuelConsumption;

	if (maxTrevelDist < km)
	{
		std::cout << "Trolley Bus drove " << maxTrevelDist << " Km \n";
		this->_vehicleInfo._vechicleFuelLevel = 0;
		this->_vehicleInfo._vechicleDistanceTreveled += km;
	}
	else
	{
		std::cout << "Trolley Bus drove " << km << " Km";
		this->_vehicleInfo._vechicleFuelLevel -= this->_vehicleInfo._fuelConsumption * km;
		this->_vehicleInfo._vechicleDistanceTreveled += km;
	}
}

std::ostream & operator << (std::ostream &out, TrolleyBus& vehicle)
{	
	vehicle.SetHeader();
	//std::cout << dynamic_cast<PassengerVehicle&>(vehicle);
	return out;
}

std::istream & operator >> (std::istream &in, TrolleyBus& vehicle)
{
	int charge;
	std::cout << "\nCharge level: ";
	InputValidator::IsNumberInputCorrect(in, 0, 100, charge);
	vehicle.SetChargeLevel(charge);

	std::cin >> dynamic_cast<PassengerVehicle&>(vehicle);
	return in;
}

double TrolleyBus::GetProfit()
{
	return this->_ticketCost*this->_maxNumberOfPersons;
}

TrolleyBus& TrolleyBus::operator = (TrolleyBus& obj)
{
	if (this == &obj)
	{
		delete &obj;
		return *this;
	}

	this->ChargeLevel = obj.ChargeLevel;

	dynamic_cast<PassengerVehicle&>(*this) = dynamic_cast<PassengerVehicle&>(obj);

	return *this;
}

void TrolleyBus::SetHeader()
{
	texttable::TextTable t;

	t.add("Level of charge");
	PassengerVehicle::SetPassengerVehicleHeader(t);
	t.endRow();
	this->SetData(t);
}

void TrolleyBus::SetData(texttable::TextTable& t)
{
	t.add(std::to_string(this->GetChargeLevel()).c_str());
	PassengerVehicle::SetPessengerVehicleData(t);
	t.endRow();
	std::cout << t;
}