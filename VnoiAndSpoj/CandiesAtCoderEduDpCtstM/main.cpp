#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100
#define MaxK 100005
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 7;
int n, k;
ll a[MaxN+5], SumFromZero[MaxK+5], dp[MaxN+5][MaxK+5];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

/*void UpdateSt(int v, int tl, int tr, int id, ll val) {
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
        return 0LL;
    if ((l <= tl) && (tr <= r))
        return st[v];
    int tm = ((tl + tr) >> 1);
    return (GetSum(v*2, tl, tm, l, r) + GetSum(v*2+1, tm+1, tr, l, r))%Mod;
}*/

ll Solution() {
    for (int i=0; i<=k; i++) {
        if (i <= a[1])
            dp[1][i] = 1;
        else
            dp[1][i] = 0;
        if (i == 0)
            SumFromZero[i] = dp[1][i];
        else
            SumFromZero[i] = (SumFromZero[i-1] + dp[1][i])%Mod;
    }
    for (int i=2; i<=n; i++) {
        for (int j=0; j<=k; j++) {
            ll tmp = SumFromZero[j];
            if (j <= a[i])
                tmp = SumFromZero[j];
            else
                tmp = (SumFromZero[j] - SumFromZero[j - a[i] - 1] + Mod)%Mod;
            dp[i][j] = tmp;
        }
        SumFromZero[0] = dp[i][0];
        for (int j=1; j<=k; j++)
            SumFromZero[j] = (SumFromZero[j-1] + dp[i][j])%Mod;
    }
    return dp[n][k];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    ReadData();
    cout << Solution();
    return 0;
}
