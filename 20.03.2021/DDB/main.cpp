#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t,n,a[2000001];
bool Sieve[2000001];

void MakeSieve() {
    Sieve[0] = Sieve[1] = true;
    int m = sqrt(2000000);
    for (int i=2; i<=m; i++) {
        if (Sieve[i] == false) {
            for (int j=i; j<=2000000/i; j++) {
                Sieve[i*j] = true;
            }
        }
    }
    for (int i=1; i<=2000000; i++) {
        if (Sieve[i] == false) {
            a[i] = a[i-1]+1;
        }
        else
            a[i] = a[i-1];
    }
}

void Solve() {
    for (int i=1; i<=t; i++) {
        int dem = 0;
        cin >> n;
        cout << a[2*n] - a[n] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("DDB.INP", "r", stdin);
    freopen("DDB.OUT", "w", stdout);
    MakeSieve();
    cin >> t;
    Solve();
    return 0;
}
