#pragma once
#include <bits/stdc++.h>

using namespace std;

inline void solve()
{
    int n{0};
    cin >> n;
    // vector<int> v(n);
    // for (int i = 0; i < n; i++) cin >> v[i];

    string r1, r2;
    cin >> r1 >> r2;

    auto fr1_count = count(r1.begin(), r1.end(), 'f');
    auto fr2_count = count(r2.begin(), r2.end(), 'f');

    // cout << fr1_count << " " << fr2_count << "\n";

    if (fr1_count == fr2_count) {
        cout << 0 << "\n";
        return;
    }

    int pairs{0}, iso1{0}, iso2{0};
    for (int i = 0; i < r1.length();)
    {
        // cout << r1[i] << " " << r2[i] << "\n";
        if (r1[i] == 'f') {
            if (r2[i] == 'f') {
                pairs++;
                i++;
            }
            else {
                if (i != r1.length() - 1 && r1[i + 1] == 'f' && r2[i + 1] != 'f') {
                    pairs++;
                    i += 2;
                }
                else {
                    iso1++;
                    i++;
                }
            }
        }
        else {
            if (i != r1.length() - 1 && r2[i + 1] == 'f' && r1[i + 1] != 'f') {
                pairs++;
                i += 2;
            }
            else {
                iso2++;
                i++;
            }
        }
    }
    auto min_iso = min({iso1, iso2});

    auto removes = (fr1_count + fr2_count) - (2 * pairs) - abs(iso1 - iso2); //
    cout << removes << "\n";
    // total number of f's - (2 * pairs of f's (vertical or horizontal))
}

inline void solution()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t{0};
    cin >> t;

    while (t--) solve();
}
