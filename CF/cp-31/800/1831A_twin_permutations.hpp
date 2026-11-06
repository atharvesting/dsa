/*
@METADATA
Date: 2026-11-01
Problem: 1831A - Twin Permutations
Link: https://codeforces.com/problemset/problem/1831/A
Source: CF
Pattern: Constructive Algorithms
Type: CP-31
*/
#pragma once
#include <bits/stdc++.h>

using namespace std;

inline void solve() {
    int n{0}, tmp{0};
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v[i] = n + 1 - tmp;
    }
    for (int i = 0; i < n; i++) cout << v[i] << " ";
    cout << "\n";
}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t{0};
    cin >> t;

    while (t--) solve();
}
