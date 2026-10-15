/*
@METADATA
Date:
Problem:
Link:
Source:
Pattern:
Type: Solve
*/
#pragma once
#include <bits/stdc++.h>

using namespace std;

inline void solve() {
    int c{0}, s{0}, res{0};
    cin >> c >> s;

    if (s >= c)
        res = -1;

    else if (c >= 2 * s)
        res = s;

    else { // 2*s > c > s
        res = c - s;
    }

    cout << res << "\n";
}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) solve();
}
