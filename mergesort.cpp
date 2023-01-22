#include "mergesort.h"
void mergeSort(int* arr, int left, int right) {
	if (left < right) {
		int median = (left + right) / 2;
		mergeSort(arr, left, median);
		mergeSort(arr, median + 1, right);
		merge(arr, left, median, right);
	}
}

void merge(int* arr, int left, int median, int right) {
	int i = left;
	int j = median + 1;
	int k = left;

	int* temp = new int[right + 1];
	while (i <= median && j <= right) {
		if (arr[i] <= arr[j]) {
			temp[k] = arr[i];
			i++;
			k++;
		}
		else {
			temp[k] = arr[j];
			j++;
			k++;
		}
	}
	while (i <= median) {
		temp[k] = arr[i];
		i++;
		k++;
	}
	while (j <= right) {
		temp[k] = arr[j];
		j++;
		k++;
	}
	for (int p = left; p <= right; p++) {
		arr[p] = temp[p];
	}
	delete[]temp;
}