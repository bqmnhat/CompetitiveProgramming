#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 7;
int n, t;
ll dp1[MaxN+5], dp2[MaxN+5];

void MakeDp() {
    dp1[1] = dp2[1] = 1;
    for (int i=2; i<=MaxN; i++) {
        dp1[i] = (2*dp1[i-1] + dp2[i-1])%Mod;
        dp2[i] = (4*dp2[i-1] + dp1[i-1])%Mod;
    }
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ll ans = (dp1[n] + dp2[n])%Mod;
        cout << ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MakeDp();
    cin >> t;
    Solve();
    return 0;
}
