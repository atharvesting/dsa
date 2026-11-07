/*
@METADATA
Date: 2026-10-12
Problem: 1901A - Line Trip
Link: https://codeforces.com/problemset/problem/1901/A
Source: CF
Pattern: Greedy, Math
Type: CP-31
*/
#pragma once
// #include "my_utils.hpp"
#include <bits/stdc++.h>

inline void solve() {
    // The premise of this problem is simple enough.
    // To find: The maximum distance the car goes without encountering a gas station
    // I initially tried to simulate the trip and find the maximum distance greedily
    // This required two loops: to and from the destination.

    // It became obvious that there was a much better and concise way to find the max
    // distance, and it simply involves iterating through the gas station indices and
    // finding the max distance between them.
    // The distance between the last gas station, end point, and back to that station is
    //  handled by a deterministic calculation before the loop altogether. The loop then only
    //  needs to address till the second to last gas station.
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
                distance = 0;
        }
    }
    std::cout << max_distance_bw_gas << "\n";
}

inline void solve2() {
    // This is the better approach to the problem. However, things can be optimised further
    //  by eliminating vector allocation altogether and process distances on a streaming basis.
    int n{0}, x{0};
    std::cin >> n >> x;
    std::vector<int> v(n + 1, 0);
    for (int i = 1; i < n + 1; i++) std::cin >> v[i];

    auto max_distance = 2 * (x - v[n]);

    for (int i = 0; i < n; i++) {
        auto distance = v[i + 1] - v[i];
        if (distance > max_distance)
            max_distance = distance;
    }
    std::cout << max_distance << "\n";
}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) solve2();
}
