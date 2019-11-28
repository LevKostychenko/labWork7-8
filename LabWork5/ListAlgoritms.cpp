#pragma once
#include "pch.h"
#include "List.cpp"

template<typename T>
class ListAlgoritms
{
public:
	static void Sort(typename List<T>::iterator& it, List<T> list);
};

template<typename T>
void ListAlgoritms<T>::Sort(typename List<T>::iterator& it, List<T> list)
{
	while (it != list.end())
	{

	}
}
