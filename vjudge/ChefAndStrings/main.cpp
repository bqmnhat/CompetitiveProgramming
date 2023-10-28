#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
int t, n;
string s;
ll dp[MaxN+1];

ll Solution() {
    dp[0] = dp[1] = 0;
    for (int i=2; i<=n; i++) {
        dp[i] = dp[i-1];
        if (s[i-1] != s[i-2])
            dp[i] = max(dp[i], dp[i-2] + 1LL);
    }
    return dp[n];
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> s;
        n = s.length();
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
