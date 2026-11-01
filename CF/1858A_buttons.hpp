/*
@METADATA
Date: 2026-10-25
Problem: 1858A - Buttons
Link: https://codeforces.com/problemset/problem/1858/A
Source: CF
Pattern: Greedy, Math
Type: Solve
*/
#pragma once
#include <bits/stdc++.h>

using namespace std;

inline void solve() {
    int a{0}, b{0}, c{0}, half{0};
    cin >> a >> b >> c;

    if ((c & 1) == 1) half = (c + 1) / 2;
    else half = c / 2;

    a += half;
    c -= half;
    b += c;

    if (a > b) cout << "First\n";
    else cout << "Second\n";
}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t{0};
    cin >> t;
    while (t--) solve();
}
