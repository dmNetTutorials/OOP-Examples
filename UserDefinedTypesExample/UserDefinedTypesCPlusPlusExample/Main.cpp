#include"Main.h"

void header(const char* text)
{

	cout << "Використання " << text << " змiнних" <<
		" в якостi полiв типу користувача" << endl;
}

void simpleFieldSample()
{
	header("звичайних");

	// Створення екземпляру (instance) 
	// типу даних користувача
	UserStorageInfo storageInfo = UserStorageInfo();
	// Задати к-сть вільної пам'яті
	// в гігабайтах
	storageInfo.FreeSpace = 5;
	// Вивести к-сть вільної пам'яті
	cout << storageInfo.FreeSpace << endl;
}

void mutableFieldSample()
{
	header("mutable");

	// Створення незмінного 
	// (затвердженного) документа
	const Document doc = Document();
	// Не можна змінювати незмінні 
	// (const) об'єкти
	// doc.IsCompleted = false;
	// mutable-поля можна змінювати завжди
	doc.IsArchived = true;

}

void bitFieldsSample()
{
	Document doc = Document();
	// Документ є діючим, використання бітового поля
	doc.Status.Active = true;
	cout << "Об'єм пам'ятi в байтах зайнятий " 
		 << "об'єднанням з бiтовими полями:\t"
		 << sizeof(doc.Status) << endl;
}

void unionSample()
{
	Document doc = Document();
	// Документ є діючим
	doc.Status.Active = true;
	cout << "Об'єм пам'ятi в байтах зайнятий об'єднанням:\t"
		<< sizeof(doc.Status) << endl;

	//cout << "Адреса першого статусу (Активний):\t" 
	//	 << &doc.Status.Active << endl;
	//cout << "Адреса останнього статусу (Невiдомий):\t" 
	//	 << &doc.Status.Unknown << endl;
}
void structSample()
{
	AuthorMetaData author = AuthorMetaData();
	// створення порожнього рядка в 7 символів
	// 7-й символ - символ завершення рядка '\0'
	author.FirstName = new char[7] {};
	// запис тексту в рядок
	strcpy(author.FirstName, "Дмитро");
	author.SecondName = new char[7] {};
	strcpy(author.FirstName, "Сулима");
	cout << "Об'єм пам'ятi в байтах зайнятий структурою:\t"
		<< sizeof(author) << endl;

	cout << "Адреса першого поля (FirstName):\t"
		<< &author.FirstName << endl;
	cout << "Адреса другого поля (SecondName):\t"
		<< &author.SecondName << endl;
}

int main()
{
	setlocale(LC_ALL, "ukr.utf8");

	simpleFieldSample();
	mutableFieldSample();
	unionSample();
	structSample();
	bitFieldsSample();
}