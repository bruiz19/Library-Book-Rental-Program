//Brandon Ruiz
//Section 02

#include "person.h"

Person::Person(int CI, bool A, string FN, string LN) {
    cardID=CI;
    active=A;
    firstName=FN;
    lastName=LN;
}

string Person::getFirstName() {
    return firstName;
}

string Person::getLastName() {
    return lastName;
}

int Person::getId() {
    return cardID;
}

void Person::setActive(bool A) {
    active=A;
}

bool Person::isActive() {
    return active;
}

string Person::fullName() {
    string fullName=firstName+" "+lastName;
    return fullName;
}
