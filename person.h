//Brandon Ruiz
//Section 02

#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Person{
  private:
    int cardID;
    bool active;
    string firstName;
    string lastName;
  public:
    Person();
    Person(int id, bool act, string fn, string ln);
    int getCardID();
    void setCardID(int id);
    bool getActive();
    void setActive(bool a);
    string getFirstName();
    void setFirstName(string fName);
    string getLastName();
    void setLastName(string lName);
};
#endif
