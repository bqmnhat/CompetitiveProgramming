#include <iostream>
#include <bits/stdc++.h>
#define MaxN 18
#define MaxDig 9
using namespace std;
typedef long long ll;
ll a, b;
ll dp[MaxN+5][2][2][MaxDig + 5];

void ExtractingDigits(ll x, vector<int>& digits) {
    digits.clear();
    if (x < 0) {
        digits.push_back(-1);
        return;
    }
    while (x > 0LL) {
        digits.push_back(x%10);
        x /= 10;
    }
    reverse(digits.begin(), digits.end());
}

ll FromZeroToX(const vector<int>& digits) {
    if (digits.size() == 0)
        return 1;
    if (digits[0] == -1)
        return 0;
    memset(dp, 0, sizeof(dp));
    int n = digits.size();
    for (int d=0; d<=digits[0]; d++)
        dp[0][d == digits[0]][d == 0][d] = 1;
    for (int i=0; i<n-1; i++) {
        for (int tight = 0; tight < 2; tight++) {
            for (int zero = 0; zero < 2; zero++) {
                for (int cur = 0; cur < 10; cur++) {
                    if (dp[i][tight][zero][cur] == 0)
                        continue;
                    int limit = 9;
                    if (tight)
                        limit = digits[i+1];
                    for (int nxt=0; nxt<=limit; nxt++) {
                        if ((nxt == cur) && (!zero))
                            continue;
                        int NewTight = tight && (nxt == digits[i+1]);
                        int NewZero = zero && (nxt == 0);
                        dp[i+1][NewTight][NewZero][nxt] += dp[i][tight][zero][cur];
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (int tight = 0; tight < 2; tight++)
        for (int zero = 0; zero < 2; zero++)
            for (int cur = 0; cur < 10; cur++)
                ans += dp[n-1][tight][zero][cur];
    return ans;
}

ll Solution() {
    vector<int> digits;
    ExtractingDigits(a-1LL, digits);
    ll ZeroToA = FromZeroToX(digits);
    ExtractingDigits(b, digits);
    ll ZeroToB = FromZeroToX(digits);
    return ZeroToB - ZeroToA;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;
    cout << Solution();
    return 0;
}
