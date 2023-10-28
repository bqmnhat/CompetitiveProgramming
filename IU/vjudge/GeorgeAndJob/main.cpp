#include <iostream>
#include <bits/stdc++.h>
#define MaxN 5000
using namespace std;
typedef long long ll;
int n, m, k;
ll p[MaxN+1], dp[MaxN+1][MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> p[i];
        p[i] += p[i-1];
    }
}

ll Solution() {
    for (int i=m; i<=n; i++)
        for (int j=1; j<=k; j++)
            dp[i][j] = max(dp[i-1][j], dp[i-m][j-1] + p[i] - p[i-m]);
    return dp[n][k];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    ReadData();
    cout << Solution();
    return 0;
}
