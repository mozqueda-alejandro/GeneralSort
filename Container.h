#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>

class Container {
private:
    int num1;
    int num2;
    std::string word;
public:
    Container();
    Container(int num1, int num2, std::string word);
    ~Container();
};

#endif // CONTAINER_H