#pragma once
#include "Vehicle.h"

class PassengerVehicle : public Vehicle
{
public:
	PassengerVehicle(double, int, double);
	PassengerVehicle();
	virtual ~PassengerVehicle();

public:
	double GetMaxNumberOfPersons();
	void SetMaxNumberOfPersons(int);
	double GetTicketCost();
	void SetTicketCost(double);

	virtual double GetProfit() = 0;


public:
	static void SetPassengerVehicleHeader(texttable::TextTable& t);
	void SetPessengerVehicleData(texttable::TextTable& t);
	PassengerVehicle& operator = (PassengerVehicle& obj);
	friend std::ostream & operator << (std::ostream &out, PassengerVehicle& vehicle);
	friend std::istream & operator >> (std::istream &in, PassengerVehicle& vehicle);

protected:
	int _maxNumberOfPersons{ 0 };
	double _ticketCost{ 0 };
};

