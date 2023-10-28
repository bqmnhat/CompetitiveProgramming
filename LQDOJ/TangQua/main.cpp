#include <iostream>
#include <bits/stdc++.h>
#define MaxN 2000
using namespace std;
int n, dp[2*MaxN+5][2*MaxN+5], d, c[2*MaxN+5];

void ReadData() {
    for (int i=1; i<=2*n; i++)
        cin >> c[i];
}

int CalDp(int i, int j) {
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i == j)
        return dp[i][j] = 0;;
    dp[i][j] = 0;
    if (abs(c[i] - c[j]) <= d)
        dp[i][j] = CalDp(i+1, j-1) + 1;
    dp[i][j] = max(dp[i][j], max(CalDp(i+1, j), CalDp(i, j-1)));
    return dp[i][j];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> d;
    ReadData();
    memset(dp, -1, sizeof(dp));
    cout << CalDp(1, 2*n);
    return 0;
}
