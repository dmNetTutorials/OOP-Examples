#pragma once

#include<iostream>

using namespace std;

template<typename Elem> struct ListElement
{
	Elem Value;
	ListElement* Previous;
	ListElement* Next;
};

template<typename ElemType> class LinkedList
{
private:
	// Початок "голова" списку
	ListElement<ElemType>* Head;
	// Кіцень "хвіст" списку
	ListElement<ElemType>* Tail;

	// Курсор, для навігації по списку
	ListElement<ElemType>* Cursor;
public:
	LinkedList();

	// Додати в кінець черги
	bool Add(ListElement* newElement);
	// Вставити елемент в позицію курсора
	bool Insert(ListElement* newElement);
	ListElement** GoPreviousElement();
	ListElement** GoNextElement();
	void RemoveCurrentElement();
	void RemoveLastElement();

	string GetElementInfo();
	string ShowAllElements();

};