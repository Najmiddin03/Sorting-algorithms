#include <chrono>
#include <cassert>
#include <iostream>
#include <random>
#include "quicksort.h"
#include "heapsort.h"
#include "mergesort.h"
#include "insertionsort.h"
const int step = 100;
const int maxSize = 10000;
const int times = 100;

using std::chrono::nanoseconds;
using namespace std;

nanoseconds timeit(int* original, int* arr, int size, string alg);

int main() {
    random_device rd;
    mt19937 gen(rd());

    cout << "Size Quick Heap Merge Insertion\n";

    for (int size = step; size <= maxSize; size += step) {
        nanoseconds quick(0);
        nanoseconds heap(0);
        nanoseconds merge(0);
        nanoseconds ins(0);

        int* original = new int[size];
        for (int i = 0; i < size; i++) {
            original[i] = i;
        }

        int* arr = new int[size];

        for (int t = 0; t < times; t++) {
            shuffle(original, original + size, gen);

            quick += timeit(original, arr, size, "quick");
            heap += timeit(original, arr, size, "heap");
            merge += timeit(original, arr, size, "merge");
            ins += timeit(original, arr, size, "insertion");
        }

        cout << size << " ";
        cout << quick.count() / times << "  ";
        cout << heap.count() / times << "  ";
        cout << merge.count() / times << "  ";
        cout << ins.count() / times << "\n";

        delete[] arr;
        delete[] original;
    }
    return 0;
}

nanoseconds timeit(int* original, int* arr, int size, string alg) {
    copy(original, original + size, arr);

    auto start = chrono::steady_clock::now();
    if (alg == "quick") {
        quicksort(arr, 0, size - 1);
    }
    if (alg == "heap") {
        heapsort(arr, size);
    }
    if (alg == "merge") {
        mergeSort(arr, 0, size - 1);
    }
    if (alg == "insertion") {
        insertion_sort(arr, size);
    }
    auto stop = chrono::steady_clock::now();

    assert(std::is_sorted(arr, arr + size));

    nanoseconds time(stop - start);
    return time;
}