#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10
#define MaxM 1000
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 7;
int n, m;
ll dp[MaxM+5][MaxN+5][1 << MaxN];

ll Solution() {
    dp[0][n][0] = 1;
    for (int i=1; i<=m; i++) {
        for (int mask = 0; mask < (1 << n); mask++)
            dp[i][0][mask] = dp[i-1][n][mask];
        for(int j = 1; j <= n; j++){
            for(int mask = 0; mask < (1<<n); mask++){
                if(mask&(1<<(j-1)))
                    dp[i][j][mask] = (dp[i][j][mask] + dp[i][j-1][mask^(1<<(j-1))])%Mod;
                else {
                    dp[i][j][mask] = (dp[i][j][mask] + dp[i][j-1][mask^(1<<(j-1))])%Mod;
                    if((j > 1) && (!(mask&(1<<(j-2)))))
                        dp[i][j][mask]= (dp[i][j][mask] + dp[i][j-2][mask])%Mod;
                }
            }
        }
    }
    return dp[m][n][0];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    cout << Solution();
    return 0;
}
