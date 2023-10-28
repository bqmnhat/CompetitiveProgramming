#include <iostream>
#include <bits/stdc++.h>
#define MaxN 300
#define MaxM 10
#define MaxK 3000
using namespace std;
typedef long long ll;
int n, m, k;
ll dp[MaxN+1][MaxK+1], pref[MaxN+1][MaxM+1], a[MaxN+1][MaxM+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin >> a[i][j];
}

void MakePref() {
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            pref[i][j] = pref[i][j-1] + a[i][j];
}

ll Solution() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=k; j++) {
            dp[i][j] = dp[i-1][j];
            for (int t = 1; t <= m; t++) {
                if (j - t >= 0)
                    dp[i][j] = max(dp[i][j], dp[i-1][j-t] + pref[i][t]);
            }
        }
    }
    return dp[n][k];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    ReadData();
    MakePref();
    cout << Solution();
    return 0;
}
