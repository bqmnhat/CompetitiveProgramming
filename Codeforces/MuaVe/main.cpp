#include <iostream>
#include <bits/stdc++.h>
#define MaxN 5000
using namespace std;
typedef long long ll;
int n, TimeCost[MaxN+1][4], dp[MaxN+2];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> TimeCost[i][1] >> TimeCost[i][2] >> TimeCost[i][3];
}

int Solution() {
    for (int i=n; i>=1; i--) {
        dp[i] = 1e9 + 7;
        for (int j=1; j<=3; j++)
            if (i + j <= n + 1)
                dp[i] = min(dp[i], dp[i+j] + TimeCost[i][j]);
    }
    return dp[1];
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
