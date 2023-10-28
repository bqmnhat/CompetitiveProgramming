#include <iostream>
#include <bits/stdc++.h>
#define MaxN 25
#define MaxR 25
using namespace std;
typedef long long ll;
int n, t;
ll L, R, dp[MaxN+1][MaxR+1][2];
vector<int> digits;

ll CalDp(const vector<int>& digits) {
    n = digits.size();
    memset(dp, 0, sizeof(dp));
    for (int i=0; i<=digits[0]; i++)
        dp[1][i!=0][i == digits[0]]++;
    for (int i=1; i<n; i++) {
        for (int tight = 0; tight < 2; tight++) {
            for (int j=0; j<=4; j++) {
                if (dp[i][j][tight] == 0)
                    continue;
                int limit = tight ? digits[i] : 9;
                for (int x = 0; x<=limit; x++)
                    dp[i+1][j + (x != 0)][tight && x == limit] += dp[i][j][tight];
            }
        }
    }
    ll ans = 0;
    for (int j=1; j<=3; j++)
        ans += dp[n][j][0] + dp[n][j][1];
    return ans;
}

void SplitData(vector<int>& digits, ll a) {
    digits.clear();
    if (a == 0)
        digits.push_back(0);
    while (a > 0) {
        ll x = a%10;
        a = a/10;
        digits.push_back(x);
    }
    reverse(digits.begin(), digits.end());
}

ll Solution() {
    SplitData(digits, R);
    ll RAns = CalDp(digits);
    SplitData(digits, L-1LL);
    ll LAns = CalDp(digits);
    return (RAns - LAns);
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> L >> R;
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
