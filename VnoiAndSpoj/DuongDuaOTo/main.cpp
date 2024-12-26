#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
typedef long long ll;
int n;
ll dp[MaxN+5], a[MaxN+5], Sum = 0;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        Sum += a[i];
    }
}

ll Solution() {
    if (n <= 3)
        return 0;
    dp[0] = 0;
    dp[1] = a[1];
    dp[2] = a[1] + a[2];
    dp[3] = a[1] + a[2] + a[3];
    for (int i=4; i<=n; i++) {
        dp[i] = max(dp[i-1], dp[i]);
        dp[i] = max(dp[i], max(dp[i-2] + a[i], max(dp[i-3] + a[i] + a[i-1], dp[i-4] + a[i] + a[i-1] + a[i-2])));
    }
    ll ans = Sum - dp[n];
    return ans;
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
