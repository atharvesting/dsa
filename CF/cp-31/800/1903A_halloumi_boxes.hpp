/*
@METADATA
Date: 2026-10-11
Problem: 1903A - Halloumi Boxes
Link: https://codeforces.com/problemset/problem/1903/A
Source: CF
Pattern: Brute Force, Greedy
Type: CP-31
*/
#pragma once
#include <bits/stdc++.h>

inline void solve() {
    int n{0}, k{0};
    std::cin >> n; std::cin >> k;
    if (k >= 2) {
        // We can already conclude that the array can be sorted
        //  since k = 2 performs a swap and bubble sort can be performed.
        std::cout << "YES\n";
        return;
    }
    int tmp;
    bool increasing = true, decreasing = true;
    std::vector<int> v;
    v.resize(n, 0);

    // At this point, k = 1.
    // This traversal is necessary to establish whether the array is already sorted.
    // By tracking increasing and descreasing flags, we only need one pass to determine
    //  whether the array is sorted (ascending or descending)
    for (int i = 0; i < n; i++)
    {
        std::cin >> tmp;
        v[i] = tmp;
        if (i == 0) continue;
        if (v[i - 1] > v[i]) increasing = false;
        if (v[i - 1] < v[i]) decreasing = false;
    }
    if (increasing && decreasing) std::cout << "YES\n";
    else if (increasing) std::cout << "YES\n";
    else std::cout << "NO\n";
}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) solve();
}
