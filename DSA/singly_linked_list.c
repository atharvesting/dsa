/*
This is a menu-driven program to showcase the implementation of a linked list in C.

The various operations include:
	- Printing the linked list.
	- Deleting an item at a given index.
	- Searching for an item.
	- Inserting an item at a given index.
*/

#include <stdio.h>
#include <stddef.h>

struct Node {
	int data;
	struct Node* next;
} *START = NULL, *p = NULL;

int c, q, size_ll = 0;

void print_ll(void);
void search_ll(void);
void insert_ll(void);

int main() {

	do {
		print_ll();
		printf("\n1. Print, 2. Search, 3. Insert, 0. Exit");
		printf("Enter command: ");
		scanf("%d", &c);

		switch (c) {
		case 1:
			break;
		case 2:
			search_ll();
			break;
		case 3:
			insert_ll();
			break;
		case 0:
			break;
		}

	} while (c != 0);
}

void print_ll(void) {
	if (START == NULL) printf("LL Empty!\n"); return;
	p = START;
	while (p->next != NULL) {
		printf("%d  ", p->data);
		p = p->next;
	}
}

void search_ll(void) {
	if (START == NULL) printf("LL Empty!\n"); return;
	printf("Enter target: ");
	scanf("%d", c);
	p = START;
	while (p != NULL) {
		if (p->data == c) {
			printf("Target %d found at address %d.\n", c, &p->data);
			return;
		}
		p = p->next;
	}
	printf("Target not found in LL.\n");
}

void insert_ll(void) {
	if (START == NULL) {
		START = (struct Node*)malloc(sizeof(struct Node));
		size_ll++;
	}
	else {
		printf("(idx) Insert at index, (-1) Insert at the end: ");
		scanf("%d", &c);
		p = START;
		q = 0;
		if (c > 0 && c < size_ll) {
			while (q != p) {
				if (q == c) {
					
				}
				p = p->next;
				q++;
			}
		}
	}
}