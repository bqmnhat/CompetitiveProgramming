#include <iostream>
#include <bits/stdc++.h>
#define MaxN 5000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const ll INF = 1e9 + 7;
int n, m;
ll dp[MaxN+5][MaxN+5], x[MaxN+5];
pii a[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> x[i];
    for (int i=1; i<=m; i++)
        cin >> a[i].first >> a[i].second;
}

ll Solution() {
    sort(a+1, a+1+m);
    sort(x+1, x+1+n);
    for (int i=1; i<=n; i++)
        for (int j=0; j<=m; j++)
            dp[i][j] = INF;
    for (int i=1; i<=n; i++) {
        for (int j=i; j<=m; j++) {
            dp[i][j] = min(dp[i][j], dp[i][j-1]);
            dp[i][j] = min(dp[i][j], dp[i-1][j-1] + abs(x[i] - a[j].first));
        }
    }
    return dp[n][m];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    cout << Solution();
    return 0;
}
