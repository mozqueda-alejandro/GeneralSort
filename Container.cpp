#include "Container.h"

Container::Container() {
    num1 = 0;
    num2 = 0;
    word = "";
}

Container::Container(int num1, int num2, std::string word) {
    this->num1 = num1;
    this->num2 = num2;
    this->word = word;
}