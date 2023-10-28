//Vjudge
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long l,k,dp[101][2];

long long Solution() {
    long long ans = 0;
    dp[1][1] = dp[k][1] = 1;
    for (int i=2; i<=l; i++) {
        for (int j=0; j<2; j++) {
            if (j == 0)
                dp[i][j] = dp[i][j] + dp[i-1][1];
            else {
                dp[i][j] = dp[i][j] + dp[i-1][0];
                if (i-k >= 1)
                    dp[i][j] = dp[i][j] + dp[i-k][0];
            }
        }
    }
    for (int i=1; i<=l; i++)
        ans += dp[i][1];
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> l >> k;
    cout << Solution() << '\n';
    return 0;
}
