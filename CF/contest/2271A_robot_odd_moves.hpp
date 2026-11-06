/*
@METADATA
Date: 2026-10-10
Problem: 2271A - Robot Odd Moves
Link: https://codeforces.com/contest/2271/problem/A
Source: CF
Pattern: Constructive Algorithms
Type: Contest
*/
#pragma once
#include <iostream>
#include <cmath>

struct Coord {
    int x;
    int y;
};

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Coord c = {0, 0};

    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> c.x;
        std::cin >> c.y;

        if (c.x >= 0 && (std::abs(c.y) <= c.x + 1))
        {
            int y_steps = std::abs(c.y);
            int x_steps = c.x - y_steps;
            if ((x_steps & 1) == 1)
                x_steps++;

            std::cout << y_steps + x_steps << "\n";
        }
        else {
            std::cout << -1 << "\n";
        }

    }
}
