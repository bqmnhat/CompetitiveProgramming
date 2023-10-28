#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int t, k, n;
ll a[MaxN+1], pref[MaxN+1], dp[MaxN+1][2];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        pref[i] = pref[i-1] + a[i];
    }
}

ll Solution() {
    for (int i=1; i<=n; i++) {
        for (int state = 0; state <= 1; state++) {
            ll tmp;
            if (state == 0)
                tmp = -1;
            else
                tmp = 1;
            dp[i][state] = dp[i-1][state];
            if (i - k >= 0)
                dp[i][state] = max(dp[i-1][state], tmp*(pref[i] - pref[i-k]) + dp[i-k][(1 - state)]);
        }
    }
    return max(dp[n][0], dp[n][1]);
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> k;
        ReadData();
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
