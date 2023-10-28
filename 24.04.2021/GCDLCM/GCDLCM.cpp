#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long mu1[1000001], mu2[1000001], Sieve[1000001],m,n, c = 1000000000 + 7;

void MakeSieve() {
    int m = sqrt(1000000);
    for (int i = 2; i<=m; i++) {
        if (Sieve[i] == 0) {
            for (int j = i; i*j <= 1000000; j++) {
                Sieve[i*j] = i;
            }
        }
    }
}

void Factorise(long long val, long long mu[]) {
    while (val > 1) {
        int p = Sieve[val];
        if (p == 0)
            p = val;
        while (val%p == 0) {
            mu[p]++;
            val = val/p;
        }
    }
}

void ReadData() {
    int val;
    for (int i=1; i<=n; i++) {
        cin >> val;
        Factorise(val, mu1);
    }
    for (int i=1; i<=m; i++) {
        cin >> val;
        Factorise(val, mu2);
    }
}

void Solve() {
    long long gcd = 1, lcm = 1;
    for (int i=1; i<=1000000; i++) {
        long long x = min(mu1[i], mu2[i]);
        for (int j = 1; j<=x; j++)
            gcd = ((gcd%c) * (i%c))%c;
        long long y = max(mu1[i], mu2[i]);
        for (int j=1; j<=y; j++)
            lcm = ((lcm%c) * (i%c))%c;
    }
    cout << gcd << endl;
    cout << lcm;
}

int main()
{
    freopen("GCDLCM.INP", "r", stdin);
    freopen("GCDLCM.OUT", "w", stdout);
    MakeSieve();
    cin >> n >> m;
    ReadData();
    Solve();
    return 0;
}
