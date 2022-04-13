#include "Person.h"


Person::Person() :
    firstName(""),
    lastName(""),
    height(0),
    age(0)
{}

Person::Person(std::string newFirstName, std::string newLastName, int newHeight, int newAge) :
    firstName(newFirstName),
    lastName(newLastName),
    height(newHeight),
    age(newAge)
{}

bool Person::operator<(const Person& person) {
    return false;
}
bool Person::operator>(const Person& person) {
    return false;
}
std::ostream& operator<<(std::ostream& stream, const Person& person) {
    stream << person.firstName << ", " << person.lastName << ", " << person.height << ", " << person.age << "\n";
    return stream;
}
std::istream& operator>>(std::istream& stream, Person& person) {
    char comma{};
    stream >> person.firstName >> comma >> person.lastName >> comma >> person.height >> comma >> person.age;
    return stream;
}

void Person::setFirstName(std::string newFirstName) {
    firstName = newFirstName;
}

void Person::setLastName(std::string newLastName) {
    lastName = newLastName;
}

void Person::setName(std::string newName) {
    if (newName.find(",") != std::string::npos) {
        std::string lastName = newName.substr(0, newName.find(",")) + "!";
        std::string firstName = newName.substr(newName.find(",") + 1) + "!";
        setFirstName(firstName);
        setLastName(lastName);
    } else {
        firstName = newName.substr(0, newName.find(" ")) + "!";
        lastName = newName.substr(newName.find(" ") + 1) + "!";
    }    
}

void Person::setHeight(int newHeight) {
    height = newHeight;
}

void Person::setAge(int newAge) {
    age = newAge;
}

// std::string Person::getObjectType() {
//     return "Person";
// }