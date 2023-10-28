#include <iostream>
#include <bits/stdc++.h>
#define MaxN 500
using namespace std;
const int INF = 1e9 + 7;
int w, h, dp[MaxN+5][MaxN+5];

void Init() {
    for (int i=0; i<=w; i++) {
        for (int j=0; j<=h; j++) {
            if (i == j)
                dp[i][j] = 0;
            else
                dp[i][j] = INF;
        }
    }
}

int Solution() {
    for (int i=0; i<=w; i++) {
        for (int j=0; j<=h; j++) {
            if (i==j)
                continue;
            for (int k=1; k<i; k++)
                dp[i][j] = dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-k][j]+1);
            for (int k = 1; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
        }
    }
    return dp[w][h];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> w >> h;
    Init();
    cout << Solution();
    return 0;
}
