#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int t, n;
ll dp[MaxN+1][2], pref[MaxN+1]; // dp: 1 is intervals with odd ones, 0 is intervals with even ones
string s;

void MakePref() {
    for (int i=1; i<=n; i++) {
        pref[i] = pref[i-1] + (s[i] == '1');
    }
}

ll Solution() {
    MakePref();
    for (int i=1; i<=n; i++) {
        if (s[i] == '1') {
            dp[i][1] = dp[i-1][0] + 1LL; // +1 is adding [i] to the list
            dp[i][0] = dp[i-1][1];
        }
        else {
            dp[i][1] = dp[i-1][1];
            dp[i][0] = dp[i-1][0] + 1LL;
        }
    }
    ll ans = 0;
    int j = 1;
    for (int i=2; i<=n; i++) {
        if ((pref[i] - pref[j-1])&1LL)
            ans += dp[j-1][0];
        else
            ans += dp[j-1][1];
        if (s[i] == '1')
            j = i; // this is the same as the way I dp for the Thanos Cow (or 1e9*1e9 problem of Mr Synh)
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> s;
        s = ' ' + s;
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
