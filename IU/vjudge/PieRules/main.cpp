#include <iostream>
#include <bits/stdc++.h>
#define MaxN 50
using namespace std;
int n, a[MaxN+1], sum[MaxN+2], dp[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=n; i>=1; i--)
        sum[i] = sum[i+1] + a[i];
}

void Solve() {
    dp[n]= a[n];
    for (int i=n-1; i>=1; i--)
        dp[i] = max(a[i] + sum[i+1] - dp[i+1], dp[i+1]);
    cout << sum[1] - dp[1] << ' ' << dp[1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
