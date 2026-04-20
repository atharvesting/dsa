#include <iostream>
#include <vector>
#include <algorithm>

int countOfOnes(int num)
{
    int count = 0;
    for (int n = num; n != 0; n >>= 1)
    {
        if (n & 1 == 1) count++;
    }
    return count;
}

std::vector<int> sortByBits(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i)
    {
        int min_idx = i;

        for (int j = i + 1; j < n; ++j)
        {
            int n_min = countOfOnes(arr[min_idx]), n_j = countOfOnes(arr[j]);
            if (n_j < n_min)
            {
                min_idx = j;
            }
            else if (n_j == n_min) {
                min_idx = arr[min_idx] < arr[j] ? min_idx : j;
            }
        }
        std::swap(arr[i], arr[min_idx]);
    }
    return arr;
}