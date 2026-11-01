/*
@METADATA
Date: 2026-10-25
Problem: 1857A - Array Coloring
Link: https://codeforces.com/problemset/problem/1857/A
Source: CF
Pattern: Greedy, Math
Type: Solve
*/
#pragma once
#include <bits/stdc++.h>
#include <numeric>

using namespace std;

inline void solve()
{
    int n{0};
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    auto total = accumulate(v.begin(), v.end(), 0);
    if ((total & 1) == 1) cout << "NO\n";
    else cout << "YES\n";
}

inline void solution()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t{0};
    cin >> t;

    while (t--) solve();
}
