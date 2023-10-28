#include <iostream>
#include <bits/stdc++.h>
#define MaxN 3010
using namespace std;
typedef long long ll;
int n;
ll dp[MaxN+1][MaxN+1], st[4*MaxN+1];
string s;
const ll Mod = 1e9 + 7;

void UpdateSt(int v, int tl, int tr, int id, ll val) {
    if (tl == tr)
        st[v] = val;
    else {
        int tm = ((tl + tr) >> 1);
        if (id <= tm)
            UpdateSt(v*2, tl, tm, id, val);
        else
            UpdateSt(v*2+1, tm+1, tr, id, val);
        st[v] = (st[v*2] + st[v*2+1])%Mod;
    }
}

ll GetSum(int v, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l))
        return 0;
    if ((l <= tl) && (tr <= r))
        return st[v];
    int tm = ((tl + tr) >> 1);
    return ((GetSum(v*2, tl, tm, l, r) + GetSum(v*2+1, tm+1, tr, l, r))%Mod);
}

ll Solution() {
    s = ' ' + s;
    dp[0][1] = 1;
    UpdateSt(1, 1, n, 1, 1);
    for (int i=1; i<n; i++) {
        for (int j=1; j<=i+1; j++) {
            if (s[i] == '>')
                dp[i][j] = (dp[i][j] + GetSum(1, 1, n, j, i))%Mod;
            else
                dp[i][j] = (dp[i][j] + GetSum(1, 1, n, 1, j-1))%Mod;
        }
        for (int j=1; j<=i+1; j++)
            UpdateSt(1, 1, n, j, dp[i][j]);
    }
    ll ans = 0;
    for (int i=1; i<=n; i++)
        ans = (ans + dp[n-1][i])%Mod;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    cout << Solution();
    return 0;
}
