#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, p[11], w, dp[101], a[7] = {0, 1, 2, 5, 10, 15, 20}, sum = 0;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> p[i];
        sum += p[i];
    }
}

void CalDp() {
    for (int i=1; i<=w; i++)
        dp[i] = 1e9;
    for (int j=1; j<=w; j++) {
        for (int i=1; i<=6; i++)
            if (j - a[i] >= 0)
                dp[j] = min(dp[j], dp[j-a[i]] + 1);
    }
}

int Solution() {
    int ans = 1e9, cnt = 0;
    if (w - sum >= 0)
        ans = min(ans, dp[w-sum]);
    for (int i=n; i>=1; i--) {
        cnt++;
        sum = sum - p[i];
        if (w - sum >= 0)
            ans = min(ans, cnt + dp[w - sum]);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cin >> w;
    CalDp();
    cout << Solution();
    return 0;
}
