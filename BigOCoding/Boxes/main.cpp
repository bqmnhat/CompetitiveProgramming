#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, w[1001], l[1001], dp[6001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> w[i] >> l[i];
}

int Solution() {
    memset(dp, 0, sizeof(dp));
    for (int i=n; i>=1; i--) {
        for (int j=l[i]; j>=0; j--)
            dp[j + w[i]] = max(dp[j+w[i]], dp[j] + 1);
        if (dp[w[i]] == 0)
            dp[w[i]] = 1;
    }
    int ans = 0;
    for (int j = 1; j<=6000; j++)
        ans = max(ans, dp[j]);
    return ans;
}

void Solve() {
    while ((cin >> n) && (n != 0)) {
        ReadData();
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
