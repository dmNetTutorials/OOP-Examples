/*
* Підключити необхідний заголовочний файл
* який необхідно реалізувати (описати логіку роботи)
*/
#include"OrderBase.h"

/*
* "Охорона включень" (include guard), 
* ОБОВ'ЯЗКОВО мають бути в усіх файлах реалізації (.cpp) 
* для усунення проблем з конфліктами імен,
* коли код з цього файлу буде використовуватись в декількох
* інших файлах.
* 
* "Охорона включень" це макроси компіляції, які ГАРАНТУЮТЬ,
* що файл реалізації (.cpp) буде оброблений компілятором
* ТІЛЬКИ ОДИН раз.
* 
* Назва макросу зазвичай має вигляд:
* HEADERFILENAME_H
* тобто назва заголовочного файлу великими літерами,
* в якому зберігається опис елементів 
* (структур даних, методів і т.д.) які потрібно реалізувати
* 
* Наприклад:
* ORDERBASE_H - це назва заголовочного файлу OrderBase.h
* 
* ГОЛОВНЕ НЕ ЗАБУТИ В КІНЦІ ФАЙЛУ РЕАЛІЗАЦІЇ 
* "ЗАКРИТИ" ДИРЕКТИВУ #ifndef
* ДИРЕКТИВОЮ #endif , інакше проект не зкомпілюється!
*/
#ifndef ORDERBASE_H
#define ORDERBASE_H

/*
* Для того, щоб вказати що конкретно реалізовується,
* необхідно вказати повний "шлях" до метода або атрибути.
* 
* "Шлях" формується за допомогою 
* оператора розширеного доступу :: (дві подвійні крапки),
* де зліва вказується об'єкт, який містить в собі елемент,
* до якого відбувається доступ.
* 
* Наприклад:
* MyDocuments::OrderBase,
* де простір імен MyDocuments містить в собі клас OrderBase
*/
std::string MyDocuments::OrderBase::GetRecieverDepartment()
{
	/*
	* 
	* Ключове слово this, є вказівником на поточний клас,
	* тобто для доступу до елементів всередині класу потрібно 
	* використовувати this->.
	* 
	* В даному випадку відбувається доступ до закритої частини
	* класу, за допомогою вказівника на поточний клас.
	* 
	* Вказівник this доступний ЛИШЕ всередині класу, та 
	* за його допомогою можна отримати доступ до будь-якого 
	* елемента класу
	*/
	return this->_recieverDepartment;
}

/*
* 
* Описати логіку роботи (реалізація) метода отримання
* відомостей про структурний відділ, 
* з якого було надіслано наказ
*/
std::string MyDocuments::OrderBase::GetSenderDepartment()
{
	return this->_recieverDepartment;
}

// НЕ ЗАБУТИ "ЗАКРИТИ" ДИРЕКТИВУ #ifndef
#endif