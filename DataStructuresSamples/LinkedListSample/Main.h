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
	// ������� "������" ������
	ListElement<ElemType>* Head;
	// ʳ���� "����" ������
	ListElement<ElemType>* Tail;

	// ������, ��� �������� �� ������
	ListElement<ElemType>* Cursor;
public:
	LinkedList();

	// ������ � ����� �����
	bool Add(ListElement* newElement);
	// �������� ������� � ������� �������
	bool Insert(ListElement* newElement);
	ListElement** GoPreviousElement();
	ListElement** GoNextElement();
	void RemoveCurrentElement();
	void RemoveLastElement();

	string GetElementInfo();
	string ShowAllElements();

};