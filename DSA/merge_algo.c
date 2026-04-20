#include <stdio.h>

void merge(int* arr1, int* arr2, int* merged, int s1, int s2, int full_size) {

    int i = 0, j = 0, t = 0;
    while (i < s1 && j < s2) {
        if (arr1[i] < arr2[j]) {
            merged[t++] = arr1[i++];
        }
        else {
            merged[t++] = arr2[j++];
        }
    }

    while (i < s1) merged[t++] = arr1[i++];
    while (j < s2) merged[t++] = arr2[j++];
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr1[] = { 2, 4, 5, 6, 10, 42, 67 };
    int arr2[] = { 1, 3, 7, 41 };

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int full_size = size1 + size2;

    int merged[full_size];

    merge(arr1, arr2, merged, size1, size2, full_size);

    print_array(merged, full_size);

    return 0;
}