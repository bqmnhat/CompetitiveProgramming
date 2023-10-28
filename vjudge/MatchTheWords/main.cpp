#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
typedef long long ll;
int t, n;
ll dp[MaxN+1];
const ll Mod = 1e9 + 7;

void CalDp() {
    dp[1] = 0;
    dp[2] = 1;
    for (int i=3; i<=MaxN; i++)
        dp[i] = ((i - 1LL)*1LL*(dp[i-1] + dp[i-2]))%Mod;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        cout << dp[n] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    CalDp();
    Solve();
    return 0;
}
