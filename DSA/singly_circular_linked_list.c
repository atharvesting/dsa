#include <stdio.h>
#include <stdlib.h>

struct Node {
	int val;
	struct Node* next;
} *START = NULL;

struct Node* create_node(int val) {
	struct Node* t = (struct Node*)malloc(sizeof(struct Node));
	t->val = val; t->next = NULL;
	return t;
}

void insert_end(int val) {
	if (START == NULL) {
		START = create_node(val);
		START->next = START;
		return;
	}
	struct Node* q = START;

	while (q->next != START) {
		q = q->next;
	}

	q->next = create_node(val);
	q->next->next = START;
}

void insert_idx(int val, int idx) {
	if (START == NULL) {
		if (idx == 0) {
			START = create_node(val);
			return;
		}
		printf("LL Empty!\n");
		return;
	}
	struct Node* q = START; int i = 0;

	while (i < idx - 1 && q->next != START) {
		q = q->next;
		i++;
	}

	if (i + 1 == idx) {
		struct Node* temp = q->next;
		q->next = create_node(val);
		q->next->next = temp;
		return;
	}
	printf("Invalid Idx, Num of Nodes = %d\n", i + 1);
}

void delete_end() {
	if (START == NULL) {
		printf("LL Empty!\n");
	}
	else if (START->next == START) {
		START = NULL;
	}
	else {
		struct Node* q = NULL;
		for (q = START; q->next->next != START; q = q->next) {}
		struct Node* t = q->next;
		q->next = q->next->next;
		free(t);
	}
}

void print_ll() {
	if (START == NULL) {
		printf("LL Empty!\n");
	}
	else {
		struct Node* q;
		printf("%d  ", START->val);
		for (q = START->next; q != START; q = q->next) {
			printf("%d  ", q->val);
		}
	}
	printf("\n");
}

int main() {
	int c, n, i;
	do {
		print_ll();
		printf("Command: ");
		scanf_s("%d", &c);
		switch (c) {
		case 1:
			printf("Val: "); scanf_s("%d", &n);
			insert_end(n); break;
		case 2:
			printf("Val, Idx: "); scanf_s("%d %d", &n, &i);
			printf("Val: %d, Idx: %d\n", n, i);
			insert_idx(n, i); break;
		case 3: delete_end(); break;
		default: break;
		}

	} while (c != 0);
}
