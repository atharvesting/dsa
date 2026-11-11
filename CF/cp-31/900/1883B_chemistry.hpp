/*
@METADATA
Date: 2026-11-11
Problem: 1883B - Chemistry
Link: https://codeforces.com/problemset/problem/1883/B
Source: CF
Pattern: Strings
Type: CP-31
*/
#pragma once
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

inline void solve() {
    int n{0}, k{0};
    cin >> n >> k;
    string s;
    cin >> s;
    unordered_map<char, int> m;

    for (const auto& c : s) {
        m[c]++;
    }

    int odd_count{0};
    for (const auto& [c, count] : m) {
        if ((count & 1) == 1) {
            odd_count++;
        }
    }
    if (odd_count > k + 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) solve();
}
