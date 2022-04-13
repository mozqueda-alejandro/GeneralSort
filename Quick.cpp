#include "Quick.h"

template <class T>
Quick<T>::Quick() : SortBase<T>() {}

template <class T>
void Quick<T>::sort()
{    
    comparisons = 0;
    swaps = 0;
    sortTime = 0;
    std::cout << "In the quick sort" << std::endl;
    // quickSort(0, unsortedLen - 1, unsorted);
}

template <class T>
void Quick<T>::quickSort(int low, int high, T arr[])
{
    // if (low < high && low >= 0 && high >= 0) {
    //     // Hoare Partition
    //     T pivot = arr[low];
    //     int first = low - 1;
    //     int last = high + 1;
    //     while (true) {
    //         do {
    //             ++first;
    //             ++comparisons;
    //         } while (arr[first] < pivot);

    //         do {
    //             --last;
    //             ++comparisons;
    //         } while (arr[last] > pivot);

    //         if (first >= last) {
    //             break;
    //         }
    //         std::swap(arr[first], arr[last]);
    //         ++swaps;
    //     }
    //     quickSort(low, last, arr);
    //     quickSort(last + 1, high, arr);
    // }
}

template <class T>
inline std::string Quick<T>::getSortName() const
{
    return "Quick";
}