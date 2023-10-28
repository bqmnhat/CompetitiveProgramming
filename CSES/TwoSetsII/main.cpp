#include <iostream>
#include <bits/stdc++.h>
#define MaxN 500
#define MaxVal 200000
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 7;
ll dp[MaxN+5][MaxVal+5], n;

ll Solution() {
    ll sum = (n*(n+1LL))/2;
    if (sum%2)
        return 0;
    sum >>= 1LL;
    dp[0][0] = 1;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=sum; j++) {
            dp[i][j] = dp[i-1][j];
            if (j - i >= 0)
                dp[i][j] = (dp[i][j] + dp[i-1][j-i])%Mod;
        }
    }
    return dp[n][sum];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cout << Solution();
    return 0;
}
