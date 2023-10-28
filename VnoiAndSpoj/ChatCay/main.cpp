#include <iostream>
#include <bits/stdc++.h>
#define MaxN 2000
using namespace std;
typedef long long ll;
int n, K[MaxN+5][MaxN+5];
ll dp[MaxN+5][MaxN+5], a[MaxN+5], pref[MaxN+5];
const int INF = 1e9 + 7;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        pref[i] = pref[i-1] + a[i];
    }
}

ll Solution() {
    for (int i=1; i<=n; i++)
        for (int j=i; j<=n; j++)
            dp[i][j] = INF;
    for (int i=1; i<=n; i++) {
        dp[i][i] = 0;
        K[i][i] = i;
    }
    for (int i=n-1; i>=1; i--) {
        for (int j=i+1; j<=n; j++) {
            for (int k=K[i][j-1]; k<=K[i+1][j]; k++) {
                ll NewCost = pref[j] - pref[i-1] + dp[i][k-1] + dp[k][j];
                if (NewCost <= dp[i][j]) {
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
