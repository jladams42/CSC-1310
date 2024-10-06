// main.cpp
#include "sorter.h"

using namespace std; 

int main() {
    // Sample data to be sorted
    std::vector<int> data1 = {64, 25, 12, 22, 11,10,9,6,6,6,6,5,4,4,3,2,12,1234,4,35,6,5,34,234,4,5,6,34,2,2,1,3,5,6,7,8,9,7,6,5,5,44,3,3,5,6,77,8,234,245,2556,2345,2,1234,1234412,5,36434,5,346,346,346,7,76,4,345,6,34,534,534,534,5,345,345345,23,4,234,5};
    std::vector<int> data2 = {64, 25, 12, 22, 11,10,9,6,6,6,6,5,4,4,3,2,12,1234,4,35,6,5,34,234,4,5,6,34,2,2,1,3,5,6,7,8,9,7,6,5,5,44,3,3,5,6,77,8,234,245,2556,2345,2,1234,1234412,5,36434,5,346,346,346,7,76,4,345,6,34,534,534,534,5,345,345345,23,4,234,5};
    std::vector<int> data3 = {64, 25, 12, 22, 11,10,9,6,6,6,6,5,4,4,3,2,12,1234,4,35,6,5,34,234,4,5,6,34,2,2,1,3,5,6,7,8,9,7,6,5,5,44,3,3,5,6,77,8,234,245,2556,2345,2,1234,1234412,5,36434,5,346,346,346,7,76,4,345,6,34,534,534,534,5,345,345345,23,4,234,5};
    std::vector<int> data4 = {64, 25, 12, 22, 11,10,9,6,6,6,6,5,4,4,3,2,12,1234,4,35,6,5,34,234,4,5,6,34,2,2,1,3,5,6,7,8,9,7,6,5,5,44,3,3,5,6,77,8,234,245,2556,2345,2,1234,1234412,5,36434,5,346,346,346,7,76,4,345,6,34,534,534,534,5,345,345345,23,4,234,5};

    // Create sorter objects for each sorting algorithm
    SelectionSorter selectionSorter;
    InsertionSorter insertionSorter;
    BubbleSorter bubbleSorter;
    MergeSorter mergeSorter;

    // Measure and print time for Selection Sort
    std::cout << "Selection Sort:" << std::endl;
    double timeSelection = selectionSorter.measureSortTime(data1);
    selectionSorter.printArray(data1);
    std::cout << "Time taken: " << timeSelection << " microseconds" << std::endl;

    // Measure and print time for Insertion Sort
    std::cout << "Insertion Sort:" << std::endl;
    double timeInsertion = insertionSorter.measureSortTime(data2);
    insertionSorter.printArray(data2);
    std::cout << "Time taken: " << timeInsertion << " microseconds" << std::endl;

    // Measure and print time for Bubble Sort
    std::cout << "Bubble Sort:" << std::endl;
    double timeBubble = bubbleSorter.measureSortTime(data3);
    bubbleSorter.printArray(data3);
    std::cout << "Time taken: " << timeBubble << " microseconds" << std::endl;

    // Measure and print time for Merge Sort
    std::cout << "Merge Sort:" << std::endl;
    double timeMerge = mergeSorter.measureSortTime(data4);
    mergeSorter.printArray(data4);
    std::cout << "Time taken: " << timeMerge << " microseconds" << std::endl;

    return 0;
}
