#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int c, idx, p;

struct Node {
    struct Node* prev;
    int val;
    struct Node* next;
} *START = NULL, * q = NULL, * t = NULL;

struct Node* create_node(void) {
    t = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value: ");
    scanf_s("%d", &(t->val));
    t->prev = NULL; t->next = NULL;
    return t;
}

bool ll_empty(void) {
    return (START == NULL ? true : false);
}

void insert_end(void) {
    if (START == NULL) {
        START = create_node();
        return;
    }
    q = START;
    while (q->next != NULL) {
        q = q->next;
    }
    q->next = create_node();
    (q->next)->prev = q;
}

void insert_idx(void) {
    printf("Index: ");
    scanf_s("%d", &idx);
    if (ll_empty() && idx != 0) {
        printf("LL empty! Invalid idx!\n");
        return;
    }
    int p = 0;
    for (q = START; q->next != NULL && p < idx - 1; p++, q = q->next) {}
    if (idx == 0) {
        t = create_node();
        t->next = START;
        START->prev = t;
        START = t;
    }
    else {
        t = create_node();
        t->next = q->next;
        t->prev = q;

        if (q->next != NULL) {
            q->next->prev = t;
        }
        q->next = t;
    }
}

void delete_end(void) {
    for (q = START; q->next->next != NULL; q = q->next) {}
    t = q->next;
    q->next = NULL;
    free(t);
}

void delete_idx(void) {
    printf("Index: ");
    scanf_s("%d", &idx);
    if (ll_empty()) {
        printf("LL Empty!\n");
        return;
    }
    int p = 0;
    for (p = 0, q = START; p < idx - 1 && q->next != NULL; p++, q = q->next) {}
    if (p < idx - 1) {
        printf("Index out of bounds!\n"); return;
    }
    t = q->next;
    q->next = q->next->next;
    q->next->prev = q;
    free(t);
}

void print_dll(void) {
    if (START == NULL) {
        printf("DLL Empty!");
        return;
    }
    for (q = START; q != NULL; q = q->next) {
        printf("%d  ", q->val);
    }
}

int main() {
    do {
        print_dll();
        printf("\n\n1.Print, 2.Insert, 3.Delete, 4.Search, 0.Exit\n");
        printf("Enter command: ");
        scanf_s("%d", &c);
        switch (c) {
        case 1: break;
        case 2:
            printf("1. Index, 2. End: ");
            scanf_s("%d", &c);
            if (c == 1) insert_idx();
            else insert_end();
            break;
        case 3:
            printf("1. Index, 2. End: ");
            scanf_s("%d", &c);
            if (c == 1) delete_idx();
            else delete_end();
        default:
            printf("Invalid command entered!\n");
            break;
        }
    } while (c != 0);
}