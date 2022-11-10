#pragma once

#include<iostream>
#include<string>

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

	string _getElementInfo(ListElement<ElemType>* elem);
public:
	LinkedList();
	~LinkedList();

	// Додати в кінець черги
	bool Add(ListElement<ElemType>* newElement);
	// Вставити елемент в позицію курсора
	bool Insert(ListElement<ElemType>* newElement);
	ListElement<ElemType>** GoPreviousElement();
	ListElement<ElemType>** GoNextElement();
	inline ListElement<ElemType>** GoHead()
	{
		Cursor = Head;
		return &Cursor;
	}
	void RemoveCurrentElement();
	void RemoveLastElement();

	string GetCurrentElementInfo();
};

template<typename ElemType>
class LinkedListOutput
{
private:
	LinkedList<ElemType> list;
public:
	LinkedListOutput(LinkedList<ElemType>& list);
	~LinkedListOutput();
	
	string ShowAllElements();

};