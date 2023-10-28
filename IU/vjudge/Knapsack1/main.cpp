#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100
#define MaxW 100000
using namespace std;
typedef long long ll;
int n, W;
ll v[MaxN+1], w[MaxN+1], dp[MaxN+1][MaxW+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> w[i] >> v[i];
}

ll Solution() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=W; j++) {
            dp[i][j] = dp[i-1][j];
            if (j - w[i] >= 0)
                dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i]);
        }
    }
    return dp[n][W];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> W;
    ReadData();
    cout << Solution();
    return 0;
}
