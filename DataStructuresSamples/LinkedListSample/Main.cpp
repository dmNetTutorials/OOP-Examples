#include"Main.h"

template<typename T>
LinkedList<T>::LinkedList()
{
	Head = nullptr;
	Tail = Head;
	Cursor = Tail;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	delete Head;
	delete Tail;
	delete Cursor;
}

template<typename T> 
LinkedListOutput<T>::LinkedListOutput(LinkedList<T>& list)
{
	this->list = list;
}
template<typename T> 
LinkedListOutput<T>::~LinkedListOutput()
{
	this->list.~LinkedList();
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
		Cursor->Previous->Next = newElem;

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
// 1 <->   <-> 3
//		 ^	  ^  - Tail
//		 |
//	   Cursor
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

template<typename T>
ListElement<T>** LinkedList<T>::GoPreviousElement()
{
	Cursor = Cursor->Previous;

	return &Cursor;
}

template<typename T>
ListElement<T>** LinkedList<T>::GoNextElement()
{
	Cursor = Cursor->Next;

	return &Cursor;
}

template<typename T>
string LinkedList<T>::_getElementInfo(ListElement<T>* elem)
{
	const char* delimiter = "\n--------------------\n";
	string info = delimiter;
	if (elem != nullptr)
	{
		info.append("Значення поточного елемента:\t" + to_string(elem->Value));
		if (elem->Previous != nullptr)
		{
			info.append("\nЗначення попереднього елемента:\t" + to_string(elem->Previous->Value));
		}
		if (elem->Next != nullptr)
		{
			info.append("\nЗначення наступного елемента:\t" + to_string(elem->Next->Value));
		}
		info.append(delimiter);
	}

	return info;
}

template<typename T>
string LinkedList<T>::GetCurrentElementInfo()
{
	return this->_getElementInfo(Cursor);
}

template<typename T>
string LinkedListOutput<T>::ShowAllElements()
{

	auto currentElem = *list.GoHead();

	string result;

	while (currentElem != nullptr)
	{
		result.append(list.GetCurrentElementInfo());

		currentElem = *list.GoNextElement();
	
	}

	return result;

}

int main()
{

	setlocale(LC_ALL, "");

	auto myList = new LinkedList<double>();

	auto elem1 = new ListElement<double>();

	elem1->Value = 1.0;

	auto elem2 = new ListElement<double>();

	elem2->Value = 2.0;

	auto elem3 = new ListElement<double>();

	elem3->Value = 3.0;

	myList->Add(elem1);
	myList->Add(elem3);

	myList->Insert(elem2);

	auto output = new LinkedListOutput<double>(*myList);

	cout << output->ShowAllElements().c_str();

}