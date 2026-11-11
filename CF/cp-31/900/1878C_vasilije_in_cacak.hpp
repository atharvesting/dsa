/*
@METADATA
Date: 2026-11-11
Problem: 1878C - Vasilije in Cacak
Link: https://codeforces.com/problemset/problem/1878/C
Source: CF
Pattern: Math
Type: CP-31
*/
#pragma once
#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

inline void solve() {
    ll n{0}, k{0}, x{0}, max_total{0}, min_total{0};
    cin >> n >> k >> x;

    ll m = n - k + 1;
    max_total = ((m + n) * (n - m + 1)) / 2;
    min_total = (k * (k + 1)) / 2;

    if (min_total <= x && x <= max_total) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) solve();
}
