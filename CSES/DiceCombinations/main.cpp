#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 7;
int n;
ll dp[MaxN+5];

ll Solution() {
    for (int i=1; i<=n; i++) {
        if (i<=6)
            dp[i] = 1;
        for (int j=1; j<=min(i, 6); j++)
            dp[i] = (dp[i] + dp[i-j])%Mod;
    }
    return dp[n];
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
