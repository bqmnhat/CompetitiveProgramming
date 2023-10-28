#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n;
map <pii, int> dp;
map <pii, pii> mark;

ll LCM(ll a, ll b) {
    return ((a*b)/__gcd(a, b));
}

int DFS(int x, ll CurrLCM) {
    if (x == 0)
        return CurrLCM;
    if (x < 0)
        return 0;
    if (dp.find({x, CurrLCM}) != dp.end())
        return dp[{x, CurrLCM}];
    ll ans = 0;
    for (int i=1; i<=x; i++) {
        if (__gcd(CurrLCM, 1LL*i) != 1)
            continue;
        ll NextLCM = LCM(CurrLCM, i);
        ll tmp = DFS(x - i, NextLCM);
        if (tmp > ans) {
            ans = tmp;
            mark[{x, CurrLCM}] = {x-i, NextLCM};
        }
    }
    return (dp[{x, CurrLCM}] = ans);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("ROBOT.INP", "r", stdin);
    freopen("ROBOT.OUT", "w", stdout);
    cin >> n;
    cout << DFS(n, 1);
    return 0;
}

