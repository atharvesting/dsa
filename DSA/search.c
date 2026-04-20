#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

/* Searching Algorithms
*
* Linear/Sequential Search ✔️
* Binary Search ✔️
* Interpolation Search ✔️
* Transpose Sequential Search ✔️
*
*/

int linear_search(int* arr, int size, int target) {

	if (arr == NULL || size <= 0) return -1;

	int i;
	for (i = 0; i < size; i++) {
		if (*(arr + i) == target) {
			return i;
		}
	}
	return -1;
}

int binary_search(int* arr, int size, int target) {

	if (arr == NULL || size <= 0) return -1;

	int low = 0, high = size - 1, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		int current = *(arr + mid);

		if (current == target) {
			return mid;
		}
		else if (current > target) {
			high = mid - 1;
		}
		else if (current < target) {
			low = mid + 1;
		}
	}
	return -1;
}

/// The given array should be sorted and be uniformly distributed for optimal results
int interpolation_search(int* arr, int size, int target) {
	int low = 0, high = size - 1;

	while (low <= high && arr[low] != arr[high] &&
		target >= arr[low] && target <= arr[high]) {

		int pos = low + (int)(
			((double)(target - arr[low]) * (high - low)) /
			(arr[high] - arr[low])
			);

		if (pos < low || pos > high) return -1;

		if (arr[pos] == target) return pos;
		if (arr[pos] < target) low = pos + 1;
		else high = pos - 1;
	}

	if (low <= high && arr[low] == target) return low;
	return -1;
}

void swap(int* n1, int* n2) {
	int t = *n1;
	*n1 = *n2;
	*n2 = t;
}

void print_array(int* arr, int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%d  ", arr[i]);
	}
	printf("\n");
}

int transpose_sequential_search(int* arr, int size, int target) {
	int i;
	for (i = 0; i < size; i++)
	{
		if (arr[i] == target)
		{
			if (i > 0)
			{
				swap((arr + i), (arr + i - 1));
			}
			return i > 0 ? i - 1 : i;
		}
	}
	return -1;
}

int main() {
	int arr[SIZE] = { 1,2,3,4,5,6,7,8,9 };
	//int result_linear = linear_search(arr, SIZE, 1);
	//int result_binary = binary_search(arr, SIZE, 1);
	printf("Linear: %d, Binary: %d\n", linear_search(arr, SIZE, 1), binary_search(arr, SIZE, 1));
	printf("Interpolation: %d\n", interpolation_search(arr, SIZE, 8));
	printf("Transpose Sequential: \n");
	transpose_sequential_search(arr, SIZE);
	print_array(arr, SIZE);

	return 0;
}