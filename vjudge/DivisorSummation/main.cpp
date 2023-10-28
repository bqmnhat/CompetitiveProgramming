#include <iostream>
#include <bits/stdc++.h>
#define MaxN 500000
using namespace std;
typedef long long ll;
int t;
ll Sieve[MaxN+5];

void MakeSieve() {
    for (int i=1; i*i<=MaxN; i++) {
        Sieve[i*i] += i;
        for (int j=i+1; i*j<=MaxN; j++)
            Sieve[i*j] += i + j;
    }
}

void Solve() {
    for (int i=1; i<=t; i++) {
        int n;
        cin >> n;
        cout << Sieve[n] - n << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    MakeSieve();
    Solve();
    return 0;
}
