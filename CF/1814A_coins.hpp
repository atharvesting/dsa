/*
@METADATA
Date: 2026-11-01
Problem: 1814A - Coins
Link: https://codeforces.com/problemset/problem/1814/A
Source: CF
Pattern: Implementation, Math
Type: Solve
*/
#pragma once
#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

inline void solve() {
    ll n{0}, k{0};
    cin >> n >> k;

    if ((n & 1) == 0) {
        cout << "YES\n";
        return;
    }
    if (((n - k) & 1) == 0) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t{0};
    cin >> t;

    while (t--) solve();
}
