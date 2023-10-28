#include <iostream>
#include <bits/stdc++.h>
#define MaxVal 1000000
#define MaxN 100
using namespace std;
const int INF = 1e9 + 7;
int n, dp[MaxN+5][MaxVal+5], c[MaxN+5], x;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> c[i];
}

void Init() {
    for (int i=0; i<=n; i++)
        for (int j=1; j<=x; j++)
            dp[i][j] = INF;
}

int Solution() {
    Init();
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=x; j++) {
            dp[i][j] = dp[i-1][j];
            if (j - c[i] >= 0)
                dp[i][j] = min(dp[i][j - c[i]] + 1, min(dp[i-1][j - c[i]] + 1, dp[i][j]));
        }
    }
    if (dp[n][x] >= INF)
        return -1;
    return dp[n][x];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    ReadData();
    cout << Solution();
    return 0;
}
