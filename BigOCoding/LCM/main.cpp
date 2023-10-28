#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, Mod = 1e9 + 7, primes[1000001], lp = 0;
bool Sieve[1000001];

void MakeSieve() {
    Sieve[0] = Sieve[1] = true;
    for (int i=2; i <= 1000; i++) {
        if (!Sieve[i]) {
            for (int j=i; i*j <= 1000000; j++) {
                Sieve[i*j] = true;
            }
        }
    }
}

void MakePrimes() {
    for (int i=1; i<=n; i++) {
        if (!Sieve[i]) {
            lp++;
            primes[lp] = i;
        }
    }
}

int Solution() {
    long long ans = 1;
    for (int i = 1; i <= lp; i++) {
        long long  x = 1;
        while (1LL*x*primes[i] <= n) {
            x = x*1LL*primes[i];
            ans = (1LL*(ans%Mod)*(primes[i]%Mod))%Mod;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    MakeSieve();
    MakePrimes();
    cout << Solution();
    return 0;
}
