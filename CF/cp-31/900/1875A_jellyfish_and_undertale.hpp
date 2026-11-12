/*
@METADATA
Date: 2026-11-12
Problem: 1875A - Jellyfish and Undertale
Link: https://codeforces.com/problemset/problem/1875/A
Source: CF
Pattern: Greedy, Brute Force
Type: CP-31
*/
#pragma once
#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

inline void solve() {
    ll a{0}, b{0}, n{0}, tmp{0}, total{0};
    cin >> a >> b >> n;

    for (ll i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp >= a) {
            tmp = a - 1;
        }
        total += tmp;
    }
    total += b;
    cout << total << "\n";
}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) solve();
}
