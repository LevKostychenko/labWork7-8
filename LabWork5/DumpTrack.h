#pragma once
#include "FreightVehicle.h"

class DumpTrack : public FreightVehicle
{
public:
	DumpTrack(double fuelConsumption = 0, double maxCapacity = 0, const char* name = new char[10]{ "undefine" }, const char* transportedResources = new char[10]{ "undefine" });
	~DumpTrack();
	DumpTrack(const DumpTrack& dumpTrack);

public:
	void Move(double) override;
	char* GetTransportedResources();
	void SetTransportedResources(const char* resources);

	void SetHeader();
	void SetData(texttable::TextTable& t);
	DumpTrack& operator = (DumpTrack& obj);
	friend std::ostream & operator << (std::ostream &out, DumpTrack& vehicle);
	friend std::istream & operator >> (std::istream &in, DumpTrack& vehicle);

private:
	char* TransportedResources;
};

