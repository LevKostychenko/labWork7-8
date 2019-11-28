#pragma once
#include "FreightVehicle.h"

class GarbageTruck : public FreightVehicle
{
public:
	GarbageTruck(double fuelConsumption = 0, double maxCapacity = 0, const char* name = new char[10]{ "undefine" }, const char* transportedGarbage = new char[10]{ "undefine" });
	~GarbageTruck();

public:
	void Move(double) override;
	char* GetTransportedGarbage();
	void SetTransportedGarbage(const char* garbage);
	GarbageTruck(const GarbageTruck& dumpTrack);

	void SetHeader();
	void SetData(texttable::TextTable& t);
	GarbageTruck& operator = (GarbageTruck& obj);
	friend std::ostream & operator << (std::ostream &out, GarbageTruck& vehicle);
	friend std::istream & operator >> (std::istream &in, GarbageTruck& vehicle);

private:
	char* TransportedGarbage;
};

