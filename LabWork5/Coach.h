#pragma once
#include "PassengerVehicle.h"

class Coach : public PassengerVehicle
{
public:
	Coach(double fuelConsumption = 0, int maxNumberOfPersons = 0, double ticketCost = 0, const char* name = new char[10]{ "undefine" }, int countOfSections = 0);
	~Coach();

	Coach(const Coach &coach);

public:
	void Move(double) override;
	double GetProfit() override;
	int GetCountOfSections();
	void SetCountOfSections(int count);	

	void SetHeader();
	void SetData(texttable::TextTable& t);
	Coach& operator = (Coach& obj);
	friend std::ostream & operator << (std::ostream &out, Coach& vehicle);
	friend std::istream & operator >> (std::istream &in, Coach& vehicle);

private:
	int CountOfSections;
	
};

