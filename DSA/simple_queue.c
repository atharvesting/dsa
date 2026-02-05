#include <stdio.h>
#define S 5

int c, i, f = 0, r = 0;
int queue[5] = { 0 };

void print_queue(void);
void enqueue(void);
void dequeue(void);

int main() {
	do {
		print_queue();
		printf("\n1. Print, 2. Enqueue, 3. Dequeue, 0. Exit %d\n", r);
		printf("Enter command: ");
		scanf("%d", &c);
		switch (c) {
		case 1: break;
		case 2: enqueue(); break;
		case 3: dequeue(); break;
		case 0: break;
		default:
			printf("Invalid command entered. Try again.\n");
			break;
		}

	} while (c != 0);

	return 0;
}

void print_queue(void) {
	if (f == r) {
		printf("Empty!\n");
		return;
	}
	for (i = f; i < r; i++) {
		printf("%d  ", queue[i]);
	}
	printf("\n");
}

void enqueue(void) {
	if (r >= S) {
		if (f > 0) {
			for (i = 0; i < S - f; i++) {
				queue[i] = queue[f + i];
			}
			r = r - f;
			f = 0;
		}
		else {
			printf("Queue Overflow!\n");
			return;
		}
	}
	printf("Enqueue: ");
	scanf("%d", &queue[r]);
	r++;
}

void dequeue(void) {
	if (r == f) {
		printf("Queue Underflow!\n");
		return;
	}
	f++;
}