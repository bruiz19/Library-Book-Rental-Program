//Brandon Ruiz
//Section 02

#include "book.h"

Book::Book(int BI, string TI, string AU, string CAT) {
    title=TI;
    author=AU;
    category=CAT;
    bookID=BI;
}

string Book::getTitle() {
    return title;
}

string Book::getAuthor() {
    return author;
}

string Book::getCategory() {
    return category;
}

int Book::getId() {
    return bookID;
}
void Book::setPersonPtr(Person * ptr) {
    personPtr=ptr;
}

Person * Book::getPersonPtr() {
    return personPtr;
}
