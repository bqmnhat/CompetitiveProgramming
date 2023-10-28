#include <iostream>
#include <bits/stdc++.h>
#define MaxN 20000
#define MaxK 10
using namespace std;
typedef long long ll;
int n, k;
ll a[MaxN+1], d;
unordered_map<ll, int> dp[MaxK+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

int Solution() {
    int ans = 1;
    unordered_map<ll, int> dp2[MaxK+1];
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=k; j++)
            dp2[j].clear();
        for (int j=0; j<=k; j++) {
            for (ll t = 0; t<=j; t++) {
                int tmp1 = dp[j-t][a[i] + t - d]+1, tmp2 = dp[j-t][a[i] - t - d]+1;
                dp2[j][a[i] + t] = max(tmp1, dp[j][a[i] + t]);
                dp2[j][a[i] - t] = max(tmp2, dp[j][a[i] - t]);
            }
        }
        for (int j=0; j<=k; j++) {
            for (ll t = 0; t<=j; t++) {
                dp[j][a[i] + t] = dp2[j][a[i] + t];
                dp[j][a[i] - t] = dp2[j][a[i] - t];
                ans = max(ans, max(dp[j][a[i] - t], dp[j][a[i] + t]));
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CSC.INP", "r", stdin);
    cin >> n >> d >> k;
    ReadData();
    cout << Solution();
    return 0;
}
