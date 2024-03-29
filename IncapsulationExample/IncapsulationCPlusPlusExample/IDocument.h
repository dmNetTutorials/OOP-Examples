#pragma once

/*
*
* В заголовочних файлах можна
* підключати інші заголовочні файлі
*
*/
#include<string>

/*
	В заголовочному файлі (.h)
	дозволяється розміщувати декілька
	типів даних користувача, ТІЛЬКИ
	у випадку, якщо вони невеликі за обсягом
	та відносяться до однієї сутності

	Наприклад, типи даних користувача
	розміщені в даному файлі, тому що
	вони малі за розміром та відносяться
	до опису документів:
	1.) Перерахування DocumentType
	2.) Об'єднання DocumentStatus
	3.) Інтерфейс IDocument
*/


/*
* Простори імен потрібні для 
* усунення проблем "конфліктів імен", тобто
* коли використовуються типи даних 
* з різних джерел (наприклад, бібліотек)
* з однаковими назвами, наприклад, 
* тип даних Doc з бібліотеки Word та 
* тип даних Doc з власної бібліотеки
*/
namespace MyDocuments
{
/*
* Перерахування, використовуються для
* швидкого створення ЧИСЛОВИХ констант,
* що дозволяє уникати "магічних чисел" в коді
*
* Перелік типів документів, що
* підтримуються в програмі
*/
enum DocumentType
{
	Statement, // Заява, має значення 0, тобто Statement = 0
	Report,	   // Звіт, має значення 1,	 тобто Report = 1
	Order,     // Наказ, має значення 2, тобто Order = 2
	Unknown,   // Невідомий тип документа, має значення 3, тобто Unknown = 3
};

/*
*
* Структури даних об'єднань (union) та структури (struct)
* призначені для зберігання даних.
*
* Основна відмініість між структурою та об'єднанням
* полягає в тому, що в об'єднанні всі дані зберігаються
* за однією адресою в пам'яті, а в структурі під кожний
* атрибут використовуються різні ділянки пам'яті.
*
* Для економії пам'яті можна
* використати бітові поля (bit fields),
* які визначають діапазон можливих значень
*
* В структурах та об'єднаннях дозволяється використання
* методів, які є службовими (наприклад, як в
* структурі AuthorMetaData наведеній нижче)
*
* Статус документа.
* В конкретний момент часу,
* в документа може бути тільки
* один статус!
*
*/
union DocumentStatus
{
	bool Active : 1;   // Діючий документ
	bool Archived : 1; // Архівний документ
	bool Unknown : 1;  // Невизначений 
};

// Відомості про автора документа
struct AuthorMetaData
{
	std::string FirstName;	// Ім'я
	std::string SecondName;	// Прізвище

	// Службовий метод
	// Сформувати ПІБ автора 
	inline std::string GetFullName() const
	{
		/*
		* Ключове слово inline дозволяє 
		* писати реалізацію прямо в заголовочному файлі,
		* але це дозволяється лише для невеликих методів
		*/
		return FirstName + " " + SecondName;
	}
};

/*
	Інтерфейс, який описує ТІЛЬКИ
	ЗАГАЛЬНІ функціональні
	можливості документа, тому він
	не може мати реалізації, тобто він
	повинен складатись тільки
	з відкритих (public) методів (функцій)

	Назви інтерфейсів зазвичай починаються з 
	великої літери I (скор.від Interface)

	За допомогою інтерфейсів описуються абстрації,
	тобто сутності з найбільш суттєвими характеристиками,
	за допомогою яких можна відрізнити одну сутність від іншої

	Через відсутність реалізації можна
	увесь код інтерфейсу розмістити в
	заголовочному файлі (.h)

	Але в сучасних ООП мовах програмування, таких
	як C# дозволяється створювати відкриті
	властивості та методи

	В деяких мовах програмування, існують 
	альтернативні назви інтерфейсів:
	1.) C# - контракт (contract), інтерфейс;
	2.) Swift - протокол (protocol), інтерфейс.
*/
class IDocument
{
public:
	/*
	* Методи інтерфейсів обов'язково мають бути 
	* "чисто віртуальними" (pure virtual),
	* їх реалізація буде зазначена в дочірніх класах
	*/

	// Отримати ПІБ автора документа
	virtual const char* GetAuthorFullName() const = 0;
	// Отримати час та дату останніх змін документа
	virtual unsigned long GetLastModifiedTimeStamp() const = 0;
	/*
	* 
	* Можна використовувати одні типи даних всередині 
	* інших, наприклад перерахування DocumentType 
	* зазначене в якості результату 
	* виконання методу GetType()
	* 
	* Отримати тип документа (заява, звіт і т.д.)
	* 
	*/
	virtual DocumentType GetType() const = 0;
};

}