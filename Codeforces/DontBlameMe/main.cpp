#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
#define MaxMask 64
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 7;
int t, n, k, a[MaxN+5], cntBit[MaxMask+5], Log2[MaxMask+5], MaxVal;

void MakeCntBit() {
    for (int mask=0; mask < MaxMask; mask++)
        cntBit[mask] = __builtin_popcount(mask);
}

ll Solution() {
    vector<vector<ll>> dp(n+1, vector<ll>(MaxMask, 0));
    //int thre = (1 << (Log2[MaxVal] + 1));
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        dp[i][a[i]] = (dp[i][a[i]] + 1LL)%Mod;
        if (dp[i][a[i]] > Mod)
            dp[i][a[i]] -= Mod;
        for (int mask = 0; mask < MaxMask; mask++) {
            dp[i][mask] = dp[i][mask] + dp[i-1][mask];
            if (dp[i][mask] > Mod)
                dp[i][mask] -= Mod;
            dp[i][mask&a[i]] = (dp[i][mask&a[i]] + dp[i-1][mask])%Mod;
            if (dp[i][mask&a[i]] > Mod)
                dp[i][mask&a[i]] -= Mod;
        }
    }
    ll ans = 0;
    for (int mask = 0; mask < MaxMask; mask++)
        if (cntBit[mask] == k)
            ans = (ans + dp[n][mask])%Mod;
    return ans;
}

void Solve() {
    MakeCntBit();
    for (int i=1; i<=t; i++) {
        cin >> n >> k;
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
