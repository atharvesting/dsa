#include <stdio.h>
#include <stdlib.h>

// Heap

void swap(int* n1, int* n2) {
	int t = *n1;
	*n1 = *n2;
	*n2 = t;
}

void print_array(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d  ", arr[i]);
	}
	printf("\n");
}

int insert_heap(int* arr, int* size, int val) {
	int idx = *size;
	arr[idx] = val;
	(*size)++;
	int parent = (idx - 1) / 2;

	while (idx > 0 && arr[parent] < arr[idx])
	{
		swap(arr + parent, arr + idx);
		idx = parent;
		parent = (parent - 1) / 2;
	}

	return idx;
}

void heap_sort(int* arr, int* size) {
	int root = arr[0];
	swap(arr, arr + *size - 1);
	(*size)--;

	int idx = 0;

	while (*size > 0) {
		int left = 2 * idx + 1;
		int right = 2 * idx + 2;
		int largest = idx;

		if (left < *size && arr[left] > arr[largest]) {
			largest = left;
		}

		if (right < *size && arr[right] > arr[largest]) {
			largest = right;
		}

		if (largest == idx) break;

		swap(arr + idx, arr + largest);
		idx = largest;
	}
}

int main() {
	int size = 9;
	int arr[100] = { 0 };
	int example[9] = { 5, 3, 7, 1, 8, 2, 9, 4, 6 };

	int current_size = 0;

	for (int i = 0; i < size; i++) {
		int current = insert_heap(arr, &current_size, example[i]);
	}
	print_array(arr, current_size);
}