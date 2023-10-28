#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10000
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
int n, dp[MaxN + 5][MaxN/2 + 5];;
pii a[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i].first >> a[i].second;
}

void Init() {
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            dp[i][j] = INF;
}

int Solution() {
    Init();
    dp[0][0] = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i/2; j++) {
            dp[i][j] = min(dp[i][j], dp[i-1][j-1] + a[i].first);
            dp[i][j] = min(dp[i][j], dp[i-1][j] + a[i].second);
        }
        dp[i][0] = dp[i-1][0] + a[i].second;
    }
    return dp[n][n/2];
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
