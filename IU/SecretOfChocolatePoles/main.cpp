#include <iostream>
#include <bits/stdc++.h>
#define MaxL 100
using namespace std;
typedef long long ll;
int l, k;
ll dp[2][MaxL+1];
bool vis[2][MaxL+1];

ll Dp(int top, int h) {
    if (h < 0)
        return 0;
    if (vis[top][h])
        return dp[top][h];
    vis[top][h] = true;
    if (top == 0)
        dp[top][h] = Dp(1-top, h-1);
    else
        dp[top][h] = Dp(1-top, h-1) + Dp(1-top, h-k);
    return dp[top][h];
}

ll Solution() {
    dp[1][1] = dp[0][0] = dp[1][0] = 1;
    vis[1][1] = vis[0][1] = vis[0][0] = vis[1][0] = true;
    dp[0][l] = Dp(0, l);
    dp[1][l] = Dp(1, l);
    ll ans = 0;
    for (int i=1; i<=l; i++)
        ans += dp[1][i];
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> l >> k;
    cout << Solution();
    return 0;
}
