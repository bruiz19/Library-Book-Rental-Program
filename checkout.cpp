//Brandon Ruiz
//Section 02

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "book.cpp"
#include "person.cpp"

using namespace std;

void printmenu() {
    cout << "1. Book checkout" << endl;
    cout << "2. Book return" << endl;
    cout << "3. View all available books" << endl;
    cout << "4. View all outstanding rentals" << endl;
    cout << "5. View outstanding rentals for a cardholder" << endl;
    cout << "6. Open new library card" << endl;
    cout << "7. Close library card" << endl;
    cout << "8. Close program" << endl;
  }

int findPerson(int id, vector<Person *> perVec){
  int found = -1;
  for(int i = 0; i < perVec.size(); ++i){
      if(perVec.at(i)->getCardID() == id){
         found = i;
      }
  }
  return found;
}

int findBook(int id, vector<Book *> bookVec){
  int found = -1;
  for(int i = 0; i < bookVec.size(); ++i){
      if(bookVec.at(i)->getBookID() == id){
         found = i;
      }
  }
  return found;
}

vector<Book *> readBookFile(vector<Book *> bookVec, string fileName){
  fstream myFile;
  myFile.open(fileName);
  int bookID;
  string author;
  string category;
  string title;
  string space;
  while(myFile){
    myFile >> bookID;
    getline(myFile, space);
    getline(myFile, title);
    getline(myFile, author);
    getline(myFile, category);
    bookVec.push_back(new Book(bookID, title, author, category));
  }
  bookVec.pop_back();
  myFile.close();
  return bookVec;
}

vector<Person *> readPersonFile(vector<Person *> perVec, string fileName){
  fstream myFile;
  myFile.open(fileName);
  string fName;
  string lName;
  int cardID;
  bool active;
  string space;
  while(myFile){
    myFile >> cardID;
    myFile >> active;
    myFile >> fName >> lName;
    getline(myFile,space);
    perVec.push_back(new Person(cardID, active, fName, lName));
  }
  perVec.pop_back();
  myFile.close();
  return perVec;
}

void bookCheckout(vector<Book *> bookVec, vector<Person *> perVec, int id){
    int bookID;
    int person = findPerson(id,perVec);
    int book = -1;
    if(person  == -1){
        cout << "Card ID not found" << endl;
        return;
    }else if(perVec.at(person)->getActive() == false){
      cout << "Card ID is inactive" << endl;
      return;
    }
    cout << "Cardholder: " << perVec.at(person)->getFirstName() << " " << perVec.at(person)->getLastName() << endl;
    cout << "Please enter the book ID: ";
    cin >> bookID;
    book = findBook(bookID, bookVec);
    if(book == -1){
        cout << "Book ID not found" << endl;
        return;
    }
    cout << "Title: " << bookVec.at(book)->getTitle() << endl;
    if(bookVec.at(book)->getChecked() == false){
        bookVec.at(book)->setChecked(true);
        bookVec.at(book)->setRenterID(perVec.at(person)->getCardID());
        cout << "Rental Completed" << endl;
    }else{
        cout << "Book already checked out" << endl;
    }
}

void bookReturn(vector<Book *> bookVec, int bookID){
    int book = findBook(bookID, bookVec);
    if(book == -1){
        cout << "Book ID not found" << endl;
        return;
    }
    bookVec.at(book)->setChecked(false);
    bookVec.at(book)->setRenterID(-1);
    cout << "Title: " << bookVec.at(book)->getTitle() << endl;
    cout << "Return Completed" << endl;

}

void availableBooks(vector<Book *> bookVec){
    int count = 0;
    for(int i = 0; i < bookVec.size(); ++i){
        if(bookVec.at(i)->getChecked() == false){
            cout << "Book ID: " << bookVec.at(i)->getBookID() << endl;
            cout << "Title: " << bookVec.at(i)->getTitle() << endl;
            cout << "Author: " << bookVec.at(i)->getAuthor() << endl;
            cout << "Category: " << bookVec.at(i)->getCategory() << endl;
            cout << endl;
            ++count;
        }
    }
    if(count == 0){
        cout << "No available books" << endl;
    }
}

void outstandingRentals(vector<Book *> bookVec, vector <Person*> perVec){
    int found = -1;
    for(int i = 0; i < bookVec.size(); ++i){
      if(bookVec.at(i)->getChecked() == true){
        found = findPerson(bookVec.at(i)->getRenterID(), perVec);
        cout << "Book ID: " << bookVec.at(i)->getBookID() << endl;
        cout << "Title: " << bookVec.at(i)->getTitle() << endl;
        cout << "Author: " << bookVec.at(i)->getAuthor() << endl;
        cout << "Cardholder: " << perVec.at(found)->getFirstName() << " " << perVec.at(found)->getLastName() << endl;
        cout << "Card ID: " << bookVec.at(i)->getRenterID() << endl;
      }
    }
    if(found == -1){
        cout << "No outstanding rentals" << endl;
    }
}

