#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100
#define MaxV 100000
using namespace std;
typedef long long ll;
int n, v[MaxN+1], MaxVal = 0;
ll W, w[MaxN+1], dp[MaxN+2][MaxV+1];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> w[i] >> v[i];
        MaxVal += v[i];
    }
}

void Init() {
    for (int i=1; i<=MaxN+1; i++)
        for (int j=1; j<=MaxV; j++)
            dp[i][j] = 1e18;
}

void CalDp() {
    dp[n+1][0] = 0;
    for (int i=n; i>=1; i--) {
        for (int j=0; j<=MaxV; j++) {
            dp[i][j] = dp[i+1][j];
            if (v[i] <= j)
                dp[i][j] = min(dp[i][j], dp[i+1][j - v[i]] + w[i]);
        }
    }
}

int Solution() {
    for (int i=MaxVal; i>=1; i--) {
        if (dp[1][i] <= W)
            return i;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> W;
    ReadData();
    Init();
    CalDp();
    cout << Solution();
    return 0;
}
