#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

// Doubly Circular Linked List

struct Node {
	int val;
	struct Node* prev;
	struct Node* next;
} *START = NULL;

struct Node* create_node(int val) {
	struct Node* t = (struct Node*)malloc(sizeof(struct Node));
	t->val = val;
	t->prev = NULL;
	t->next = NULL;
	return t;
}

void insert_end(int val) {
	if (START == NULL) {
		START = create_node(val);
		START->prev = START; START->next = START;
		return;
	}
	struct Node* t = START->prev;
	t->next = create_node(val);
	t->next->prev = t;
	t->next->next = START;
	START->prev = t->next;
}

void delete_end(void) {
	if (START == NULL) {
		printf("LL Empty!\n");
		return;
	}

	if (START->next == START) {
		free(START);
		START = NULL;
		return;
	}

	struct Node* t = START->prev;
	t->prev->next = START;
	START->prev = t->prev;
	free(t);
}

void print_ll(void) {
	if (START == NULL) {
		printf("LL Empty!\n");
		return;
	}
	struct Node* q = START;
	do {
		printf("%d  ", q->val);
		q = q->next;
	} while (q != START);
	printf("\n");
}

int main() {
	int c, n;
	do {
		print_ll();
		printf("Enter command: ");
		scanf_s("%d", &c);
		switch (c) {
		case 1:
			printf("Append: ");
			scanf_s("%d", &n);
			insert_end(n);
			break;
		case 2: delete_end(); break;
		case 0: break;
		}
	} while (c != 0);
	return 0;
}