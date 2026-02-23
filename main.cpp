#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

struct Node {
	int val;
	struct Node* next = NULL;
} *START = NULL, *q = NULL, *t = NULL;

struct Node* create_node(int data) {
	t = (struct Node*)malloc(sizeof(struct Node));
	t->val = data;
	return t;
}

void insert_end(int data) {
	if (START == NULL) {
		START = create_node(data);
		START->next = START;
		return;
	}
	for (q = START; q->next != START; q = q->next) {}
	q->next = create_node(data);
	q->next->next = START;
}

void delete_end(void) {
	if (START == NULL) {
		printf("LL Empty!\n");
		return; 
	}
	for (q = START; q->next->next != START || q->next != START; q = q->next) {}
	if (q == START) {
		t = START; START = NULL;
		free(t);
	}
	t = q->next;
	q->next = START;
	free(t);
}

int main() {
	t = create_node(4);
	printf("%d\n", t->val);
	t->next = create_node(19);
	t->next->next = START;
	printf("%d\n", t->next->val);
	for (q = t; q != START; q = q->next) {
		printf("%d  ", q->val);
	}

	return 0;
}