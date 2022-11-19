#pragma once


// Відомості про автора документа
struct AuthorMetaData
{
	char* FirstName;	// Ім'я
	char* SecondName;	// Прізвище

	// Сформувати ПІБ автора
	char* GetFullName() const;
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

	// Ел. пошта користувача
	char* Email;
	// Приховані відомості про користувача
	struct UserMetaData {
		// Шлях до особистого каталогу
		char* PersonalFolderPath;
		// Ідентифікатор користувача
		char* UserID;
	};
public:
	// Дізнатись скільки було спроб авторизації
	inline short int GetCurrentTriesAmount() const
	{
		// ключове слово const в сигнатурі методу 
		// забороняє змінювати будь-які внутрішні дані
		// всередині класу User
		return _currentTriesAmount;
	}
};