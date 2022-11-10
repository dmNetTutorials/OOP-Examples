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
	// ������� "������" ������
	ListElement<ElemType>* Head;
	// ʳ���� "����" ������
	ListElement<ElemType>* Tail;
	// ������, ��� �������� �� ������
	ListElement<ElemType>* Cursor;

	string _getElementInfo(ListElement<ElemType>* elem);
public:
	LinkedList();
	~LinkedList();

	// ������ � ����� �����
	bool Add(ListElement<ElemType>* newElement);
	// �������� ������� � ������� �������
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