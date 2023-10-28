#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MaxN 1000001
int q;
bool Sieve[MaxN+1];

void MakeSieve() {
    int m = sqrt(MaxN);
    Sieve[0] = Sieve[1] = true;
    for (int i=2; i<=m; i++) {
        if (Sieve[i] == false)
            for (int j=i; i*j <= MaxN; j++)
                Sieve[i*j] = true;
    }
}

void Solve() {
    int ai;
    for (int i=1; i<=q; i++) {
        cin >> ai;
        if ((Sieve[ai-1] == false) || (Sieve[ai] == false) || (Sieve[ai+1] == false))
            cout << "1";
        else
            cout << "0";
        cout << '\n';
    }
}

int main()
{
    freopen("NPRIMES.INP", "r", stdin);
    freopen("NPRIMES.OUT", "w", stdout);
    cin >> q;
    MakeSieve();
    Solve();
    return 0;
}
