#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000000
using namespace std;
bool Sieve[MaxN+5];
int cntPrimes[MaxN+5], n;

void MakeSieve() {
    memset(Sieve, true, sizeof(Sieve));
    Sieve[0] = Sieve[1] = false;
    for (int i=2; i*i<=MaxN; i++)
        if (Sieve[i])
            for (int j=i; i*j<=MaxN; j++)
                Sieve[i*j] = false;
}

void CountPrimes() {
    for (int i=2; i<=MaxN; i++)
        cntPrimes[i] = cntPrimes[i-1] + Sieve[i];
}

void Solve() {
    while ((cin >> n) && (n != 0)) {
        double  ans = abs(cntPrimes[n] - (double(n)/double(log(n))))/cntPrimes[n];
        cout << fixed << setprecision(1) << ans*100.0 << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MakeSieve();
    CountPrimes();
    Solve();
    return 0;
}
