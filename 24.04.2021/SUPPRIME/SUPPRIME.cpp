#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool Sieve[1000001];
int n;

void MakeSieve() {
    Sieve[0] = Sieve[1] = true;
    int m = sqrt(50000);
    for (int i=2; i<=m; i++) {
        if (Sieve[i] == false) {
            for (int j = i; j<=50000/i; j++) {
                Sieve[i*j] = true;
            }
        }
    }
}

void Solve() {
    int dem = 0, i = 1, k = 0;
    while (dem < n) {
        if (Sieve[i] == false) {
            k++;
            if (Sieve[k] == false) {
                dem++;
            }
        }
        i++;
    }
    cout << i-1;
}

int main()
{
    freopen("SUPPRIME.INP", "r", stdin);
    freopen("SUPPRIME.OUT", "w", stdout);
    cin >> n;
    MakeSieve();
    Solve();
    return 0;
}
