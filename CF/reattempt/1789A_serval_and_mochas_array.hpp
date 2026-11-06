/*
@METADATA
Date: 2026-11-06
Problem: 1789A - Serval and Mocha's Array
Link: https://codeforces.com/problemset/problem/1789/A
Source: CF
Pattern: Brute Force, Math, Number Theory
Type: CP-31
*/
#pragma once
#include <bits/stdc++.h>
#include <numeric>

using namespace std;
using ll = long long int;

inline void solve() {
    int n{0};
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    auto total = accumulate(v.begin(), v.end(), 0LL);

    int gcd = 1;

    for (int i = n; i > 0; i--) {
        if (total % i == 0) {
            gcd = i;
            break;
        }
    }

    cout << gcd << "\n";
}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) solve();
}
