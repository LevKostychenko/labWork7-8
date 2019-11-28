#pragma once

struct VechicleInfo
{
	char* _vechicleRegNumber{ new char[10] {"undefined"} };
	char* _vechicleCategory{ new char[10] {"undefined"} };
	char* _vechicleName{ new char[10] {"undefined"} };
	double _vechicleFuelLevel{ 0 };
	double _vechicleDistanceTreveled{ 0 };
	double _vehicleMaxSpeed{ 0 };
	double _fuelConsumption{ 0 };
};