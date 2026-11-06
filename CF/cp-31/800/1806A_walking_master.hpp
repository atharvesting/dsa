/*
@METADATA
Date: 2026-11-01
Problem: 1806A - Walking Master
Link: https://codeforces.com/problemset/problem/1806/A
Source: CF
Pattern: Geometry, Math, Greedy
Type: CP-31
*/
#pragma once
#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

inline void solve() {
    ll a{0}, b{0}, c{0}, d{0};
    cin >> a >> b >> c >> d;
    auto vertical = d - b;
    if (vertical < 0) {
        cout << -1 << "\n";
        return;
    }
    a += vertical;
    auto horizontal = c - a;
    if (horizontal > 0)
        cout << -1 << "\n";
    else
        cout << abs(vertical) + abs(horizontal) << "\n";
}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) solve();
}
