#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
const ll Mod = 1e9;
int t;
ll m, n;
bool Sieve[MaxN+5];

void MakeSieve(ll m, ll n) {
    memset(Sieve, false, sizeof(Sieve));
    for (ll i = 2; i*i<=n; i++)
        for (ll j = max(i*i, (m+i-1LL)/i*i); j<=n; j+=i)
            Sieve[j-m] = true;
    if (m == 1)
        Sieve[0] = true;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> m >> n;
        MakeSieve(m, n);
        for (ll i=m; i<=n; i++)
            if (!Sieve[i - m])
                cout << i << '\n';
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
