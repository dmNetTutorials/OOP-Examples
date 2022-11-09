#include"Main.h"

int main()
{
	setlocale(LC_ALL, "");

	Document doc = Document();
	// ���
	Document* docPointer = new Document();

	doc.GetAuthor();
	// ���
	docPointer->GetAuthor();
}

// ���������� �������
struct User
{
	// ���� (����) �������� �����������
	const char* FirstName = "������";
	const char* SecondName = "������";

};

struct User
{
	// ��. ����� �����������
	char* Email;
	// �������� ������� ��� �����������
	struct UserMetaData {
		// ���� �� ���������� ��������
		char* PersonalFolderPath;
		// ������������� �����������
		char* UserID;
	};
};

class Document
{
// ��������, ����� �������� 
// �� ��������� �������� ����������� 
// � ������� _ (����� �����)
private:
	// ������� ���������� ���
	// ������ ���� ���������

	// ������������ ����� ���������
	char* _registerID;
protected:
	// ��������� ���������� ��� 
	// ������� ���������

	// ����� ���������
	char* _author;
	// ���� ��������� ���������
	unsigned long int _creationDate;
public:
	// ���������������� ������� (���������)

	// ĳ������� ��� ����� ���������
	char* GetAuthor();
	// ĳ������� ���� ��������� ���������
	unsigned long int GetCreationDate();
};