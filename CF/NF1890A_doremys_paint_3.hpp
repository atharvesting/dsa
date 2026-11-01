/*
@METADATA
Date:
Problem:
Link:
Source:
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
#include <bits/stdc++.h>
#include <numeric>

using namespace std;

inline void solve() {
    int n{0};
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    if (n <= 2) {
        cout << "Yes\n";
        return;
    }

    set<int> s(v.begin(), v.end());
    auto s_size = s.size();
    if (s_size == 1) {
        cout << "Yes\n";
        return;
    }
    else if (s_size > 2) {
        cout << "No\n";
        return;
    }
    else {
        if ((n & 1) == 0) {
            if (count(v.begin(), v.end(), *s.begin()) == count(v.begin(), v.end(), *(++s.begin())))
                cout << "Yes\n";

        }
        else {
            if (count(v.begin(), v.end(), *s.begin()) == count(v.begin(), v.end(), *(++s.begin())))
        }
    }



    sort(v.begin(), v.end());
    if ((n & 1) == 0) {

    } else {

    }
}

inline void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) solve();
}
