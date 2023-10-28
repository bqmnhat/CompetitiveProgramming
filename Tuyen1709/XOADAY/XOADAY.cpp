#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
typedef long long ll;
int n;
ll D[MaxN+1], dp[MaxN+1];
string s;

void ReadData() {
    cin >> s;
    s = ' ' + s;
    for (int i=1; i<=n; i++)
        cin >> D[i];
}

ll Solution() {
    ll ans = 0;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=i; j++)
            dp[i] = max(dp[i], dp[i - j] + D[j]);
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("XOADAY.INP", "r", stdin);
    freopen("XOADAY.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
