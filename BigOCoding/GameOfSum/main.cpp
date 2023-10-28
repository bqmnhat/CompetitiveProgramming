#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100
using namespace std;
typedef long long ll;
int n;
ll dp[MaxN+1][MaxN+1], a[MaxN+1], pref[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        pref[i] = pref[i-1] + a[i];
    }
}

ll CalDp(int i, int j) {
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i == j)
        return dp[i][j] = a[i];
    dp[i][j] = -1e18;
    for (int t = i-1; t<j; t++)
        dp[i][j] = max(dp[i][j], -CalDp(i, t) + pref[j] - pref[t]);
    for (int k=i+1; k<=j+1; k++)
        dp[i][j] = max(dp[i][j], -CalDp(k, j) + pref[k-1] - pref[i-1]);
    return dp[i][j];
}

void Solve() {
    while ((cin >> n) && (n != 0)) {
        ReadData();
        memset(dp, -1, sizeof(dp));
        cout << CalDp(1, n) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
