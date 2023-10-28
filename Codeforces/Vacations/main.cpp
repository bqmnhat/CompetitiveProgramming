#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, a[101], dp[101][3];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

int Solution() {
    for (int i=1; i<=n; i++) {
        dp[i][0] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
        if ((a[i] == 1) || (a[i] == 3))
            dp[i][1] = max(dp[i-1][0] + 1, dp[i-1][2] + 1);
        if ((a[i] == 2) || (a[i] == 3))
            dp[i][2] = max(dp[i-1][0] + 1, dp[i-1][1] + 1);
    }
    return (n - max(dp[n][0], max(dp[n][1], dp[n][2])));
}

int main()
{
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
