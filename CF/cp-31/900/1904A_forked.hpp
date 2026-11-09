/*
@METADATA
Date: 2026-11-09
Problem: 1904A - Forked!
Link: https://codeforces.com/problemset/problem/1904/A
Source: CF
Pattern: Brute Force, Implementation
Type: CP-31
*/
#pragma once
#include <bits/stdc++.h>

using namespace std;

inline void solve() { // ABORTED
    struct Point {
        int x;
        int y;

        Point(int x, int y) : x(x), y(y) {}
    };

    int a{0}, b{0};
    cin >> a >> b;

    auto king = Point(0, 0);
    cin >> king.x >> king.y;

    auto queen = Point(0, 0);
    cin >> queen.x >> queen.y;

    int distance{0};

    if (king.x == queen.x) {
        distance = abs(queen.y - king.y) - 1;
        if (distance == 2 * a + 1 - 2 || distance == 2 * b + 1 - 2) {
            cout << 2;
        }
        else {
            cout << 0;
        }
        cout << "\n";
    }
    else if (king.y == queen.y) {
        distance = abs(queen.x - king.x) - 1;
        if (distance == 2 * a + 1 - 2 || distance == 2 * b + 1 - 2) {
            cout << 2;
        }
        else {
            cout << 0;
        }
        cout << "\n";
    }
    else {
        cout << -1 << "\n";
    }
}

inline void solve2() {
    struct Point {
        int x;
        int y;

        Point(int x, int y) : x(x), y(y) {}
    };

    int a{0}, b{0};
    cin >> a >> b;

    auto king = Point(0, 0);
    cin >> king.x >> king.y;

    auto queen = Point(0, 0);
    cin >> queen.x >> queen.y;

    set<pair<int, int>> king_points;
    set<pair<int, int>> queen_points;

    set<pair<int, int>> moves = {{a, b}, {-a, -b}, {a, -b}, {-a, b}, {b, a}, {-b, -a}, {b, -a}, {-b, a}};

    for (const auto& [a, b] : moves) {
        king_points.emplace(king.x + a, king.y + b);
        queen_points.emplace(queen.x + a, queen.y + b);
    }

    int count{0};

    for (const auto& p : king_points) {
        if (queen_points.find(p) != queen_points.end()) {
            count++;
        }
    }
    cout << count << "\n";
}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) solve2();
}
