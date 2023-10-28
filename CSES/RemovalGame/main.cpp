#include <iostream>
#include <bits/stdc++.h>
#define MaxN 5000
using namespace std;
typedef long long ll;
int n;
ll dp[MaxN+5][MaxN+5][2], a[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

ll Solution() {
    for (int i=n; i>=1; i--) {
        for (int j=i; j<=n; j++) {
            for (int player = 0; player <= 1; player++) {
                if (player == 0)
                    dp[i][j][player] = max(dp[i][j-1][1-player] + a[j], dp[i+1][j][1-player] + a[i]);
                else
                    dp[i][j][player] = min(dp[i][j-1][1-player], dp[i+1][j][1-player]);
            }
        }
    }
    return dp[1][n][0];
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
