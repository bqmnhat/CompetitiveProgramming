#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, n, a[21][4], dp[21][4];

void ReadData() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=3; j++) {
            cin >> a[i][j];
        }
    }
}

void Init() {
    for (int i=1; i<=20; i++) {
        for (int j=1; j<=3; j++) {
            dp[i][j] = 0;
        }
    }
}

int MinCost() {
    int ans = 20001;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=3; j++) {
            if (j == 1)
                dp[i][j] = a[i][j] + min(dp[i-1][2], dp[i-1][3]);
            if (j == 2)
                dp[i][j] = a[i][j] + min(dp[i-1][1], dp[i-1][3]);
            if (j == 3)
                dp[i][j] = a[i][j] + min(dp[i-1][1], dp[i-1][2]);
            if ((i == n) && (dp[i][j] < ans))
                ans = dp[i][j];
        }
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        Init();
        cin >> n;
        ReadData();
        cout << MinCost() << '\n';
    }
}

int main()
{
    freopen("PAINT.INP", "r", stdin);
    freopen("PAINT.OUT", "w", stdout);
    cin >> t;
    Solve();
    return 0;
}
