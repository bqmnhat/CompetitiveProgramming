#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100
using namespace std;
typedef long long ll;
const ll Mod = 1e9;
int m, n;
ll a[MaxN+5][MaxN+5], dp[MaxN+5][MaxN+5];

void ReadData() {
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            cin >> a[i][j];
}

ll Solution() {
    for (int i=1; i<=m; i++)
        dp[i][1] = 1;
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            for (int PreI=1; PreI<=i; PreI++)  {
                for (int PreJ = 1; PreJ <= j; PreJ++) {
                    if ((PreI == i) && (PreJ == j))
                        continue;
                    if (PreI + PreJ >= i + j)
                        continue;
                    if ((PreJ < n) && (__gcd(a[i][j], a[PreI][PreJ]) > 1))
                        dp[i][j] = (dp[i][j] + dp[PreI][PreJ])%Mod;
                }
            }
        }
    }
    ll res = 0;
    for (int i=1; i<=m; i++)
        res = (res + dp[i][n])%Mod;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    ReadData();
    cout << Solution();
    return 0;
}
