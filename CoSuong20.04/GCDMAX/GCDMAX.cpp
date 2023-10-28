#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, Base = 1;
ll a[50001], dp[3][50001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

ll Solution() {
    dp[0][1] = a[1]-1;
    dp[1][1] = a[1];
    dp[2][1] = a[1]+1;
    for (int i=2; i<=n; i++) {
        for (int j=-1; j<=1; j++) {
            ll tmp1, tmp2, tmp3;
            if (dp[0][i-1] == 0)
                tmp1 = 0;
            else
                tmp1 = __gcd(dp[0][i-1], a[i]+j);
            if (dp[1][i-1] == 0)
                tmp2 = 0;
            else
                tmp2 = __gcd(dp[1][i-1], a[i]+j);
            if (dp[2][i-1] == 0)
                tmp3 = 0;
            else
                tmp3 = __gcd(dp[2][i-1], a[i]+j);
            if (a[i] + j > 0)
                dp[j+Base][i] = max(tmp1, max(tmp2, tmp3));
        }
    }
    return max(dp[0][n], max(dp[1][n], dp[2][n]));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("GCDMAX.INP", "r", stdin);
    freopen("GCDMAX.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
