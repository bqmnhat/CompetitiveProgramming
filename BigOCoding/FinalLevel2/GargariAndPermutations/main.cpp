#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, k, a[6][1001], pos[6][1001], dp[1001];

void ReadData() {
    for (int i=1; i<=k; i++) {
        for (int j=1; j<=n; j++) {
            cin >> a[i][j];
            pos[i][a[i][j]] = j;
        }
    }
}

int Solution () {
    int ans = 1;
    for (int i=1; i<=n; i++) {
        dp[i] = 1;
        for (int j=1; j<i; j++) {
            bool Flag = true;
            for (int kk = 2; kk<=k; kk++) {
                if (pos[kk][a[1][i]] < pos[kk][a[1][j]]) {
                    Flag = false;
                    break;
                }
            }
            if (Flag)
                dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    ReadData();
    cout << Solution();
    return 0;
}
