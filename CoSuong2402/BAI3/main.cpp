#include <iostream>
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int m, n, a[101][101];
ll dp[101][101];

void ReadData() {
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            cin >> a[i][j];
}

bool IsPrime(int x) {
    int tmp = sqrt(x);
    if ((x == 0) || (x == 1))
        return false;
    for (int i=2; i<=tmp; i++)
        if (x % i == 0)
            return false;
    return true;
}

ll Solution() {
    dp[1][1] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if ((i == 1) && (j == 1))
                continue;
            if (IsPrime(abs(a[i][j] - a[i-1][j])))
                dp[i][j] = (dp[i][j]%MOD + dp[i - 1][j]%MOD)%MOD;
            if (IsPrime(abs(a[i][j] - a[i][j-1])))
                dp[i][j] = (dp[i][j]%MOD + dp[i][j - 1]%MOD)%MOD;
        }
    }
    return dp[m][n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("BAI3.INP", "r", stdin);
    freopen("BAI3.OUT", "w", stdout);
    cin >> m >> n;
    ReadData();
    cout << Solution();
    return 0;
}
