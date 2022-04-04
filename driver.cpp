//Created by ALejandro Mozqueda

#include <iostream>
#include <time.h>
#include "SortTest.h"

int main() {
    srand(time(0));

    Selection<int>   select;
    Insertion<int>   insert;
    // Bubble<int>      bubble;
    // Merge<int>       merge;
    Quick<int>       quick;
    // Radix<int>       radix;
    
    SortTest test;

    test.run<>(select);
    test.run<>(insert);
    // test.run<>(bubble);
    // test.run<>(merge);
    test.run<>(quick);
    // test.run<>(radix);

    return 0;
}