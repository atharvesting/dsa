/*
@METADATA
Date:
Problem:
Link:
Source:
Pattern:
Type: Solve

@JOURNEY


@ITERATION_FAILED
Method:
Why:

@ITERATION_SUCCESS
Method:
Complexity:
Why:
*/
#pragma once
#include <bits/stdc++.h>

using namespace std;

inline void solve() {
    int n{0};
    cin >> n;
    string s;
    cin >> s;

    int l{0}, r{n - 1};
    while (l < r) {
        if (s[l] == s[r])
            break;
        l++; r--;
    }
    cout << r - l + 1 << "\n";
}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) solve();
}
