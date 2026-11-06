/*
@METADATA
Date: 2026-11-06
Problem: 1788A - One and Two
Link: https://codeforces.com/problemset/problem/1788/A
Source: CF
Pattern: Brute Force, Math
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

    auto two_count = count(v.begin(), v.end(), 2);

    if (two_count == 0) {
        cout << 1 << "\n";
        return;
    }

    if ((two_count & 1) == 1) {
        cout << -1 << "\n";
        return;
    }
    int nth = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == 2) {
            nth++;
            if (nth == two_count / 2) {
                cout << i + 1 << "\n";
                return;
            }
        }
    }
}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) solve();
}
