#pragma once

#include<string>
#include<iostream>

namespace MyDocuments
{

	/*
	* 
	* Конкретний тип наказів:
	* "Наказ з міністерства"
	* 
	*/
	class MinistryOrder
	{
	private:
		std::string _ministryName;
		std::string _lastRecieverName;
	public:
		// Конструктор
		MinistryOrder(std::string ministryName);
		// Деструктор
		~MinistryOrder();

		/*
		* Метод "відправки" наказу в конкретний
		* структурний підрозділ
		*/
		bool SendTo(std::string recieverName);
	};

}