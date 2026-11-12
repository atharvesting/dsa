/*
@METADATA
Date: 
Problem:
Link:
Source: CF
Pattern:
Type: CP-31/Solve/Contest
*/
#pragma once
#include <bits/stdc++.h>

using namespace std;

inline void solve() {
    int k{0};
    cin >> k;

    vector<int> v(k);
    for (int i = 0; i < k; i++) cin >> v[i];

    vector<int> p(k);
    p[0] = v[0];
    for (int i = 1; i < k; i++) {
        p[i] = p[i - 1] ^ v[i];
    }
    for (int i = 0; i < k; i++) {
        cout << p[i] << " ";
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
