#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MaxN 15000
int t;
ll X, Y, xx[MaxN+1], yy[MaxN+1], p[MaxN+1];

void Init() {
    for (int i=10; i<=MaxN; i++) {
        p[i] = 1;
        xx[i] = 0;
        yy[i] = 0;
    }
}

void ChangeToDec() {
    while (X > 0) {
        ll m = X%10, n = Y%10;
        X = X/10;
        Y = Y/10;
        for (ll i=10; i<=MaxN; i++) {
            xx[i] = xx[i] + m*p[i];
            yy[i] = yy[i] + n*p[i];
            p[i] = p[i]*i;
        }
    }
}

int BinSearch(ll val, ll a[]) {
    int l = 10, r = MaxN;
    while (l <= r) {
        int m = (l+r)/2;
        if (a[m] == val)
            return m;
        else if (a[m] < val)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

void Solve() {
    for (int i=10; i<=MaxN; i++) {
        int tmp = BinSearch(xx[i], yy);
        if (tmp > -1) {
            cout << i << " " << tmp;
            return;
        }
    }
}

int main()
{
    freopen("LOSTBASE.INP", "r", stdin);
    freopen("LOSTBASE.OUT", "w", stdout);
    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> X >> Y;
        Init();
        ChangeToDec();
        Solve();
        cout << '\n';
    }
    return 0;
}
