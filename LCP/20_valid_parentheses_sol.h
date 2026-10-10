#pragma once
// Example: adapting an existing LCP function-library header to the
// solution() contract via a thin wrapper.
// The underlying logic stays in validParantheses.h (brute_force/optimal);
// this file only provides the required entry point.
#include "LCP/validParantheses.h"
#include <iostream>
#include <string>

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s;
    if (!(std::cin >> s)) return;
    std::cout << (optimal(s) ? "true" : "false");
}
