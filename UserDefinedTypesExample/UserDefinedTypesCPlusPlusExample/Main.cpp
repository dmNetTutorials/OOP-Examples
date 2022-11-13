#include"Main.h"

class Document
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

	// Загальнодоступна частина (інтерфейс)
	// Дізнатись хто автор документа
	char* GetAuthor()
	{
		return new char;
	}
	// Дізнатись дату створення документа
	unsigned long int GetCreationDate();
};

// Відомості про особисте 
// сховище користувача
class UserStorageInfo
{
private:
	// Шлях до особистого каталогу
	// користувача. Доступ до цієї
	// змінної можливий тільки всередині
	// типу UserStorageInfo
	char* _personalFolderPath;
public:
	// Скільки залишилось вільного
	// місця в гігабайтах, доступ
	// до цієї змінної поза межами 
	// UserStorageInfo
	short int FreeSpace;
};

// Користувач системи
class User
{
	// Максимальна кількість спроб 
	// для вводу правильних даних
	const short int _maximumTriesAmount = 3;
	// Поточна кількість спроб
	short int _currentTriesAmount;
public:
	// Дізнатись скільки було спроб авторизації
	short int GetCurrentTriesAmount() const
	{
		// ключове слово const в сигнатурі методу 
		// забороняє змінювати будь-які внутрішні дані
		// всередині класу User
		return _currentTriesAmount;
	}
};

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

	//simpleFieldSample();
	//mutableFieldSample();
	//unionSample();
	//structSample();
	bitFieldsSample();
	// конкретний документ
	Document doc = Document();
	// або
	Document* docPointer = new Document();

	doc.GetAuthor();
	// або
	docPointer->GetAuthor();
	User usr = User();
	auto amounts = usr.GetCurrentTriesAmount();

	delete docPointer;
}

//
//struct User
//{
//	// Ел. пошта користувача
//	char* Email;
//	// Приховані відомості про користувача
//	struct UserMetaData {
//		// Шлях до особистого каталогу
//		char* PersonalFolderPath;
//		// Ідентифікатор користувача
//		char* UserID;
//	};
//};