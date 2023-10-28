#include <iostream>
#include <bits/stdc++.h>
#define MaxN 2000
using namespace std;
typedef long long ll;
int n;
ll p[MaxN+1], dp[MaxN+1][MaxN+1], K[MaxN+1][MaxN+1], pref[MaxN+1];
const ll INF = 1e9 + 7;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> p[i];
        pref[i] = pref[i-1] + p[i];
    }
}

ll Solution() {
    for (int i=0; i<=n; i++)
        for (int j=i; j<=n; j++)
            dp[i][j] = 0;
    for (int i=1; i<=n; i++) {
        dp[i][i] = 0;
        K[i][i] = i;
    }
    for (int i=n-1; i>=1; i--) {
        for (int j=i+1; j<=n; j++) {
            for (int k=K[i][j-1]; k<=K[i+1][j]; k++) {
                ll NewCost = min(dp[k][j] + pref[j] - pref[k-1], dp[i][k-1] + pref[k-1] - pref[i-1]);
                if (NewCost >= dp[i][j]) {
                    dp[i][j] = NewCost;
                    K[i][j] = k;
                }
            }
        }
    }
    return dp[1][n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
