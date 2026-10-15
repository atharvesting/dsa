/*
@METADATA
Date: 2026-10-12
Problem: 1901A - Line Tracker
Link: https://codeforces.com/problemset/problem/1901/A
Source: CF
Pattern: Greedy, Math
Type: Solve
*/
#pragma once
// #include "my_utils.hpp"
#include <bits/stdc++.h>

inline void solve() {
    int num_gas_stations{0}, end_point{0};
    std::cin >> num_gas_stations >> end_point;
    std::vector<int> v(num_gas_stations);
    int max_distance_bw_gas{-1}, distance{0}, gas_idx{0};

    for (int i = 0; i < num_gas_stations; i++)
        std::cin >> v[i];

    for (int i = 1; i < end_point; i++)
    {
        distance++;
        if (i == v[gas_idx]) {
            if (gas_idx < v.size() - 1) gas_idx++;
            if (distance > max_distance_bw_gas)
                max_distance_bw_gas = distance;
            distance = 0;
        }
    }
    gas_idx = num_gas_stations - 1;
    for (int i = end_point; i >= 0; i--)
    {
        distance++;
        if (i == v[gas_idx]) {
            if (gas_idx > 0) gas_idx--;
            if (distance > max_distance_bw_gas)
                max_distance_bw_gas = distance;
            distance = 0;
        }
    }
    std::cout << max_distance_bw_gas << "\n";
}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) solve();
}
