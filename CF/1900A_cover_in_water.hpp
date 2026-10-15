/*
@METADATA
Date: 2026-10-13
Problem: 1900A - Cover in Water
Link: https://codeforces.com/problemset/problem/1900/A
Source: CF
Pattern: Greedy
Type: Solve
*/
#pragma once
#include <bits/stdc++.h>

using namespace std;

inline void solve() {
    int n;
    string s;
    std::cin >> n >> s;

    if (s.find(".") == s.npos) {
        std::cout << 0 << "\n";
        return;
    }

    int ops = s.find("...") != s.npos
              ? 2
              : std::count(s.begin(), s.end(), '.');

    std::cout << ops << "\n";
}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) solve();
}
