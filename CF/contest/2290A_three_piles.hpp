/*
@METADATA
Date: 2026-11-12
Problem: 2290A - Three Piles
Link: https://codeforces.com/contest/2290/problem/A
Source: CF
Pattern: Implementation, Math
Type: Contest
*/
#pragma once
#include <bits/stdc++.h>

using namespace std;

inline void solve() {
    int a{0}, b{0}, c{0};
    cin >> a >> b >> c;

    if (c - a == 2 && a != b && c != b)
        cout << "YES\n";
    else
        cout << "NO\n";
}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) solve();
}
