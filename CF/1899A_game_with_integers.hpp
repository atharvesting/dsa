/*
@METADATA
Date: 2026-10-14
Problem: 1899A - Game with Integers
Link: https://codeforces.com/problemset/problem/1899/A
Source: CF
Pattern: Math, Number Theory
Type: Solve
*/
#pragma once
#include <bits/stdc++.h>

using namespace std;

inline void solve() {
    int n{0};
    std::cin >> n;
    if (n % 3 == 0) std::cout << "Second\n";
    else std::cout << "First\n";
}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) solve();
}
