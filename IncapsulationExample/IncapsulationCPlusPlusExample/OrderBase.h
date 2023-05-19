#pragma once

#include<iostream>

/*
* 
* Один й той самий простір імен можна 
* використовувати в різних файлах
* 
*/
namespace MyDocuments
{
	/*
	* 
	* Абстрактний клас, призначений для опису 
	* сімейства певних об'єктів.
	* 
	* В даному класі зберігаються 
	* атрибути та методи характерні ТІЛЬКИ для 
	* документів типу "Наказ" (Order)
	* 
	* Такі класи потрібні для побудови ієрархій класів.
	* 
	* Абстрактний клас ОБОВ'ЯЗКОВО включає в себе 
	* мінімум один "чисто віртуальний" метод!
	* 
	*/
	class OrderBase
	{
	private:
		/*
		* Секція коду для використання
		* тільки всередині поточного класу
		*/

		// Назва структурного підрозділу отримувача наказу
		std::string _recieverDepartment;
		// Назва структурного підрозділу відправника наказу
		std::string _senderDepartment;
	public:
		/*
		* 
		* "чисто віртуальний" метод, який 
		* ОБОВ'ЯЗКОВО потрібно буде 
		* реалізувати в дочірніх класах
		* 
		*/
		virtual bool Process() = 0;

		/*
		* Віртуальні методи необхідні для того,
		* щоб за необхідності, можна було в дочірніх класах 
		* замінити реалізацію за-замовчуванням 
		*/
		// Дізнатись назву структурного підрозділу отримувача
		virtual std::string GetRecieverDepartment();
		/* 
		* Дізнатись назву структурного підрозділу,
		* з якого було надіслано наказ
		*/
		virtual std::string GetSenderDepartment();
	};

}