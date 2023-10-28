#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll dp[11][151], cost[11];

void ReadData() {
    for (int i=1; i<=10; i++)
        cin >> cost[i];
}

void Solve() {
    for (int i=0; i<=10; i++)
        for (int j=1; j<=n; j++)
            dp[i][j] = 1e9;
    for (int i=1; i<=10; i++) {
        for (int j=1; j<=n; j++) {
            dp[i][j] = min(dp[i][j], dp[i-1][j]);
            if (j - i >= 0)
                dp[i][j] = min(dp[i][j], dp[i][j-i] + cost[i]);
        }
    }
    int j = n, i = 10;
    vector<int> res;
    while ((i > 0) && (j > 0)) {
        if (dp[i][j] == dp[i][j-i] + cost[i]) {
            res.push_back(i);
            j = j - i;
        } else
            i--;
    }
    reverse(res.begin(), res.end());
    for (auto x: res)
        cout << x << '\n';
    cout << dp[10][n] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CHEAPBUS.INP", "r", stdin);
    freopen("CHEAPBUS.OUT", "w", stdout);
    ReadData();
    cin >> n;
    Solve();
    return 0;
}
