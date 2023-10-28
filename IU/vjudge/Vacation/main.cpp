#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int n, dp[MaxN+1][3], a[MaxN+1][3];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2];
}

int Solution() {
    for (int i=1; i<=n; i++) {
        for (int j=0; j<3; j++) {
            for (int k=0; k<3; k++) {
                if ((j == k) && (i > 1))
                    continue;
                dp[i][j] = max(dp[i][j], dp[i-1][k] + a[i][j]);
            }
        }
    }
    return max(dp[n][0], max(dp[n][1], dp[n][2]));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
