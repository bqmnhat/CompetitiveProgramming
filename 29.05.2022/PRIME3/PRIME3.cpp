#include <iostream>
#include <bits/stdc++.h>
#define MaxP 1000
#define MaxN 10000
using namespace std;
typedef long long ll;
int n;
ll dp[MaxN+1][100];
bool Sieve[MaxP+1];
int Primes[MaxP+1], lp = 0;
const ll Mod = 1e9 + 9;

void MakeSieve() {
    Sieve[0] = Sieve[1] = true;
    for (int i=2; i*i<=MaxP; i++)
        if (!Sieve[i])
            for (int j=i; i*j <= MaxP; j++)
                Sieve[i*j] = true;
}

void MakePrimes() {
    for (int i=100; i<=MaxP; i++) {
        if (!Sieve[i]) {
            lp++;
            Primes[lp] = i;
        }
    }
}

ll Solution() {
    ll ans = 0;
    for (int i=1; i<=lp; i++)
        dp[3][Primes[i]%100]++;
    for (int i=4; i<=n; i++)
        for (int j=1; j<=lp; j++)
            dp[i][Primes[j]%100] = (dp[i][Primes[j]%100] + dp[i-1][Primes[j]/10])%Mod;
    for (int j=0; j<=99; j++)
        ans = (ans + dp[n][j])%Mod;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("PRIME3.INP", "r", stdin);
    freopen("PRIME3.OUT", "w", stdout);
    cin >> n;
    MakeSieve();
    MakePrimes();
    cout << Solution();
    return 0;
}
