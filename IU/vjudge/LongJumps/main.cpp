#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int t, n;
ll a[MaxN+1], dp[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

ll Solution() {
    ll ans = 0;
    for (int i=n; i>=1; i--) {
        dp[i] = a[i];
        if (i + a[i] <= n)
            dp[i] += dp[i + a[i]];
        ans = max(ans, dp[i]);
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
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
