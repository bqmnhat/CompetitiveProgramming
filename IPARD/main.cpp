#include <iostream>
#include <bits/stdc++.h>
#define MOD 123456789
using namespace std;
typedef long long ll;
int n;
ll dp[5001][5001];

int Solution() {
    for (int i=0; i<=n; i++)
        dp[i][0] = 1;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            dp[i][j] = dp[i-1][j] + dp[i-1][j-i];
   return dp[n][n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cout << Solution();
    return 0;
}
