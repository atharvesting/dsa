#pragma once
// 4A - Watermelon
#include <iostream>

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int input;
    if (!(std::cin >> input)) return;
    if ((input & 1) == 0 && input != 2)
        std::cout << "YES";
    else
        std::cout << "NO";
}
