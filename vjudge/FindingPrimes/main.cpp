#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10000000
using namespace std;
int t, n;
bool Sieve[MaxN+5];
vector<int> primes;

void MakeSieve() {
    Sieve[0] = Sieve[1] = true;
    for (int i=2; i*i<=MaxN; i++)
        if (!Sieve[i])
            for (int j=i; i*j<=MaxN; j++)
                Sieve[i*j] = true;
    for (int i=2; i<=MaxN; i++)
        if (!Sieve[i])
            primes.push_back(i);
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        int tmpn = n/2;
        int l = upper_bound(primes.begin(), primes.end(), tmpn) - primes.begin();
        int r = upper_bound(primes.begin(), primes.end(), n) - primes.begin() - 1;
        int ans = r - l + 1;
        cout << ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MakeSieve();
    cin >> t;
    Solve();
    return 0;
}
