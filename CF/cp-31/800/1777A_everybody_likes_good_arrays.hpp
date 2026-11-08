/*
@METADATA
Date: 2026-11-08
Problem: 1777A - Everybody Likes Good Arrays
Link: https://codeforces.com/problemset/problem/1777/A
Source: CF
Pattern: Greedy, Math
Type: CP-31
*/
#pragma once
#include <bits/stdc++.h>

using namespace std;

inline void solve() {
    int n{0}, tmp{0}, counter{1}, ops{0};
    cin >> n >> tmp;
    int even{0};
    even = (tmp & 1) == 0 ? 0 : 1;
    for (int i = 1; i < n; i++) {
        cin >> tmp;
        if ((tmp & 1) == even) {
            counter++;
        }
        else {
            ops += counter - 1;
            even = tmp & 1;
            counter = 1;
        }
    }
    ops += counter - 1;
    cout << ops << "\n";
}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) solve();
}
