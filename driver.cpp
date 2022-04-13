//Created by ALejandro Mozqueda

#include <algorithm>
#include <array>
#include <iostream>
#include <time.h>
#include <vector>

#include "SortBase.h"

#include "Insertion.h"
#include "Merge.h"
#include "Person.h"
#include "Quick.h"
#include "Selection.h"

int main() {
    srand(time(0));


    SortBase<int>* s1 = new Quick<int>();
    int arr[3] = {1, 2, 3};
    s1->sort<>(std::begin(arr), std::end(arr));

    SortBase<int>* s2 = new Insertion<int>();
    std::vector<int> vec = {1, 2, 3};
    s2->sort<>(std::begin(vec), std::end(vec));

    SortBase<Person>* s3 = new Selection<Person>();
    Person p("A", "B", 1, 2);
    std::array<Person, 3> arr2;
    arr2.fill(p);
    s3->sort<>(std::begin(arr2), std::end(arr2));


    return 0;
}
// std::vector<People> people;
// algorithm.sort(people.begin(), people.end(), )