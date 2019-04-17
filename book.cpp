//Brandon Ruiz
//Section 02

#include "book.h"
#include <string>

using namespace std;

Book::Book(){
  bookID = -1;
  title = " ";
  author = " ";
  category = " ";
  checked = false;
}
Book::Book(int id, string t, string a, string c){
  bookID = id;
  title = t;
  author = a;
  category = c;
}
int Book::getBookID(){
  return bookID;
}
void Book::setBookID(int id){
  bookID = id;
}
string Book::getTitle(){
  return title;
}
void Book::setTitle(string t){
  title = t;
}
string Book::getAuthor(){
  return author;
}
void Book::setAuthor(string a){
  author = a;
}
string Book::getCategory(){
  return category;
}
void Book::setCategory(string c){
  category = c;
}
void Book::setChecked(bool c){
    checked = c;
}
bool Book::getChecked(){
    return checked;
}
void Book::setRenterID(int id){
  renterID = id;
}
int Book::getRenterID(){
  return renterID;
}
