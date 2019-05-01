//Brandon Ruiz
//Section 02

//begin book.h
#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "person.h"

class Book
{
private:
    string   title;
    string   author;
    string   category;
    int      bookID;
    Person * personPtr = nullptr;

public:
    Book(int BI, string TI, string AU, string CAT);
    string   getTitle();
    string   getAuthor();
    string   getCategory();
    int      getId();
    void     setPersonPtr(Person * ptr);
    Person * getPersonPtr();
};
#endif // end book.h
