/*
@METADATA
Date: 2026-10-25
Problem: 1853A - Desorting
Link: https://codeforces.com/problemset/problem/1853/A
Source: CF
Pattern: Brute Force, Greedy, Math
Type: Solve
*/
#pragma once
#include <bits/stdc++.h>

using namespace std;

inline void solve()
{
    int n{0};
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int min_distance{INT_MAX};
    for (int i = 1; i < n; i++) {
        auto delta = v[i] - v[i - 1];
        if (delta < 0) {
            cout << 0 << "\n";
            return;
        }
        if (delta < min_distance) {
            min_distance = delta;
        }
    }
    cout << min_distance / 2 + 1 << "\n";
}

inline void solution()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t{0};
    cin >> t;

    while (t--) solve();
}
