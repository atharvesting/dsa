/*
@METADATA
Date: 2026-11-01
Problem: 1829B - Blank Space
Link: https://codeforces.com/problemset/problem/1829/B
Source: CF
Pattern: Implementation
Type: Solve
*/
#pragma once
#include <bits/stdc++.h>

using namespace std;

inline void solve() {
    int n{0}, tmp{0}, lgth{0}, longest{0};
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp == 0) {
            lgth++;
            if (lgth > longest) {
                longest = lgth;
            }
        }
        else lgth = 0;
    }
    cout << longest << "\n";
}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t{0};
    cin >> t;

    while (t--) solve();
}
