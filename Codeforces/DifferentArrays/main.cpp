#include <iostream>
#include <bits/stdc++.h>
#define MaxN 300
#define MaxVal 90000
using namespace std;
typedef long long ll;
const ll Mod = 998244353;
int n;
ll a[MaxN+5], dp[MaxN+5][2*MaxVal+5];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

ll Solution() {
    dp[1][a[1]+MaxVal] = dp[2][a[2]+MaxVal] = 1;
    for (int i=3; i<=n; i++) {
        for (int val = 0; val <= 2*MaxVal; val++) {
            if (val - a[i]>= 0) {
                dp[i][val] = (dp[i][val] + dp[i-1][val - a[i]])%Mod;
                if ((a[i] + 2*MaxVal - val >= 0) && (a[i] + MaxVal != val))
                    dp[i][val] = (dp[i][val] + dp[i-1][a[i] + 2*MaxVal - val])%Mod;
            }
        }
    }
    ll ans = 0;
    for (int val = 0; val <= 2*MaxVal; val++)
        ans = (ans + dp[n][val])%Mod;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
