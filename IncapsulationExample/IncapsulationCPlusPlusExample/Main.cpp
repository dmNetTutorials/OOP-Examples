/*
* Підключити єдиний заголовочний файл з усіма
* необхідними підключеними іншими заголовочними
* файлами та бібліотеками
*/
#include"Main.h"

/*
* Головна функція, з якої починається
* виконання програми
*/
int main(int argumentsCount,
		 char* argumentsValues[],
		 char* environmentVariables[])
{

	std::setlocale(LC_ALL, "UTF-8");

	/*
	*
	* Приклади використання типів даних користувача
	*
	*/

	/*
	* Не можна створювати екземпляри (instance)
	* інтерфейсів та абстрактних класи. оскільки вони
	* лише задають загальний опис (без реалізації)
	*
	* IDocument* doc = new IDocument(); - Неправильно
	* OrderBase* orders = new OrderBase(); - Неправильно
	*
	*/

	string from = "", to = "";

	cout << "Enter ministry name:" << endl;
	getline(cin, from);
	cout << "Enter reciever department name:" << endl;
	getline(cin, to);

	// Приклад створення конкретного екземпляру наказу з міністерства
	auto order = new MinistryOrder(from);

	cout << endl;
	// надіслати наказ 
	order->SendTo(to);

	cin.get();
}