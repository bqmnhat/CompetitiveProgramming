#include <iostream>
#include <bits/stdc++.h>
#define MaxN 40000000
using namespace std;
typedef long long ll;
bool Sieve[MaxN+5];
vector<ll> primes;
ll n;

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

void SolveTestCase(ll val) {
    map<ll, ll> mu;
    while (val > 1LL) {
        ll SpFId = 0;
        while ((val%primes[SpFId] != 0) && (SpFId+1 < primes.size()))
            SpFId++;
        ll p = primes[SpFId];
        if (val%p == 0) {
            mu[p]++;
            val /= p;
        }
        else
            break;
    }
    if (val > 1LL)
        mu[val]++;
    for (auto it = mu.begin(); it != mu.end(); it++)
        cout << (*it).first << "^" << (*it).second << ' ';
    cout << '\n';
}

void Solve() {
    while ((cin >> n) && (n != 0LL))
        SolveTestCase(n);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MakeSieve();
    Solve();
    return 0;
}
