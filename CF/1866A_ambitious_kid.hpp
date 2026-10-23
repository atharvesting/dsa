/*
@METADATA
Date: 2026-10-23
Problem: 1866A - Ambitious Kid
Link: https://codeforces.com/problemset/problem/1866/A
Source: CF
Pattern: Math
Type: Solve
*/
#pragma once
#include <bits/stdc++.h>
#include <climits>

using namespace std;

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    int closest = INT_MAX, tmp;
    for (int i = 0; i < t; i++) {
        cin >> tmp;
        if (tmp == 0) {
            closest = 0;
            break;
        }
        if (abs(tmp) < closest) {
            closest = abs(tmp);
        }
    }
    cout << closest;
}
