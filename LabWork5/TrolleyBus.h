#pragma once
#include "PassengerVehicle.h"

class TrolleyBus : public PassengerVehicle
{
public:
	TrolleyBus(double fuelConsumption = 0, int maxNumberOfPersons = 0, double ticketCost = 0, const char* name = new char[10]{ "undefine" }, double chargeLevel = 0);
	~TrolleyBus();
	TrolleyBus(const TrolleyBus& TrolleyBus);

public:
	void Move(double) override;
	double GetProfit() override;
	double GetChargeLevel();
	void SetChargeLevel(double level);

	void SetHeader();
	void SetData(texttable::TextTable& t);
	TrolleyBus& operator = (TrolleyBus& obj);
	friend std::ostream & operator << (std::ostream &out, TrolleyBus& vehicle);
	friend std::istream & operator >> (std::istream &in, TrolleyBus& vehicle);

private:
	double ChargeLevel;
};

