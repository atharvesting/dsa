/*
@METADATA
Date: 2026-11-12
Problem: 2290B - Stubborn Pen
Link: https://codeforces.com/contest/2290/problem/B
Source: CF
Pattern: Implementation, Strings
Type: Contest
*/
#pragma once
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

inline void solve() {
    int n{0};
    cin >> n;
    string s;
    cin >> s;
    int count = 0;
    char current = 'R';
    unordered_map<char, char> m = {{'R', 'B'}, {'B', 'R'}};

    for (int i = 0; i < n; i++) {
        if (current != s[i]) {
            count++;
            current = m[s[i]];
        }
        else {
            current = m[current];
        }
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
