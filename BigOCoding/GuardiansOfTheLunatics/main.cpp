#include <iostream>
#include <bits/stdc++.h>
#define MaxN 8005
#define MaxG 805
using namespace std;
typedef long long ll;
int n, g, c[MaxN+1], K[MaxN+1][MaxG+1];
ll dp[MaxN+1][MaxG+1], pref[MaxN+1];
const ll INF = 1e18 + 7;

inline void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> c[i];
        pref[i] = pref[i-1] + 1LL*c[i];
    }
}

inline ll Solution() {
    for (int i=1; i<=n+1; i++) {
        for (int j=0; j<=g+1; j++) {
            if ((j >= i) || (j == g+1))
                K[i][j] = i-1;
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for (int i=1; i<=n; i++) {
        int MaxJ = min(i, g);
        for (int j = MaxJ; j>=1; j--) {
            for (int k=K[i-1][j]; k<=K[i][j+1]; k++) {
                ll NewCost = dp[k][j-1] + 1LL*(pref[i] - pref[k])*(i - k);
                if (NewCost <= dp[i][j]) {
                    dp[i][j] = NewCost;
                    K[i][j] = k;
                }
            }
        }
    }
    return dp[n][min(n, g)];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> g;
    ReadData();
    cout << Solution();
    return 0;
}
