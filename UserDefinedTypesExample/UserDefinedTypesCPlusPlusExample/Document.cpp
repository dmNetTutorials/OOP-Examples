#include"IDocument.h"

#ifndef _IDOCUMENT_H
#define _IDOCUMENT_H

int DocumentBase::TotalDocumentsAmount;

void DocumentBase::ChangeTotalDocumentsAmount(int newAmount)
{
	// Доступ до статичних даних рівня класу
	// відбувається через вказання 
	// назви типу даних користувача, та оператору
	// доступу ::
	DocumentBase::TotalDocumentsAmount = newAmount;
}

DocumentStatus DocumentBase::GetStatus()
{
	return this->Status;
}

void DocumentBase::SetStatus(DocumentStatus newStatus)
{
	this->Status = newStatus;
}

std::string Document::GetFullInfo()
{
	std::string info = GetAuthorFullName() +
					   std::to_string(GetType());
	return info;
}

Document::Document()
{
	// Коли створюється документ,
	// він стає діючим
	Status.Active = true;
}
Document::~Document()
{
	// Коли документ знищується,
	// то його статус стає невідомим 
	Status.Unknown = true;
}
unsigned long int Document::GetCreationDate()
{
	return this->_creationDate;
}

const char* Document::GetAuthorFullName() const
{
	return this->_author;
}

DocumentType Document::GetType() const
{
	return Unknown;
}
unsigned long Document::GetLastModifiedTimeStamp() const
{
	return 0;
}

#endif