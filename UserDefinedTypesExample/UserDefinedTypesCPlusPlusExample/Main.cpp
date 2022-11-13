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

int main()
{
	setlocale(LC_ALL, "");

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

