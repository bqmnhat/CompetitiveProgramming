#include <iostream>
#include <bits/stdc++.h>
#define MaxN 2005
using namespace std;
typedef long long ll;
int n, b;
ll dp[MaxN+1][MaxN+1], a[MaxN+1];
const ll Mod = 1e9 + 7;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

ll Solution() {
    dp[n+1][0] = 1;
    for (int i=n; i>=1; i--) {
        for (int j=0; j<=b; j++) {
            if (a[i] == 0)
                dp[i][j] = dp[i+1][j];
            else if ((a[i] != -1) && (a[i] <= b - j + 1))
                    dp[i][j] = dp[i+1][j-1];
            else if (a[i] == -1)
                dp[i][j] = (dp[i+1][j] + (dp[i+1][j-1]*min(1LL*i-1LL, 1LL*(b - j + 1)))%Mod)%Mod;
        }
    }
    ll ans = 0;
    for (int j=0; j<=b; j++)
        ans = (ans + dp[1][j])%Mod;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("GRAPH.INP", "r", stdin);
    //freopen("GRAPH.OUT", "w", stdout);
    cin >> n >> b;
    ReadData();
    cout << Solution();
    return 0;
}
