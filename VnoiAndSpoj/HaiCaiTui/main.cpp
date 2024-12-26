#include <iostream>
#include <bits/stdc++.h>
#define MaxN 50
using namespace std;
typedef long double ld;
int t, s, n, f;
ld p;
unordered_map<ld, ld> dp[11];

void Solvef1() {
    for (int cntt = 1; cntt <= t; cntt++) {
        for (int i=1; i<=n; i++) {
            cin >> p;
            if (p >= 0.45) {
                cout << 1 << '\n';
                int a;
                cin >> a;
            }
            else
                cout << 0 << '\n';
        }
    }
}

int main()
{
    cin >> t >> s >> n >> f;
    if (f == 1)
        Solvef1();
    return 0;
}
