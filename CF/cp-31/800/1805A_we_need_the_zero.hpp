/*
@METADATA
Date: 2026-11-02
Problem: 1805A - We Need the Zero
Link: https://codeforces.com/problemset/problem/1805/A
Source: CF
Pattern: Bitmask, Brute force
Type: CP-31
*/
#pragma once
#include <bits/stdc++.h>

using namespace std;

inline void solve() {
    int n{0};
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int tmp{0};

    for (int i = 0; i < n; i++) {
        tmp ^= v[i];
    }

    if ((n & 1) != 1) {
        if (tmp == 0)
            tmp = 1;
        else
            tmp = -1;
    }
    cout << tmp << "\n";

}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) solve();
}
