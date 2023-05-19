#include"MinistryOrder.h"

#ifndef MINISTRYORDER_H 
#define MINISTRYORDER_H 

/*
* Реалізація конструктора
*/
MyDocuments::MinistryOrder::MinistryOrder(std::string ministryName)
{
	/*
	* Зберегти назву міністерства в документі
	*/
	this->_ministryName = ministryName;
}
/*
	* Реалізація метода "відправки" наказу в конкретний
	* структурний підрозділ
	*/
bool MyDocuments::MinistryOrder::SendTo(std::string recieverName)
{
	/*
	* Зберегти відомості про останнього адресата-отримувача
	*/
	_lastRecieverName = recieverName;

	std::cout << "Order from:\t" 
			  << this->_ministryName
			  << std::endl
			  << "Successfully sent to:\t" 
			  << this->_lastRecieverName 
			  << std::endl;

	// Наказ вважається успішно надісланим
	return true;
}

#endif 
