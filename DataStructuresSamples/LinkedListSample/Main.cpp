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
		// Список ще порожній
		if (Head == nullptr)
		{
			Head = newElem;
			Tail = Head;
			Cursor = Tail;
		}
		else
		{

			// Збереження в попередньому 
			// елементі вказівник на новий
			Tail->Next = newElem;

			// Tail = поточний елемент
			newElem->Previous = Tail;

			// Новий елемент стає поточним
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
		// Посилання на попередній елемент
		Cursor->Previous = newElem;

		// Зберегти посилання на елемент, на
		// який вказує курсор
		newElem->Next = Cursor;

		// Зберегти посилання на елемент, 
		// попередній перед курсором
		newElem->Previous = Cursor->Previous;

		// Вставити елемент в список
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
	// Перейти на попередній елемент
	Cursor = Cursor->Previous;
	// Видалити елемент
	Cursor->Next = nullptr;
}

template<typename T>
void LinkedList<T>::RemoveLastElement()
{
	// Перейти на попередній елемент
	Tail = Tail->Previous;
	// Видалити елемент
	Tail->Next = nullptr;
}

int main()
{

	setlocale(LC_ALL, "");



}