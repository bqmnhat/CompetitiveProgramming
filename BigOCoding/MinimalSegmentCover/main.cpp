#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
#define MaxLen 500000
using namespace std;
int n, m, l[MaxN+1], r[MaxN+1], dp[MaxLen+1][21]; // dp[x][k] = furthest reach from x using 2^k segments

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> l[i] >> r[i];
        dp[l[i]][0] = max(dp[l[i]][0], r[i]);
    }
}

void CalculateDp() {
    for (int i=0; i<=MaxLen; i++)
        dp[i][0] = max(i, max(dp[i-1][0], dp[i][0]));
    for (int j = 1; j<=20; j++)
        for (int i=0; i<=MaxLen; i++)
            dp[i][j] = dp[dp[i][j-1]][j-1];
}

int Solution(int a, int b) {
    int ans = 0;
    for (int j=20; j>=0; j--) {
        if (dp[a][j] < b) {
            a = dp[a][j];
            ans += (1 << j);
        }
    }
    if (dp[a][0] < b)
        return -1;
    return (ans + 1);
}

void Solve() {
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        cout << Solution(a, b) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    CalculateDp();
    Solve();
    return 0;
}
