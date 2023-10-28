#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 7;
int n, m, x[MaxN+5];
ll dp[MaxN+5][101];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> x[i];
    }
}

void Init() {
    if (x[1] == 0)
        for (int i=1; i<=m; i++)
            dp[1][i] = 1;
    else
        dp[1][x[1]] = 1;
}

ll ArrayChoices() {
    for (int i=2; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if ((x[i] == 0) || (x[i] == j))
                dp[i][j] = ((dp[i-1][j-1] + dp[i-1][j+1])%Mod + dp[i-1][j])%Mod;
            else
                dp[i][j] = 0;
        }
    }
    ll ans = 0;
    for (int i=1; i<=m; i++)
        ans = (ans + dp[n][i])%Mod;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    Init();
    cout << ArrayChoices();
    return 0;
}