void cardholderRentals(vector<Person *> perVec, int cardID, vector<Book *> bookVec){
  int cardholder = findPerson(cardID, perVec);
  int count = 0;
  if(cardholder == -1){
    cout << "Card ID not found" << endl;
    return;
  }else if(perVec.at(cardholder)->getActive() == false){
    cout << "Card ID is inactive" << endl;
    return;
  }else{
    cout << "Card ID: " << perVec.at(cardholder)->getCardID() << endl;
    cout << "Cardholder: " << perVec.at(cardholder)->getFirstName() << " " << perVec.at(cardholder)->getLastName() << endl;
    for(int i = 0; i < bookVec.size(); ++i){
      if(bookVec.at(i)->getRenterID() == cardID){
        cout << "Book Id: " << bookVec.at(i)->getBookID() << endl;
        cout << "Title: " << bookVec.at(i)->getTitle() << endl;
        cout << "Author: " << bookVec.at(i)->getAuthor() << endl;
        ++count;
      }
    }
    if(count == 0){
      cout << "No oustanding rentals" << endl;
    }
  }
}

int findLargest(vector<Person *> perVec){
  int largest = 0;
  for(int i = 0; i < perVec.size(); ++i){
    if(perVec.at(i)->getCardID() > largest){
      largest = perVec.at(i)->getCardID();
    }
  }
  return largest;
}

vector<Person *> newLibraryCard(vector<Person *> perVec){
  Person *temp;
  string fname;
  string lname;
  cout << "Please enter the first name: ";
  cin >> fname;
  cout << endl;
  cout << "Please enter the last name: ";
  cin >> lname;
  cout << endl;
  perVec.push_back(new Person);
  perVec.at(perVec.size()-1)->setFirstName(fname);
  perVec.at(perVec.size()-1)->setLastName(lname);
  perVec.at(perVec.size()-1)->setCardID(findLargest(perVec)+1);
  perVec.at(perVec.size()-1)->setActive(true);
  cout << "Card ID " << perVec.at(perVec.size()-1)->getCardID() << " active" << endl;
  cout << "Cardholder: " << perVec.at(perVec.size()-1)->getFirstName() << " " << perVec.at(perVec.size()-1)->getLastName() << endl;
  return perVec;
}

void closeLibraryCard(vector<Person *> perVec, int cardID){
  int found = -1;
  char answer;
  for(int i = 0; i < perVec.size(); ++i){
    if(perVec.at(i)->getCardID() == cardID){
      found = i;
    }
  }
  if(found == -1){
    cout << "Card ID not found" << endl;
    return;
  }else if(perVec.at(found)->getActive() == false){
    cout << "Card ID is already inactive" << endl;
    return;
  }else{
    cout << "Cardholder: " << perVec.at(found)->getFirstName() << " " << perVec.at(found)->getLastName() << endl;
    cout << "Are you sure you want to deactivate card (y/n)?";
    cin >> answer;
    cout << endl;
    if(answer == 'y'){
      perVec.at(found)->setActive(false);
      cout << "Card ID deactivated" << endl;
    }
  }
}

void writeData(vector<Book *> bookVec, string fileName){
  fstream myFile;
  myFile.open(fileName);
  for(int i = 0; i < bookVec.size(); ++i){
    if(bookVec.at(i)->getChecked() == true){
      myFile << bookVec.at(i)->getBookID() << " " << bookVec.at(i)->getRenterID() << endl;
    }
  }
  myFile.close();
}

int main(){
  vector<Book *> books;
  vector<Person *> cardholders;
  int choice;
  int cardID;
  int bookID;
  cardholders = readPersonFile(cardholders, "persons.txt");
  books = readBookFile(books, "books.txt");
  do{
    printmenu();
    cin >> choice;
    switch(choice){
      case 1:
        cout << "Please enter the card ID: ";
        cin >> cardID;
        cout << endl;
        bookCheckout(books, cardholders, cardID);
        break;
      case 2:
        cout << "Please enter the book ID to return: ";
        cin >> bookID;
        cout << endl;
        bookReturn(books, bookID);
        break;
      case 3:
        availableBooks(books);
        break;
      case 4:
        outstandingRentals(books, cardholders);
        break;
      case 5:
        cout << "Please enter the card ID: ";
        cin >> cardID;
        cout << endl;
        cardholderRentals(cardholders, cardID, books);
        break;
      case 6:
        cardholders = newLibraryCard(cardholders);
        break;
      case 7:
        cout << "Please enter the card ID: ";
        cin >> cardID;
        cout << endl;
        closeLibraryCard(cardholders, cardID);
        //writeData(cardholder, "persons.txt");
        //apply in new loop
      case 8:
        cout << "Exiting program..." << endl;
        writeData(books, "rentals.txt");
        break;
      default:
        cout << "Invalid entry" << endl;
        break;
    }
    cout << endl;
  }while(choice != 8);
  for(int i = 0; i < books.size(); ++i){
    delete books.at(i);
  }
  for(int i = 0; i < cardholders.size(); ++i){
    delete cardholders.at(i);
  }
  return 0;
}
