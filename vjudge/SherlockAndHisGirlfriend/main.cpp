#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100001
using namespace std;
bool Sieve[MaxN+1];
int ans[MaxN+1], n;

void MakeSieve() {
    Sieve[0] = Sieve[1] = true;
    for (int i=2; i*i <= MaxN; i++)
        if (!Sieve[i])
            for (int j=i; i*j <= MaxN; j++)
                Sieve[i*j] = true;
}

void Solve() {
    bool Prime = false, Mult = false;
    for (int i=1; i<=n; i++) {
        if (Sieve[i+1]) {
            ans[i] = 2;
            Mult = true;
        }
        else {
            ans[i] = 1;
            Prime = true;
        }
    }
    int cnt = 0;
    if (Prime)
        cnt++;
    if (Mult)
        cnt++;
    cout << cnt << '\n';
    for (int i=1; i<=n; i++)
        cout << ans[i] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    MakeSieve();
    Solve();
    return 0;
}
