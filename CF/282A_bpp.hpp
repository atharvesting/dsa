/*
@METADATA
Date: 2026-10-10
Problem: 282A - Bit++
Link: https://codeforces.com/problemset/problem/282/A
Source: CF
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
// #include <bits/stdc++.h>
#include <iostream>
#include <string>


inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n{0}, x{0};
    std::string tmp;

    std::cin >> n;

    while (n--)
    {
        std::cin >> tmp;
        if (tmp.find("+") != std::string::npos)
            x++;
        else if (tmp.find("-") != std::string::npos)
            x--;
    }
    std::cout << x;
}
