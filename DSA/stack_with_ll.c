#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
} *START = NULL;

int MAX = 5, COUNT = 0, c, n;

struct Node* createNode(int val) {
    struct Node* t;
    t = (struct Node*)malloc(sizeof(struct Node));
    t->val = val;
    return t;
}

void push(int val) {
    struct Node* t;
    if (COUNT == MAX) {
        printf("Stack Overflow\n");
        return;
    }
    t = START;
    START = createNode(val);
    START->next = t;
    COUNT++;
}

void pop(void) {
    if (COUNT == 0) {
        printf("Stack Underflow\n");
        return;
    }
    struct Node* t;
    t = START;
    START = START->next;
    printf("Popped: %d\n", t->val);
    free(t);
    COUNT--;
}

void display(void) {
    if (START == NULL) {
        printf("Empty!\n");
    }
    for (struct Node* q = START; q != NULL; q = q->next) {
        printf("\n|  %d  |", q->val);
    }
    printf("\n--------\n");
}

int main() {

    do {
        display();
        printf("1. Push, 2. Pop, 0. Exit: ");
        scanf("%d", &c);

        switch (c) {
        case 1:
            printf("n: ");
            scanf("%d", &n);
            push(n);
            break;
        case 2:
            pop();
            break;
        case 0:
            break;
        default:
            printf("Invalid Input.\n");
            break;
        }

    } while (c != 0);

    return 0;
}