/*
@METADATA
Date: 2026-10-31
Problem: 1837A - Grasshopper on a Line
Link: https://codeforces.com/problemset/problem/1837/A
Source: CF
Pattern: Math, Greedy
Type: CP-31
*/
#pragma once
#include <bits/stdc++.h>

using namespace std;

inline void solve() {
    int x{0}, k{0};
    cin >> x >> k;

    if (x % k != 0)
        cout << 1 << "\n" << x << "\n";
    else
        cout << 2 << "\n" << x + 1 << " " << -1 << "\n";
}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t{0};
    cin >> t;

    while (t--) solve();
}
