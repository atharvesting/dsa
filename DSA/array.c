#include <stdio.h>
#define SIZE 10

void print_array(int*, int);
void bubble_sort(int*, int);
int search_for(int*, int, int);
void update(int*, int, int, int);
void delete_element(int*, int, int);

int main() {
	int test[SIZE] = { 9,8,7,6,5,4,3,2,1,0 }, target = 4;
	int command, search, found, idx;
	do {
		print_array(test, SIZE);
		printf("1. Print, 2. Sort, 3. Search, 4. Update, 5. Delete, 0. Exit\n\n");
		printf("Instruction: ");
		scanf_s("%d", &command);
		switch (command) {
		case 1:
			break;
		case 2:
			bubble_sort(test, SIZE);
			printf("After Sorting: \n");
			break;
		case 3:
			printf("Enter a number to search for: ");
			scanf_s("%d", &search);
			found = search_for(test, SIZE, search);
			if (found == -1) printf("Not found in array\n");
			else printf("%d found at index %d\n", search, found);
			break;
		case 4:
			printf("Enter index and value to update with: ");
			scanf_s("%d %d", &idx, &search);
			update(test, SIZE, idx, search);
			printf("Value updated!\n");
			break;
		case 5:
			printf("Enter index to delete: ");
			scanf_s("%d", &idx);
			delete_element(test, SIZE, idx);
			printf("Element at index %d deleted!\n", idx);
			break;
		case 0:
			printf("Successful Exit!");
			break;
		default:
			printf("Invalid value entered.");
			break;
		}

	} while (command != 0);


	return 0;
}

void print_array(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", *(arr + i));
	}
	printf("\n\n");
}

void bubble_sort(int* arr, int size) {
	int t = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (*(arr + j) > *(arr + j + 1)) {
				t = *(arr + j + 1);
				*(arr + j + 1) = *(arr + j);
				*(arr + j) = t;
			}
		}
	}
}

void delete_element(int* arr, int size, int idx) {
	for (int i = idx; i < size - 1; i++) {
		*(arr + i) = *(arr + i + 1);
	}
	*(arr + size - 1) = -1;
}

int search_for(int* arr, int size, int target) {
	for (int i = 0; i < size; i++) {
		if (*(arr + i) == target) {
			return i;
		}
	}
	return -1;
}

void update(int* arr, int size, int target_idx, int new_val) {
	if (target_idx > size || target_idx < 0) {
		printf("Invalid index chosen.");
	}
	*(arr + target_idx) = new_val;
}