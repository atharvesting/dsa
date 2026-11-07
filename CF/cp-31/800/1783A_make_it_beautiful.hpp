/*
@METADATA
Date: 2026-11-07
Problem: 1783A - Make it Beautiful
Link: https://codeforces.com/problemset/problem/1783/A
Source: CF
Pattern: Math, Sortings
Type: CP-31
*/
#pragma once
#include <bits/stdc++.h>

using namespace std;

inline void solve() {
    int n{0};
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end(), greater<>());

    if (*v.begin() == *(v.end() - 1)) {
        cout << "NO\n";
    }
    else if (v[0] == v[1]) {
        if (n == 2)
            cout << "NO\n";
        else {
            for (int i = 0; i < n; i++) {
                if (v[i] != v[1]) {
                    swap(v[1], v[i]);
                    cout << "YES\n";
                    for (int i = 0; i < n; i++) cout << v[i] << " ";
                    cout << "\n";
                    break;
                }
            }
        }
    }
    else {
        cout << "YES\n";
        for (int i = 0; i < n; i++) cout << v[i] << " ";
        cout << "\n";
    }
}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) solve();
}
