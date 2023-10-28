#include <iostream>
#include <bits/stdc++.h>
#define MaxN 500
using namespace std;
typedef long long ll;
int n, k, t;
ll r[MaxN+1], spTabMin[MaxN+1][20], log_2[MaxN+1], dp[MaxN+1][MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> r[i];
        spTabMin[i][0] = r[i];
    }
}

void MakeLog2() {
    for (int i=2; i<=MaxN; i++)
        log_2[i] = log_2[i/2] + 1;
}

void MakeSpTab() {
    for (int j=1; (1 << j) <= n; j++) {
        int step = (1 << (j - 1));
        for (int i=1; i+(2*step) <= n+1; i++)
            spTabMin[i][j] = min(spTabMin[i][j-1], spTabMin[i+step][j-1]);
    }
}

ll MinQuery(int l, int r) {
    int k = log_2[r-l+1];
    return min(spTabMin[l][k], spTabMin[r-(1<<k)+1][k]);
}

ll Solution() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=k; j++) {
            dp[i][j] = dp[i-1][j];
            int UB = min(i, t);
            for (ll x = 1LL; x <= UB; x++)
                dp[i][j] = max(dp[i][j], dp[i-x][j-1] + (x * MinQuery(i-x+1, i)));
        }
    }
    ll ans = 0;
    for (int j=0; j<=k; j++)
        ans = max(ans, dp[n][j]);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k >> t;
    ReadData();
    MakeLog2();
    MakeSpTab();
    cout << Solution();
    return 0;
}
