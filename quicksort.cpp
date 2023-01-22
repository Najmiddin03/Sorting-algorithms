#include "quicksort.h"
#include <iostream>
void quicksort(int* array, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = array[(left + right) / 2];
    int index = partition(array, left, right, pivot);
    quicksort(array, left, index - 1);
    quicksort(array, index, right);
}

int partition(int* array, int left, int right, int pivot) {
    while (left <= right) {
        while (array[left] < pivot) {
            left++;
        }
        while (array[right] > pivot) {
            right--;
        }
        if (left <= right) {
            std::swap(array[left], array[right]);
            left++;
            right--;
        }
    }
    return left;
}