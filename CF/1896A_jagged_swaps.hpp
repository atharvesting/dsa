/*
@METADATA
Date: 2026-10-15
Problem: 1896A - Jagged Edges
Link: https://codeforces.com/problemset/problem/1896/A
Source: CF
Pattern: Sorting
Type: Solve
*/
#pragma once
#include <bits/stdc++.h>

using namespace std;

inline void solve() {
    int n{0};
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    // The first element is immovable. The rest will always find their place
    if (v[0] != 1) cout << "NO\n";
    else cout << "YES\n";
}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) solve();
}
