/*
@METADATA
Date: 2026-11-01
Problem: 1834A - Unit Array
Link: https://codeforces.com/problemset/problem/1834/A
Source: CF
Pattern: Math, Greedy
Type: CP-31
*/
#pragma once
#include <bits/stdc++.h>
#include <functional>
#include <numeric>

using namespace std;

inline void solve1() {
    int n{0};
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    auto total = accumulate(v.begin(), v.end(), 0);
    auto minus_count = count(v.begin(), v.end(), -1);
    int steps{0};

    if (total >= 0) {
        if (minus_count % 2 != 0) {
            steps++;
        }
    } else {
        steps += -total / 2;
        if (minus_count - steps % 2 != 0) {
            steps++;
        }
    }
    cout << steps << "\n";
}

inline void solve2() {
    int n{0};
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int steps{0};

    while ( (accumulate(v.begin(), v.end(), 0) < 0) || (accumulate(v.begin(), v.end(), 1, multiplies<int>()) != 1) )
    {
        auto it = find(v.begin(), v.end(), -1);
        if (it == v.end())
            break;
        *it = 1;
        steps++;
    }
    // for (int i = 0; i < n; i++) cout << v[i] << " ";
    cout << steps << "\n";
}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t{0};
    cin >> t;

    while (t--) solve2();
}
