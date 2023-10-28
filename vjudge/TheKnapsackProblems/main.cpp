#include <iostream>
#include <bits/stdc++.h>
#define MaxN 2000
#define MaxS 2000
using namespace std;
int n, v[MaxN+1], w[MaxN+1], dp[MaxN+1][MaxN+1], S;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> w[i] >> v[i];
}

int Solution() {
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=S; j++) {
            dp[i][j] = dp[i-1][j];
            if (j - w[i] >= 0)
                dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i]);
        }
    }
    return dp[n][S];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> S >> n;
    ReadData();
    cout << Solution();
    return 0;
}
