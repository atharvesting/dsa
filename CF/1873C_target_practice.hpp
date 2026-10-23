
/*
@METADATA
Date: 2026-10-22
Problem: 1873C - Target Pratice
Link: https://codeforces.com/problemset/problem/1873/C
Source: CF
Pattern: Math
Type: Solve
*/
#pragma once
#include <bits/stdc++.h>

using namespace std;

inline void solve() {
    string s = "";
    string tmp;
    for (int i = 0; i < 10; i++) {
        cin >> tmp;
        s += tmp;
    }
    int score{0};
    for (int i = 0; i < 100; i++) {
        if (s[i] == 'X') {
            int y = i % 10;
            int x = (i - y) / 10;
            score += min({x, y, 9 - x, 9 - y}) + 1;
        }
    }
    cout << score << "\n";
}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) solve();
}
