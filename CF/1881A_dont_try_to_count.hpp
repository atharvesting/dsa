/*
@METADATA
Date: 2026-10-18
Problem: 1881A - Don't Try to Count
Link: https://codeforces.com/contest/1881/problem/A
Source: CF
Pattern: Brute Force
Type: Solve
*/
#pragma once
#include <bits/stdc++.h>

using namespace std;

inline void solve() {
    int n{0}, m{0};
    cin >> n >> m;
    string to_modify, to_match;
    cin >> to_modify >> to_match;

    if (to_modify.find(to_match) != to_modify.npos) {
        cout << 0 << "\n";
        return;
    }
    int count{0};
    if (to_match.size() < to_modify.size()) {
        to_modify += to_modify;
        count++;
        if (to_modify.find(to_match) != to_modify.npos) {
            cout << count << "\n";
            return;
        }
    }
    while (2 * to_match.size() >= to_modify.size()) {
        to_modify += to_modify;
        // cout << "After op: " << to_modify << "\n";
        count++;
        if (to_modify.find(to_match) != to_modify.npos) {
            cout << count << "\n";
            return;
        }
    }
    cout << -1 << "\n";

}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) solve();
}
