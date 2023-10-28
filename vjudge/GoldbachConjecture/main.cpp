#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
typedef pair<int, int> pii;
bool Calculated[MaxN+1], Sieve[MaxN+1];
int lp = 0, primes[MaxN+1], val;
pii ans[MaxN+1];

void MakeSieve() {
    Sieve[0] = Sieve[1] = true;
    for (int i=2; i*i<=MaxN; i++)
        if (!Sieve[i])
            for (int j=i; i*j<=MaxN; j++)
                Sieve[i*j] = true;
    for (int i=2; i<=MaxN; i++) {
        if (Sieve[i])
            continue;
        lp++;
        primes[lp] = i;
    }
}

void Solve() {
    while ((cin >> val) && (val != 0)) {
        for (int i=1; i <= lp; i++) {
            if (primes[i]*2 > val) {
                cout << "Goldbach's conjecture is wrong.’\n";
                break;
            }
            if (!Sieve[val - primes[i]]) {
                cout << val << " = " << primes[i] << " + " << val - primes[i] << '\n';
                break;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("GBC.INP", "r", stdin);
    //freopen("GBC.OUT", "w", stdout);
    MakeSieve();
    Solve();
    return 0;
}
