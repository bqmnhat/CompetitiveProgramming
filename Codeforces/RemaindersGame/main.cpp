#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
typedef long long ll;
int Sieve[MaxN+1], CFac[MaxN+1], KFac[MaxN+1], n, k, c[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> c[i];
}

void MakeSieve() {
    for (int i=2; i*i<=MaxN; i++)
        if (Sieve[i] == 0)
            for (int j=2; i*j<=MaxN; j++)
                Sieve[i*j] = i;
}

void FastFactorization(int val, int mu[MaxN+1]) {
    while (val > 1) {
        int p = Sieve[val];
        if (p == 0)
            p = val;
        int tmp = 0;
        while (val % p == 0) {
            tmp++;
            val = val/p;
        }
        mu[p] = max(mu[p], tmp);
    }
}

bool Solution() {
    FastFactorization(k, KFac);
    for (int i=1; i<=n; i++)
        FastFactorization(c[i], CFac);
    bool ans = true;
    for (int i=2; i<=MaxN; i++)
        if (Sieve[i] == 0)
            if (CFac[i] < KFac[i])
                ans = false;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    ReadData();
    MakeSieve();
    if (Solution())
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
