#include <iostream>
#include <bits/stdc++.h>
#define MaxN 2000
#define MaxR 2000
using namespace std;
typedef long long ll;
int n, m, d;
ll dpA[MaxN+1][MaxR+1][2], dpB[MaxN+1][MaxR+1][2];
string a, b;
const ll Mod = 1e9 + 7;

ll CalDp(string s, int n, ll dp[MaxN+1][MaxR+1][2]) {
    for (int i=0; i<=(s[0] - '0'); i++)
        dp[1][i%m][i == (s[0] - '0')] = 1;
    for (int i=1; i<n; i++) {
        for (int tight = 0; tight < 2; tight++) {
            for (int j=0; j<m; j++) {
                if (!dp[i][j][tight])
                    continue;
                if (!((i+1)&1)) {
                    dp[i+1][(j + d)%m][d == (s[i] - '0')] = (dp[i+1][(j + d)%m][d == (s[i] - '0')] + dp[i][j][tight])%Mod;
                    continue;
                }
                int limit = tight ? (s[i] - '0') : 9;
                for (int x = 0; x<=limit; x++)
                    dp[i+1][(j + x)%m][x == (s[i] - '0')] = (dp[i+1][(j + x)%m][x == (s[i] - '0')] + dp[i][j][tight])%Mod;
            }
        }
    }
    return (dp[n][0][0] + dp[n][0][1])%Mod;
}

ll Solution() {
    n = a.length();
    if (n == 1) {
        if (d != 0)
            return 0;
        return (b[0] - a[0] + 1);
    }
    // a - 1 calculation
    int i = n - 1;
    while ((a[i] == '0') && (i >= 0)) {
        a[i] = '9';
        i--;
    }
    a[i]--;
    ll ansB = CalDp(b, n, dpB), ansA = CalDp(a, n, dpA);
    ll ans = (ansB - ansA + Mod)%Mod;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> d >> a >> b;
    cout << Solution();
    return 0;
}
