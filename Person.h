#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class Person {
    std::string firstName;
    std::string lastName;
    int height;
    int age;
public:
    Person();
    Person(std::string firstName, std::string lastName, int height, int age);
    
    bool operator<(const Person&);
    bool operator>(const Person&);
    friend std::ostream& operator<<(std::ostream&, const Person&); // CSV style output
    friend std::istream& operator>>(std::istream&, Person&);

    void setName(std::string);
    void setFirstName(std::string);
    void setLastName(std::string);
    void setHeight(int);
    void setAge(int);

    // static std::string getObjectType();
};

#endif //PERSON_H