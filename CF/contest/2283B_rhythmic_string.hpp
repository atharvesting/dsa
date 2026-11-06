/*
@METADATA
Date: 2026-11-04
Problem: 2283B - Rhythmic String
Link: https://codeforces.com/contest/2283/problem/B
Source: CF
Pattern: Brute Force, Number Theory
Type: Contest
*/
#pragma once
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

inline void solve() {
    // Constructing the binary string is likely irrelevant.
    // The goal of this problem seems to be to find the biggest possible subset
    //      where the gcd lies in the same subset.

    ll n{0};
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) cin >> v[i];

    map<int, int> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[j] % v[i] == 0) {
                m[i]++;
            }
        }
    }

    auto max_entry = max_element(m.begin(), m.end(),
        [](const auto& a, const auto& b) {
            return a.second < b.second;
        });

    cout << n - max_entry->second << "\n";
}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) solve();
}
