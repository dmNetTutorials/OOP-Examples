#include"Main.h"

int main()
{
	setlocale(LC_ALL, "");

	Document doc = Document();
	// або
	Document* docPointer = new Document();

	doc.GetAuthor();
	// або
	docPointer->GetAuthor();
}

// Користувач системи
struct User
{
	// Змінні (поля) описують користувача
	const char* FirstName = "Дмитро";
	const char* SecondName = "Сулима";

};

struct User
{
	// Ел. пошта користувача
	char* Email;
	// Приховані відомості про користувача
	struct UserMetaData {
		// Шлях до особистого каталогу
		char* PersonalFolderPath;
		// Ідентифікатор користувача
		char* UserID;
	};
};

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
	// Загальнодоступна частина (інтерфейс)

	// Дізнатись хто автор документа
	char* GetAuthor();
	// Дізнатись дату створення документа
	unsigned long int GetCreationDate();
};