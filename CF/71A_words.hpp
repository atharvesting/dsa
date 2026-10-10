#pragma once
// 71A - Way Too Long Words - https://codeforces.com/problemset/problem/71/A
#include <iostream>
#include <vector>
#include <string>

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    if (!(std::cin >> n)) return;
    std::vector<std::string> words;
    std::string tmp;
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        words.push_back(tmp);
    }
    for (int i = 0; i < n; i++) {
        auto s = words[i];
        if (s.length() > 10) {
            std::cout << s.front() << (s.length() - 2) << s.back();
        } else {
            std::cout << s;
        }
        if (i + 1 < n) std::cout << '\n';
    }
}
