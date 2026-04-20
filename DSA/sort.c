#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

/* Sorting algorithms
*
* Bubble Sort ✔️
* Selection Sort ✔️
* Insertion Sort ✔️
* Merge Sort ✔️
* Quick Sort
* Heap Sort
*
*/

void print_array(int* arr, int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%d  ", *(arr + i));
	}
	printf("\n");
}

void swap(int* n1, int* n2) {
	int t = *n1;
	*n1 = *n2;
	*n2 = t;
}

void bubble_sort(int* arr, int size) {
	int i, j;
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - i - 1; j++) {
			if (*(arr + j) > *(arr + j + 1)) {
				swap((arr + j), (arr + j + 1));
			}
		}
	}
}

void selection_sort(int* arr, int size) {
	int i, j;
	int* min = arr;
	for (i = 0; i < size - 1; i++) {
		for (j = i + 1; j < size; j++) {
			if (*(arr + j) < *min) {
				min = (arr + j);
			}
		}
		swap(min, arr + i);
	}
}

void insertion_sort(int* arr, int size) {
	int i, j;
	for (i = 1; i < size - 1; i++) {
		int temp = *(arr + i);
		j = i - 1;
		while (*(arr + j) > temp && j >= 0) {
			*(arr + j + 1) = *(arr + j);
			j--;
		}
		*(arr + j + 1) = temp;
	}
}

void ms_merge(int* arr, int start, int mid, int end) {
	int n = end - start + 1;
	int* temp = (int*)malloc(n * sizeof(int));
	int i = start, j = mid + 1, t = 0;

	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j]) {
			temp[t++] = arr[i++];
		}
		else {
			temp[t++] = arr[j++];
		}
	}

	while (i <= mid) temp[t++] = arr[i++];
	while (j <= end) temp[t++] = arr[j++];

	for (int idx = 0; idx < n; idx++) {
		arr[idx + start] = temp[idx];
	}

	free(temp);
}

void merge_sort(int* arr, int start, int end) {

	if (start < end) {
		int mid = start + (end - start) / 2;
		merge_sort(arr, start, mid);	// Left Half
		merge_sort(arr, mid + 1, end);  // Right Half

		ms_merge(arr, start, mid, end);
	}
}

int qs_partition(int* arr, int start, int end) {
	int pivot = arr[end], idx = start - 1;
	for (int j = start; j < end; j++)
	{
		if (arr[j] <= pivot)
		{
			idx++;
			swap((arr + j), (arr + idx));
		}
	}
	idx++;
	swap((arr + end), (arr + idx));
	return idx;
}

void quick_sort(int* arr, int start, int end) {

	if (start < end) {
		int pivotIdx = qs_partition(arr, start, end);
		quick_sort(arr, start, pivotIdx - 1);
		quick_sort(arr, pivotIdx + 1, end);
	}
}

void hs_heapify(int* arr, int* size) {
	
	for (int i = 0; i < *size; i++) {
		int idx = *size;
		arr[idx] = arr[i];
		(*size)++;
		int parent = (idx - 1) / 2;

		while (idx > 0 && arr[parent] < arr[idx])
		{
			swap(arr + parent, arr + idx);
			idx = parent;
			parent = (parent - 1) / 2;
		}
	}
}

void heap_sort(int* arr, int* size) {
	int zero = 0;
	hs_heapify(arr, &zero);
	swap(arr, arr + *size - 1);
	(*size)--;

	int idx = 0;

	for (int i = )
	while (1) {
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
	int arr[SIZE] = { 2,6,8,3,0,7,5,4,1,9 };
	print_array(arr, SIZE);
	heap_sort(arr, SIZE - 1);
	print_array(arr, SIZE);

	return 0;
}