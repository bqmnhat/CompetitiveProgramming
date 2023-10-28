#include <iostream>
#include <bits/stdc++.h>
#define MaxC 100
#define MaxM 100
using namespace std;
typedef long long ll;
int c, m;
ll p[MaxM+1][MaxC+1], dp[MaxM+1][MaxC+1];

void ReadData() {
    for (int i=1; i<=m; i++)
        for (int j=1; j<=c; j++)
            cin >> p[i][j];
}

ll Solution() {
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=c; j++) {
            ll Profit = 0;
            for (int t = 0; t <= j; t++)
                Profit = max(Profit, dp[i-1][j-t] + p[i][t]);
            dp[i][j] = Profit;
        }
    }
    return dp[m][c];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("SELLINGCPUs.INP", "r", stdin);
    freopen("SELLINGCPUs.OUT", "w", stdout);
    cin >> c >> m;
    ReadData();
    cout << Solution();
    return 0;
}
