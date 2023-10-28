#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int k;

void Solve() {
    int cs = 1;
    long long e2 = 2, dem = 0;
    while (dem + e2 < k) {
        dem = dem + e2;
        cs++;
        e2 = e2*2;
    }
    k = k-dem;
    e2 = e2/2;
    while (e2>0) {
        if (k<=e2) {
            cout << 4;
        }
        else {
            cout << 7;
            k = (k-1)%e2 + 1;
        }
        e2 = e2/2;
    }
}

int main()
{
    freopen("LUCKY.INP", "r", stdin);
    freopen("LUCKY.OUT", "w", stdout);
    cin >> k;
    Solve();
    return 0;
}
