#pragma once
#include "pch.h"
#include <iostream>
#include "List.cpp"
#include "ActionIdEnum.h"
#include "ListAlgoritms.cpp"

template<typename T>
class ListInterface
{
public:
	void ChouseAction();
};


template<typename T>
void ListInterface<T>::ChouseAction()
{
	List<T> lst;
	int actionId;
	int index;
	T inputData;
	bool isInputContine = true;

	while (isInputContine)
	{
		std::cout << "\nChouse action: \n";
		std::cout << "-1. Push back. \n";
		std::cout << "-2. Push front. \n";
		std::cout << "-3. Insert into index. \n";
		std::cout << "-4. Remove by index. \n";
		std::cout << "-5. Get count of elements. \n";
		std::cout << "-6. Clear the list. \n";
		std::cout << "-7. Delete from begin. \n";
		std::cout << "-8. Print all elements. \n";
		std::cout << "-9. Sort the list by name. \n";

		std::istream &in = std::cin;
		InputValidator::IsNumberInputCorrect(in, 1, 9, actionId);

		switch (actionId)
		{
		case ActionId::PUSHBACK:
		{
			std::cout << "Enter data: ";
			std::cin >> inputData;
			lst.PushBack(inputData);
			break;
		}
		case ActionId::PUSHFRONT:
		{
			std::cout << "Enter data: ";
			std::cin >> inputData;
			lst.PushFront(inputData);
			break;
		}
		case ActionId::INSERT:
		{
			std::cout << "Enter data: ";
			std::cin >> inputData;
			std::cout << "Enter index: ";
			std::cin >> index;
			lst.InsertAt(index, inputData);
			break;
		}
		case ActionId::REMOVE:
		{
			std::cout << "Enter index of intem to remove: ";
			std::cin >> index;
			lst.RemoveAt(index);
			break;
		}
		case ActionId::GETSIZE:
		{
			std::cout << lst.GetSize();
			break;
		}
		case ActionId::CLEAR:
		{
			lst.Clear();
			break;
		}
		case ActionId::POPFRONT:
		{
			lst.PopFront();
			break;
		}
		case ActionId::PRINT:
		{
			lst.Print();
			break;
		}
		case ActionId::SORT:
		{
			typename List<T>::iterator it = lst.begin();
			ListAlgoritms<T>::Sort(it, lst);
			break;
		}
		default:
			isInputContine = false;
			break;
		}
	}
}
