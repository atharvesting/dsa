/*
@METADATA
Date: 2026-10-24
Problem: 1862B - Sequence Game
Link: https://codeforces.com/problemset/problem/1862/B
Source: CF
Pattern: Constructive Algorithm
Type: Solve
*/
#pragma once
#include <bits/stdc++.h>

using namespace std;

inline void solve() {
    int n{0};
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<int> b;
    b.reserve(n*2);
    b.push_back(v[0]);

    // case 1: v[i] > v[i - 1]
        // do nothing
    // case 2: v[i] == v[i - 1]
        // do nothing
    // case 3: v[i] < v[i - 1]
        // add a number smaller than v[i - 1]

    for (int i = 1; i < n; i++) {
        if (v[i] < v[i - 1]) {
            b.push_back(1);
        }
        b.push_back(v[i]);
    }

    auto b_size = b.size();
    cout << b_size << "\n";
    for (int i = 0; i < b_size; i++) {
        cout << b[i] << " ";
    }
    cout << "\n";

}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) solve();
}
