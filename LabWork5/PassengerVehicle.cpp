#include "pch.h"
#include "PassengerVehicle.h"
#include "Coach.h"
#include "TextTable.h"

PassengerVehicle::PassengerVehicle()
{
	std::cout << "Passenger Vehicle Connstructor \n";
}

PassengerVehicle::PassengerVehicle(double fuelConsumption = 0, int maxNumberOfPersons = 0, double ticketCost = 0)
{
	int catSize = strlen("Passenger") + 1;
	this->_maxNumberOfPersons = maxNumberOfPersons;
	this->_vehicleInfo._vechicleCategory = new char[catSize];
	strcpy_s(this->_vehicleInfo._vechicleCategory, catSize, "Passenger");

	this->_ticketCost = ticketCost;

	this->_vehicleInfo._fuelConsumption = fuelConsumption;
	this->_vehicleInfo._vechicleFuelLevel = 100;
	this->_vehicleInfo._vechicleDistanceTreveled = 0;

	std::cout << "Passenger Vehicle Connstructor \n";
}

PassengerVehicle::~PassengerVehicle()
{
	std::cout << "Pessenger Vehicle destructor\n";
}

double PassengerVehicle::GetMaxNumberOfPersons()
{
	return this->_maxNumberOfPersons;
}

double PassengerVehicle::GetTicketCost()
{
	return this->_ticketCost;
}

void PassengerVehicle::SetMaxNumberOfPersons(int maxNumOfPersons)
{
	this->_maxNumberOfPersons = maxNumOfPersons;
}

void PassengerVehicle::SetTicketCost(double ticketCost)
{
	this->_ticketCost = ticketCost;
}

PassengerVehicle& PassengerVehicle::operator = (PassengerVehicle& obj)
{
	if (this == &obj)
	{
		delete &obj;
		return *this;
	}

	this->SetMaxNumberOfPersons(obj._maxNumberOfPersons);
	this->SetTicketCost(obj._ticketCost);

	dynamic_cast<Vehicle&>(*this) = dynamic_cast<Vehicle&>(obj);

	return *this;
}

std::ostream & operator << (std::ostream &out, PassengerVehicle& vehicle)
{	
	std::cout << dynamic_cast<Vehicle&>(vehicle);

	return out << std::endl;
}

std::istream & operator >> (std::istream &in, PassengerVehicle& vehicle)
{
	int cost;
	int numberOfPassengers;

	std::cout << "\nMax number of pessengers: ";
	InputValidator::IsNumberInputCorrect(in, 0, 40, numberOfPassengers);
	std::cout << "\nTicket cost: ";
	InputValidator::IsNumberInputCorrect(in, 0, 100, cost);

	vehicle.SetMaxNumberOfPersons(numberOfPassengers);
	vehicle.SetTicketCost(cost);

	std::cin >> dynamic_cast<Vehicle&>(vehicle);
	return in;
}

void PassengerVehicle::SetPassengerVehicleHeader(texttable::TextTable& t)
{
	t.add("Max number of pessengers");
	t.add("Ticket cost");

	Vehicle::SetBaseHeader(t);
}

void PassengerVehicle::SetPessengerVehicleData(texttable::TextTable& t)
{
	t.add(std::to_string(this->GetMaxNumberOfPersons()).c_str());
	t.add(std::to_string(this->GetTicketCost()).c_str());
	Vehicle::SetBaseData(t);
}