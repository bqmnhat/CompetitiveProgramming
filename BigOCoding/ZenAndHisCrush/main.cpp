#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
int t, n, k;
double p[MaxN+1], dp[MaxN+1][MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> p[i];
}

double Solution() {
    dp[0][0] = 1;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=i; j++) {
            dp[i][j] = dp[i-1][j]*(1 - p[i]);
            if (j == 0)
                continue;
            dp[i][j] += dp[i-1][j-1]*p[i];
        }
    }
    return dp[n][k];
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> k;
        ReadData();
        cout << fixed << setprecision(10) << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
