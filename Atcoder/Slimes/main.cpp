#include <iostream>
#include <bits/stdc++.h>
#define MaxN 405
using namespace std;
typedef long long ll;
int n;
ll dp[MaxN+1][MaxN+1], a[MaxN+1], pref[MaxN+1];
const ll INF = 1e18 + 7;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        pref[i] = pref[i-1] + a[i];
    }
}

void Init() {
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            dp[i][j] = -1;
}

ll CalDp(int i, int j) {
    if (i == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    dp[i][j] = INF;
    for (int k=i; k<j; k++)
        dp[i][j] = min(CalDp(i, k) + CalDp(k+1,j) + pref[j] - pref[i-1], dp[i][j]);
    return dp[i][j];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    Init();
    cout << CalDp(1, n);
    return 0;
}
