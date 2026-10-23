/*
@METADATA
Date: 2026-10-19
Problem: 1877A - Goals of Victory
Link: https://codeforces.com/problemset/problem/1877/A
Source: CF
Pattern: Math
Type: Solve
*/
#pragma once
#include <bits/stdc++.h>
#include <numeric>

using namespace std;

inline void solve() {
    int n{0};
    cin >> n;
    vector<int> v(n - 1);
    for (int i = 0; i < n - 1; i++) cin >> v[i];

    auto missing_e = 0 - accumulate(v.begin(), v.end(), 0);
    cout << missing_e << "\n";
}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) solve();
}
