//Brandon Ruiz
//Section 02

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>
using namespace std;

class Person {
private:
    string firstName;
    string lastName;
    int    cardID;
    bool   active;

public:
    Person (int CI, bool A, string FN, string LN);
    string getFirstName();
    string getLastName();
    int    getId();
	void   setActive(bool A);
	bool   isActive();
    string fullName();
};
#endif // end person.h
