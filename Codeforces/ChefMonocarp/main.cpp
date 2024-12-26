#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200
using namespace std;
typedef long long ll;
const ll INF = 908654317000;
int q, n;
ll t[MaxN+5], dp[MaxN+5][2*MaxN + 5];

void ReadData() {
    for (int i = 1; i <= n; i++)
        cin >> t[i];
}

void InitDp() {
    for (int i = 0;  i <= n; i++) {
        for (int j = 0; j <= 2*n; j++) {
            dp[i][j] = INF;
        }
    }
}

ll Solution() {
    sort(t + 1, t + 1 +n);
    InitDp();
    for (int i = 0; i <= n; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 2*n; j++) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + abs(j - t[i]));
            dp[i][j] = min(dp[i][j], dp[i][j - 1]);
        }
    }
    return dp[n][2*n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> q;
    while (q--) {
        cin >> n;
        ReadData();
        cout << Solution() << '\n';
    }
    return 0;
}
