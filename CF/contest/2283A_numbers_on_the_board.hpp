/*
@METADATA
Date: 2026-11-04
Problem: 2283A - Numbers on the Board
Link: https://codeforces.com/problemset/problem/2283/A
Source: CF
Pattern: Greedy, Math, Two Pointers
Type: Contest
*/
#pragma once
#include <bits/stdc++.h>

using namespace std;

inline void solve() {
    int l{0}, r{0};
    cin >> l >> r;
    if ((l > 0 && r > 0) || (l < 0 && r < 0)) {
        cout << abs(r - l) << "\n";
        return;
    }
    if (r - l == 0) {
        cout << 0 << "\n";
        return;
    }
    if (l == 0 || r == 0) {
        cout << abs(r - l) - 1 << "\n";
        return;
    }

    int total{0};
    for (int i = l; i <= r; i++) {
        total += i;
    }

    if (total == 0) {
        cout << 0 << "\n";
        return;
    }

    if (l <= total && total <= r) {
        cout << 0 << "\n";
        return;
    }

    if (abs(l) > r) {
        cout << -(r + 1) - l << "\n";
    }
    else {
        cout << r + (l - 1) << "\n";
    }
}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) solve();
}
