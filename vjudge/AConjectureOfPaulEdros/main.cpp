#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10000000
using namespace std;
bool Sieve[MaxN+5];
int t, n, ans[MaxN+5];

void MakeSieve() {
    Sieve[0] = Sieve[1] = true;
    for (int i=2; i*i<=MaxN; i++)
        if (!Sieve[i])
            for (int j=i; i*j<=MaxN; j++)
                Sieve[i*j] = true;
}

void MakeAns() {
    for (int x=0; x*x<=MaxN; x++)
        for (int y=0; x*x + y*y*y*y <= MaxN; y++)
            if (!Sieve[x*x + y*y*y*y])
                ans[x*x + y*y*y*y] = 1;
    for (int i=1; i<=MaxN; i++)
        ans[i] += ans[i-1];
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        cout << ans[n] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MakeSieve();
    MakeAns();
    cin >> t;
    Solve();
    return 0;
}
