int binaryGap(int n) {
    if ((n & (n - 1)) == 0) {
        return 0;
    }
    int seenOne = 0;
    int last = 10, maxi = 0, count = 0;
    for (int i = n; i != 0; i = i >> 1) {
        if ((i & 1) == 1) {
            seenOne = 1;
            count++;
            maxi = std::max(count, maxi);
            count = 0;
        } else {
            if (seenOne) count++;
        }
        last = i & 1;
    }
    return maxi;
}