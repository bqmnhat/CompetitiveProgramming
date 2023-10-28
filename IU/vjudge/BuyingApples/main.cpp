#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100
#define MaxK 100
#define MaxPrice 1000
using namespace std;
typedef long long ll;
int c, n, k;
ll dp[MaxK+1][MaxK+1], a[MaxK+1];

void ReadData() {
    for (int i=1; i<=k; i++) {
        cin >> a[i];
        if (a[i] == -1)
            a[i] = 1e9;
    }
}

ll Solution() {
    for (int i=1; i<=k; i++)
        dp[0][i] = 1e9;
    for (int i=1; i<=k; i++) {
        for (int j=1; j<=k; j++) {
            if (j - i >= 0)
                dp[i][j] = min(dp[i-1][j], dp[i][j-i] + a[i]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    if (dp[k][k] == 1e9)
        return -1;
    return dp[k][k];
}

void Solve() {
    for (int i=1; i<=c; i++) {
        memset(dp, 0, sizeof(dp));
        cin >> n >> k;
        ReadData();
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c;
    Solve();
    return 0;
}
