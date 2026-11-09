/*
@METADATA
Date: 2026-11-09
Problem: 1761 - Two Permutations
Link: https://codeforces.com/problemset/problem/1761/A
Source: CF
Pattern: Brute Force, Constructive Algorithms
Type: CP-31
*/
#pragma once
#include <bits/stdc++.h>

using namespace std;

inline void solve() {
    int n{0}, a{0}, b{0};
    cin >> n >> a >> b;

    if (n == a && n == b) {
        cout << "Yes\n";
        return;
    }

    int lb = a - 1;
    int rb = n - 1 - b;
    if (rb <= lb) {
        cout << "No\n";
        return;
    }
    int elements_between = rb - lb;

    if (elements_between == 1) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) solve();
}
