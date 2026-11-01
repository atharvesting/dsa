#pragma once
#include <bits/stdc++.h>

using namespace std;

inline void solve()
{
    int n{0}, k{0}, x{0};
    cin >> n >> k >> x;

    if (x != 1) {
        cout << "YES\n" << n << "\n";
        for (int i = 0; i < n; i++) cout << 1 << " ";
        cout << "\n";
        return;
    }
    for (int i = 1; i < k + 1; i++) {
        if (i == x) continue;
        if (n % i == 0) {
            cout << "YES\n" << n / i << "\n";
            for (int j = 0; j < n / i; j++) cout << i << " ";
            cout << "\n";
            return;
        } else if (n % i != x) {
            cout << "YES\n" << (n / i) + 1 << "\n";
            for (int j = 0; j < n / i; j++) cout << i << " ";
            cout << n % i << "\n";
            return;
        }
    }
    cout << "NO\n";
}

inline void solution()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t{0};
    cin >> t;

    while (t--) solve();
}
