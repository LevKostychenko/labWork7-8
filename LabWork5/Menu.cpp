#include "pch.h"
#include "Menu.h"
#include <iostream>
#include "TypeIdEnum.h"
#include "List.cpp"
#include "ListInterface.cpp"
#include "Coach.h"
#include "TrolleyBus.h"
#include "DumpTrack.h"
#include "GarbageTruck.h"
#include "Exception.h"

void Menu::ShowStartMenu()
{
	std::cout << "Choose container type: \n";
	std::cout << "-1. Integer. \n";
	std::cout << "-2. Char. \n";
	std::cout << "-3. Garbage truck. \n";
	std::cout << "-4. Dump truck. \n";
	std::cout << "-5. Coach. \n";
	std::cout << "-6. Trolley bus. \n";

	GetUserType();
}

void Menu::GetUserType()
{
	int typeId = 0;
	std::istream &in = std::cin;
	InputValidator::IsNumberInputCorrect(in, 1, 6, typeId);

	switch (typeId)
	{
	case TypeId::INTEGER:
	{
		ListInterface<int> intInterface;
		intInterface.ChouseAction();
		break;
	}
	case TypeId::CHAR:
	{
		ListInterface<char> intInterface;
		intInterface.ChouseAction();
		break;
	}
	case TypeId::COACH:
	{
		ListInterface<Coach> intInterface;
		intInterface.ChouseAction();
		break;
	}
	case TypeId::DUMP_TRUCK:
	{
		ListInterface<DumpTrack> intInterface;
		intInterface.ChouseAction();
		break;
	}
	case TypeId::GARBAGE_TRUCK:
	{
		ListInterface<GarbageTruck> intInterface;
		intInterface.ChouseAction();
		break;
	}
	case TypeId::TROLLEY_BUS:
	{
		ListInterface<TrolleyBus> intInterface;
		intInterface.ChouseAction();
		break;
	}
	default:
		break;
	}
}
