/*
@METADATA
Date: 2026-11-08
Problem: 1766 - Extremely Round
Link: https://codeforces.com/problemset/problem/1766/A
Source: CF
Pattern: Brute Force, Implementation
Type: CP-31
*/
#pragma once
#include <bits/stdc++.h>

using namespace std;

inline int countDigitsTree(uint32_t x) {
    if (x < 10) return 1;
    if (x < 100) return 2;
    if (x < 1000) return 3;
    if (x < 10000) return 4;
    if (x < 100000) return 5;
    if (x < 1000000) return 6;
    if (x < 10000000) return 7;
    if (x < 100000000) return 8;
    if (x < 1000000000) return 9;
    return 10;
}

inline void solve() {
    int n{0};
    cin >> n;
    int state = 1, adder = 1, count = 0, prev_len = 1;

    while (state <= n) {
        count++;
        auto len = countDigitsTree(state);
        if (len > prev_len) {
            prev_len = len;
            adder *= 10;
        }
        state += adder;
    }
    cout << count << "\n";
}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) solve();
}
