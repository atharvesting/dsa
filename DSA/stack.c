#include <stdio.h>
#define SIZE 5

void push(int*, int, int*, int);
void pop(int*, int*);
void print_stack(int*, int, int*);

int main() {
	int test[SIZE] = { 0 }, limit = 0, * top, command, work;
	top = &limit;
	do {
		printf("\n");
		print_stack(test, SIZE, top);
		printf("1. Print, 2. Push, 3. Pop, 0. Exit\n\n");
		printf("Instruction: ");
		scanf_s("%d", &command);
		switch (command) {
		case 1:
			break;
		case 2:
			printf("Enter a number to push to stack: ");
			scanf_s("%d", &work);
			push(test, SIZE, top, work);

			break;
		case 3:
			pop(test, top);
			break;
		case 0:
			printf("Successful Exit!\n");
			break;
		default:
			printf("Invalid value entered.\n");
			break;
		}

	} while (command != 0);


	return 0;
}

void push(int* stack, int size, int* top, int element) {
	if (*top == size) {
		printf("Stack overflow!\n");
		return;
	}
	*(stack + *top) = element;
	(*top)++;
	printf("After Pushing: \n");
}

void pop(int* stack, int* top) {
	if (*top < 0) {
		printf("Stack underflow!\n");
		return;
	}
	printf("Removed: %d\n", *(stack + *top - 1));
	(*top)--;
}

void print_stack(int* stack, int size, int* top) {
	for (int i = size - 1; i >= 0; i--) {
		if (i >= *top) {
			printf("Empty\n");
		}
		else {
			printf("%d\n", *(stack + i));
		}
	}
}