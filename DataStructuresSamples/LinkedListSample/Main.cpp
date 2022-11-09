#include"Main.h"

template<typename T>
LinkedList<T>::LinkedList()
{
	Head = nullptr;
	Tail = Head;
	Cursor = Tail;
}

template<typename T>
bool LinkedList<T>::Add(ListElement<T>* newElem)
{
	try
	{
		// ������ �� �������
		if (Head == nullptr)
		{
			Head = newElem;
			Tail = Head;
			Cursor = Tail;
		}
		else
		{

			// ���������� � ������������ 
			// ������� �������� �� �����
			Tail->Next = newElem;

			// Tail = �������� �������
			newElem->Previous = Tail;

			// ����� ������� ��� ��������
			Tail = newElem;
			Cursor = Tail;
		}
	}
	catch (...)
	{
		return false;
	}

	return true;
}

template<typename T>
bool LinkedList<T>::Insert(ListElement<T>* newElem)
{
	try
	{
		// ��������� �� ��������� �������
		Cursor->Previous = newElem;

		// �������� ��������� �� �������, ��
		// ���� ����� ������
		newElem->Next = Cursor;

		// �������� ��������� �� �������, 
		// ��������� ����� ��������
		newElem->Previous = Cursor->Previous;

		// �������� ������� � ������
		Cursor = newElem;
	}
	catch (...)
	{
		return false;
	}

	return true;
}

// Head
// v
// 1 2 3
//	 ^ ^  - Tail
//   |
// Cursor
template<typename T>
void LinkedList<T>::RemoveCurrentElement()
{
	// ������� �� ��������� �������
	Cursor = Cursor->Previous;
	// �������� �������
	Cursor->Next = nullptr;
}

template<typename T>
void LinkedList<T>::RemoveLastElement()
{
	// ������� �� ��������� �������
	Tail = Tail->Previous;
	// �������� �������
	Tail->Next = nullptr;
}

int main()
{

	setlocale(LC_ALL, "");



}