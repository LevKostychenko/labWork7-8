#include "pch.h"
#include "DumpTrack.h"
#include "TextTable.h"

DumpTrack::DumpTrack(double fuelConsumption, double maxCapacity, const char* name, const char* transportedResources)
	: FreightVehicle(fuelConsumption, maxCapacity)
{
	int size = strlen(name) + 1;
	this->_vehicleInfo._vechicleName = new char[size];
	strcpy_s(this->_vehicleInfo._vechicleName, size, name);

	int resSize = strlen(transportedResources) + 1;
	this->TransportedResources = new char[resSize];
	strcpy_s(this->TransportedResources, resSize, transportedResources);

	std::cout << "Dump Truck Connstructor \n";
}

DumpTrack::~DumpTrack()
{
	delete this->TransportedResources;
	std::cout << "Dump truck destructor! \n";
}

DumpTrack::DumpTrack(const DumpTrack& dumpTrack)
{
	this->TransportedResources = dumpTrack.TransportedResources;
	this->_maxCarryingCapacity = dumpTrack._maxCarryingCapacity;
	this->_vehicleInfo._fuelConsumption = dumpTrack._vehicleInfo._fuelConsumption;
	this->_vehicleInfo._vechicleCategory = new char[10];
	strcpy_s(this->_vehicleInfo._vechicleCategory, 10, dumpTrack._vehicleInfo._vechicleCategory);
	this->_vehicleInfo._vechicleName = new char[10];
	strcpy_s(this->_vehicleInfo._vechicleName, 10, dumpTrack._vehicleInfo._vechicleName);
	this->_vehicleInfo._vechicleRegNumber = new char[10];
	strcpy_s(this->_vehicleInfo._vechicleRegNumber, 10, dumpTrack._vehicleInfo._vechicleRegNumber);
	this->_vehicleInfo._vechicleDistanceTreveled = dumpTrack._vehicleInfo._vechicleDistanceTreveled;
	this->_vehicleInfo._vechicleFuelLevel = dumpTrack._vehicleInfo._vechicleFuelLevel;
	this->_vehicleInfo._vehicleMaxSpeed = dumpTrack._vehicleInfo._vehicleMaxSpeed;
}

char* DumpTrack::GetTransportedResources()
{
	return this->TransportedResources;
}

void DumpTrack::SetTransportedResources(const char * resources)
{
	int size = strlen(resources) + 1;
	this->TransportedResources = new char[size];
	strcpy_s(this->TransportedResources, size, resources);
}

void DumpTrack::Move(double km)
{
	if (this->_vehicleInfo._vechicleFuelLevel == 0)
	{
		std::cout << "Fuel tank is empty! \n";
		return;
	}

	double maxTrevelDist = this->_vehicleInfo._vechicleFuelLevel / this->_vehicleInfo._fuelConsumption;

	if (maxTrevelDist < km)
	{
		std::cout << "Dump Truck drove " << maxTrevelDist << " Km \n";
		this->_vehicleInfo._vechicleFuelLevel = 0;
		this->_vehicleInfo._vechicleDistanceTreveled += km;
	}
	else
	{
		std::cout << "Dump Truck drove " << km << " Km";
		this->_vehicleInfo._vechicleFuelLevel -= this->_vehicleInfo._fuelConsumption * km;
		this->_vehicleInfo._vechicleDistanceTreveled += km;
	}
}

std::ostream & operator << (std::ostream &out, DumpTrack& vehicle)
{	
	vehicle.SetHeader();

	return out << std::endl;
}

std::istream & operator >> (std::istream &in, DumpTrack& vehicle)
{
	char* trspRes = new char[20];

	std::cout << "\nTransorted resources: ";
	InputValidator::IsInputCorrect(in, trspRes);
	vehicle.SetTransportedResources(trspRes);

	std::cin >> dynamic_cast<FreightVehicle&>(vehicle);
	return in;
}

DumpTrack& DumpTrack::operator = (DumpTrack& obj)
{
	if (this == &obj)
	{
		delete &obj;
		return *this;
	}

	this->TransportedResources = obj.TransportedResources;

	dynamic_cast<FreightVehicle&>(*this) = dynamic_cast<FreightVehicle&>(obj);

	return *this;
}

void DumpTrack::SetHeader()
{
	texttable::TextTable t;

	t.add("Tratsported resources");

	FreightVehicle::SetFreightVehicleHeader(t);
	t.endRow();
	this->SetData(t);
}

void DumpTrack::SetData(texttable::TextTable& t)
{
	t.add(this->GetTransportedResources());
	FreightVehicle::SetFreightVehicleData(t);
	t.endRow();
	std::cout << t;
}