#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1120
#define MaxK 14
using namespace std;
int n, k, lp = 0, Primes[1001], dp[MaxN+1][MaxK+1];
bool Sieve[MaxN+1];

void MakePrimes() {
    Sieve[0] = Sieve[1] = true;
    for (int i=2; i*i<=MaxN; i++)
        if (!Sieve[i])
            for (int j = i; i*j <= MaxN; j++)
                Sieve[i*j] = true;
    for (int i=2; i<=MaxN; i++) {
        if (!Sieve[i]) {
            lp++;
            Primes[lp] = i;
        }
    }
}

void CalDp() {
    dp[0][0] = 1;
    for (int i=1; i<=lp; i++) {
        for (int j = MaxN; j>=Primes[i]; j--) {
            for (int kk = MaxK; kk>=1; kk--) {
                dp[j][kk] += dp[j-Primes[i]][kk-1];
            }
        }
    }
}

void Solve() {
    cin >> n >> k;
    while ((n != 0) || (k != 0)){
        cout << dp[n][k] << '\n';
        cin >> n >> k;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MakePrimes();
    CalDp();
    Solve();
    return 0;
}
