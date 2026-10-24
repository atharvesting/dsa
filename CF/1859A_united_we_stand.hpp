/*
@METADATA
Date: 2026-10-24
Problem: 1859 - United We Stand
Link: https://codeforces.com/problemset/problem/1859/A
Source: CF
Pattern: Math, Number Theory
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

    sort(v.begin(), v.end());
    if (*v.begin() == *(v.end() - 1)) {
        cout << -1 << "\n";
        return;
    }
    auto count_max = count(v.begin(), v.end(), v[n - 1]);
    cout << v.size() - count_max << " " << count_max << "\n";

    for (int i = 0; i < n - count_max; i++) cout << v[i] << " ";
    cout << "\n";

    for (int i = n - count_max; i < n; i++) cout << v[i] << " ";
    cout << "\n";
}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) solve();
}
