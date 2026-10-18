/*
@METADATA
Date: 2026-10-18
Problem: 1878A - How Much Does Daytona Cost?
Link: https://codeforces.com/contest/1878/problem/A
Source: CF
Pattern: Greedy
Type: Solve
*/
#pragma once
#include <bits/stdc++.h>

using namespace std;

inline void solve() {
    int n{0}, k{0};
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    if (find(v.begin(), v.end(), k) != v.end()) cout << "YES\n";
    else cout << "NO\n";
}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) solve();
}
