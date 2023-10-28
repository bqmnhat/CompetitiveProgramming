#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int n, k, h[MaxN+1], dp[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> h[i];
}

int Solution() {
    dp[1] = 0;
    for (int i=2; i<=n; i++) {
        dp[i] = 1e9;
        for (int j=1; j<=k; j++) {
            if (i - j < 1)
                break;
            dp[i] = min(dp[i], dp[i-j] + abs(h[i] - h[i-j]));
        }
    }
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    ReadData();
    cout << Solution();
    return 0;
}
