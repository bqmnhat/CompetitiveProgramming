#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200
using namespace std;
typedef long long ll;
int R, G, B;
ll r[MaxN+1], g[MaxN+1], b[MaxN+1], dp[MaxN+1][MaxN+1][MaxN+1];

void ReadData() {
    for (int i=1; i<=R; i++)
        cin >> r[i];
    for (int i=1; i<=G; i++)
        cin >> g[i];
    for (int i=1; i<=B; i++)
        cin >> b[i];
}

ll Solution() {
    ll ans = 0;
    sort(r+1, r+1+R, greater<ll>());
    sort(g+1, g+1+G, greater<ll>());
    sort(b+1, b+1+B, greater<ll>());
    for (int i=0; i<=R; i++) {
        for (int j=0; j<=G; j++) {
            for (int k=0; k<=B; k++) {
                if ((i == 0) && (j == 0) && (k == 0))
                    continue;
                if ((i > 0) && (j > 0) && (k > 0))
                    dp[i][j][k] = dp[i-1][j-1][k-1];
                if ((i > 0) && (j > 0))
                    dp[i][j][k] = max(dp[i][j][k], max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i-1][j-1][k] + r[i]*g[j])));
                if ((i > 0) && (k > 0))
                    dp[i][j][k] = max(dp[i][j][k], max(dp[i-1][j][k], max(dp[i][j][k-1], dp[i-1][j][k-1] + r[i]*b[k])));
                if ((j > 0) && (k > 0))
                    dp[i][j][k] = max(dp[i][j][k], max(dp[i][j-1][k], max(dp[i][j][k-1], dp[i][j-1][k-1] + g[j]*b[k])));
            }
        }
    }
    return dp[R][G][B];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> R >> G >> B;
    ReadData();
    cout << Solution();
    return 0;
}
