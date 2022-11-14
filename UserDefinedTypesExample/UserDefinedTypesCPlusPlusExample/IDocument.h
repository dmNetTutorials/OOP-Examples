#pragma once

/*
	Перелік типів документів, що
	підтримуються в програмі
*/
enum DocumentType
{
	Statement, // Заява, має значення 0
	Report,	   // Звіт, має значення 1
	Order,     // Наказ, має значення 2
	Unknown,   // Невідомий тип документа, має значення 3
};

/*
	Статус документа.
	В конкретний момент часу,
	в документа може бути тільки
	один статус!

	Для економії пам'яті можна
	використати бітові поля (bit fields),
	для зберігання значення кожного поля
	можна використати 1 біт.
	Але все об'єднання буде займати 1 байт = 8 біт,
	тобто мінімальний об'єм пам'яті.

*/
union DocumentStatus
{
	bool Active : 1;   // Діючий документ
	bool Archived : 1; // Архівний документ
	bool Unknown : 1;  // Невизначений 
};

/*
	Інтерфейс, який описує ТІЛЬКИ
	ЗАГАЛЬНІ функціональні
	можливості документа, тому він
	не може мати реалізації.

	Через відсутність реалізації можна
	увесь код розмістити в
	заголовочному файлі (.h)

*/
class IDocument
{
	/*
		Інтерфейс повинен складатись
		ТІЛЬКИ з відкритих "чисто віртуальних"
		методів (функцій)
	*/
public:
	// Отримати ПІБ автора документа
	virtual const char* GetAuthorFullName() const = 0;
	// Отримати час та дату останніх змін документа
	virtual unsigned long GetLastModifiedTimeStamp() const = 0;
	// Отримати тип документа (заява, звіт і т.д.)
	virtual DocumentType GetType() const = 0;
	// Задати тип документа

};

class DocumentBase : IDocument
{
	/*
		Абстрактний клас, повинен мати
		який має хоча б один "чисто віртуальний"
		метод (функцію)
	*/
protected:
	/*
		В абстрактних класах дозволяється 
		створювати поля та властивості
	*/
	// Статус документа, є властивістю
	DocumentStatus Status;
public:
	// Отримати ПІБ автора документа
	virtual const char* GetAuthorFullName() const = 0;
	// Отримати час та дату останніх змін документа
	virtual unsigned long GetLastModifiedTimeStamp() const = 0;
	// Отримати тип документа (заява, звіт і т.д.)
	virtual DocumentType GetType() const = 0;
	// Дізнатись поточний статус документа
	DocumentStatus GetStatus()
	{
		return this->Status;
	}
	// Змінити статус документа
	void SetStatus(DocumentStatus newStatus)
	{
		this->Status = newStatus;
	}

};

/*
		Віртуальний клас, повинен мати
		який має хоча б один віртуальний
		метод (функцію)
*/
class Document : DocumentBase
{
private:
public:
	// Конструктор за замовчуванням
	Document()
	{
		// Коли створюється документ,
		// він стає діючим
		Status.Active = true;
	}
	// Деструктор (може бути тільки один)
	~Document()
	{
		// Коли документ знищується,
		// то його статус стає невідомим 
		Status.Unknown = true;
	}
};


/*
	Конкретний клас, повинен реалізовувати
	всі віртуальні та "чисто віртуальні"
	методи, або власні методи
*/
class Statement : Document
{
public:
	// Максимальна к-сть днів для опрацювання 
	// ВСІХ видів заяв.
	static short MaximumProcessingDaysDeadline;
};

// Відомості про автора документа
struct AuthorMetaData
{
	char* FirstName;	// Ім'я
	char* SecondName;	// Прізвище

	// Сформувати ПІБ автора
	char* GetFullName() const;
};