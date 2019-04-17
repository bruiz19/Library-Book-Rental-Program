//Brandon Ruiz
//Section 02

#ifndef BOOK_H
#define BOOK_H
#include <string>

using namespace std;

class Book{
  private:
    int bookID;
    string title;
    string author;
    string category;
    bool checked = false;
    int renterID = -1;
  public:
    Book();
    Book(int id, string t, string a, string c);
    int getBookID();
    void setBookID(int id);
    string getTitle();
    void setTitle(string t);
    string getAuthor();
    void setAuthor(string a);
    string getCategory();
    void setCategory(string c);
    void setChecked(bool c);
    bool getChecked();
    void setRenterID(int id);
    int getRenterID();
};
#endif
