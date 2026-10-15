/*
@METADATA
Date:
Problem:
Link:
Source:
Pattern:
Type: Solve

First iter: Failed
Second iter: TLE
*/
#pragma once
#include <bits/stdc++.h>
#include <numeric>
#include <vector>

using namespace std;

inline bool process_subarray(int kPlusN,
                             vector<int>::const_iterator start,
                             vector<int>::const_iterator stop)
{
    if (accumulate(start, stop, 0LL) % kPlusN == 0) return true;
    else return false;
}

inline void solve() {
    int n{0}, k{0};
    cin >> n >> k;

    if (k >= n) {
        cout << 0 << "\n";
        return;
    }

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int l{k + 1}, i{0};
    long long counter{0};

    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + v[i];
    }

    while (l <= n)
    {
        if (l + i > v.size()) {
            i = 0;
            l++;
            continue;
        }

        if ((prefix[i + l] - prefix[i]) % k == 0) {
            // traverse_subvector<int>(v.begin() + i, v.begin() + l + i);
            counter++;
        }
        i++;
    }
    cout << counter << "\n";
}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) solve();
}
