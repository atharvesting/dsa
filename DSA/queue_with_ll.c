#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

// Queue using Linked List

struct Node {
	int val;
	struct Node* next;
} *FRONT = NULL, * REAR = NULL;

struct Node* create_node(int val) {
	struct Node* t = (struct Node*)malloc(sizeof(struct Node));
	t->val = val;
	t->next = NULL;
	return t;
}

void enqueue(int val) {
	if (FRONT == NULL) {
		FRONT = create_node(val);
		return;
	}
	struct Node* q;
	for (q = FRONT; q->next != NULL; q = q->next) {}
	q->next = create_node(val);
	REAR = q;
}

void dequeue(void) {
	if (FRONT == NULL) {
		printf("Queue Empty!\n");
		return;
	}
	struct Node* q = FRONT;
	FRONT = FRONT->next;
	free(q);
}

void print_queue(void) {
	if (FRONT == NULL) {
		printf("Queue Empty!\n");
		return;
	}
	struct Node* q = FRONT;
	printf("FRONT -- ");
	for (q; q != NULL; q = q->next) {
		printf("%d ", q->val);
	}
	printf("-- REAR\n");
}

void main(void) {
	int c, n;
	do {
		print_queue();
		printf("Command: ");
		scanf("%d", &c);
		switch (c) {
		case 1:
			printf("Value: "); scanf("%d", &n);
			enqueue(n); break;
		case 2: dequeue(); break;
		case 0: break;
		}
	} while (c != 0);
}