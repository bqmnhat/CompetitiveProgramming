#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
typedef long long ll;
int m, n, a[MaxN+5][MaxN+5];
ll dpCol[MaxN+5][MaxN+5], dp[MaxN+5][MaxN+5];

void ReadData() {
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            cin >> a[i][j];
}

ll Solution() {
    ll res = 0;
    for (int i=1; i<=m; i++) {
        ll len = 0;
        for (int j=1; j<=n; j++) {
            if ((i == 1) || (a[i][j] != a[i-1][j]))
                dpCol[i][j] = 1;
            else
                dpCol[i][j] = dpCol[i-1][j] + 1LL;
            if ((j == 1) || (a[i][j] != a[i][j-1]))
                len = 1;
            else
                len++;
            if (a[i][j] == a[i-1][j-1])
                dp[i][j] = min(len, min(dpCol[i][j], dp[i-1][j-1] + 1LL));
            else
                dp[i][j] = 1;
            res = max(res, dp[i][j]);
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    ReadData();
    cout << Solution();
    return 0;
}
