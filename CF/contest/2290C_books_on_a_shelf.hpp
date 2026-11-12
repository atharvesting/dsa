/*
@METADATA
Date:
Problem:
Link:
Source: CF
Pattern:
Type: CP-31/Solve/Contest
*/
#pragma once
#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <iterator>

using namespace std;

inline void solve() {
    int n{0}, tmp{0};
    cin >> n;
    vector<int> v, rv;
    cin >> tmp;
    v.push_back(tmp);
    map<int, int> m;

    for (int i = 1; i < n; i++) {
        cin >> tmp;
        if (find(v.begin(), v.end(), tmp) != v.end()) {
            v.push_back(tmp);
        }
        else {
            rv.push_back(tmp);
        }
    }
    if (rv.empty()) {
        cout << v.size() << "\n";
        for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
        cout << "\n";
        return;
    }
    sort(v.begin(), v.end());
    sort(rv.begin(), rv.end(), greater<>());
    auto last = unique(v.begin(), v.end());
    int count = distance(v.begin(), last);
    last = unique(rv.begin(), rv.end());
    count += distance(rv.begin(), last);
    if (*(v.end() - 1) == *rv.begin()) {
        count--;
    }
    cout << count << "\n";
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    for (int i = 0; i < rv.size(); i++) cout << rv[i] << " ";
    cout << "\n";
    // sort(v.begin(), v.end());
    // list l(v.begin(), v.end());
    // for (const auto &n : l) {
    //     if (m[n] > 1) {
    //         auto tmp = n;
    //         l.remove(const int &value)
    //     }
    // }

}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) solve();
}
