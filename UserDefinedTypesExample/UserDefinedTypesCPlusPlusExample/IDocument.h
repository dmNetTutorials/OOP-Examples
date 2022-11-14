#pragma once

#include<string>

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
	// Загальна кількість документів 
	// будь-яких типів в системі,
	// дане поле спільне для 
	// всіх документів
	static int TotalDocumentsAmount;
	// Оновити загальну к-сть документів
	// в системі
	static void ChangeTotalDocumentsAmount(int newAmount);
	// Отримати ПІБ автора документа
	virtual const char* GetAuthorFullName() const = 0;
	// Отримати тип документа (заява, звіт і т.д.)
	virtual DocumentType GetType() const = 0;
	// Дізнатись поточний статус документа
	DocumentStatus GetStatus();
	// Змінити статус документа
	void SetStatus(DocumentStatus newStatus);
};

/*
		Віртуальний клас, повинен мати
		який має хоча б один віртуальний
		метод (функцію)
*/
class Document : DocumentBase
{
	// зазвичай, назви закритих 
	// та захищених елементів починаються 
	// з символу _ (нижня риска)
private:
	// Унікальні властивості для
	// даного виду документа

	// Реєстраційний номер документа
	char* _registerID;
protected:
	// Характерні властивості для 
	// подібних документів

	// Автор документа
	char* _author;
	// Дата створення документа
	unsigned long int _creationDate;
public:
	// Отримати всю інформацію про документ,
	// реалізація методу може бути 
	// перевизначена (override) в дочірніх класах
	virtual std::string GetFullInfo();

	virtual const char* GetAuthorFullName() const final override;
	virtual DocumentType GetType() const final override;
	virtual unsigned long GetLastModifiedTimeStamp() const final override;

	// Конструктор за замовчуванням
	Document();
	// Деструктор (може бути тільки один)
	~Document();
	// Дата останньої зміни документа,
	// може бути змінена поза межами 
	// поточної програми
	volatile time_t LastModifiedDateTimeStamp;

	// Чи архівний документ?
	// Навіть затверджений документ
	// можна зробити архівним
	mutable bool IsArchived;

	// Чи затверджено документ?
	bool IsCompleted;

	// Статус документа
	DocumentStatus Status;

	// Дізнатись дату створення документа
	unsigned long int GetCreationDate();
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
