#include <cmath>

int setBits(int num) {
    int set_count = 0;
    for (int x = num; x != 0; x = x >> 1) {
        if ((x & 1) == 1) set_count++;
    }
    return set_count;
}

int prime_check(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int j = 2; j <= sqrt(num); j++) {
        if (num % j == 0) {
            return 0;;
        }
    }
    return 1;
}

int countPrimeSetBits(int left, int right) {
    int prime = 0;
    for (int i = left; i <= right; i++) {
        if (prime_check(setBits(i))) prime++;
    }
    return prime;
}