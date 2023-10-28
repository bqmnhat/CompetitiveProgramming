#include <iostream>
#include <bits/stdc++.h>
#define MaxN 5000000
using namespace std;
typedef long long ll;
int t, l, r, Sieve[MaxN+1];
ll dp[MaxN+1]; // dp[i] is f[i]
const ll Mod = 1e9 + 7;

inline void MakeSieve() {
    for (int i=2; i*i <= MaxN; i++)
        if (Sieve[i] == 0)
            for (int j=i; i*j<=MaxN; j++)
                Sieve[i*j] = i;
    for (int i=2; i<=MaxN; i++)
        if (Sieve[i] == 0)
            Sieve[i] = i;
}

inline void FindAllFRes() {
    for (int n = 2; n<=r; n++) {
        dp[n] = 1e18;
        for (int x = n; x > 1; x /= Sieve[x])
            dp[n] = min(dp[n], 1LL*dp[n / Sieve[x]] + (n*1LL*(Sieve[x] - 1LL)/2));
    }
}

inline ll Solution() {
    ll ans = 0, TExp = 1;
    for (int i=l; i<=r; i++) {
        ans = (ans + (TExp*1LL*(dp[i]%Mod))%(1LL*Mod))%Mod;
        TExp = (TExp*1LL*t)%(1LL*Mod);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t >> l >> r;
    MakeSieve();
    FindAllFRes();
    cout << Solution();
    return 0;
}
