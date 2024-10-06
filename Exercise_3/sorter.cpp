// sorter.cpp
#include "sorter.h"

// Method to print the elements of the array
void Sorter::printArray(const std::vector<int>& arr) const {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Method to measure and return the time taken to sort the array
double Sorter::measureSortTime(std::vector<int>& arr) {
    // Get the starting time point
    auto start = std::chrono::high_resolution_clock::now();

    // Call the sorting function (polymorphism)
    sort(arr);

    // Get the ending time point
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the duration in microseconds
    std::chrono::duration<double, std::micro> duration = end - start;

    // Return the duration in microseconds
    return duration.count();
}

// Selection Sort implementation
void SelectionSorter::sort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

// Insertion Sort implementation
void InsertionSorter::sort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Bubble Sort implementation
void BubbleSorter::sort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Merge Sort implementation
void MergeSorter::sort(std::vector<int>& arr) {
    mergeSort(arr, 0, arr.size() - 1);
}

// Helper function to perform merge sort on the array
void MergeSorter::mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

// Helper function to merge two sorted halves
void MergeSorter::merge(std::vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;
    std::vector<int> L(n1);
    std::vector<int> R(n2);
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[middle + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
