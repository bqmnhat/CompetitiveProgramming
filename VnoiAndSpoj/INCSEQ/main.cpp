#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10000
#define MaxAi 100000
#define MaxK 50
using namespace std;
typedef long long ll;
int n, k, st[MaxK+1][4*MaxAi+1], a[MaxN+1];
const int Mod = 5000000;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void UpdateSt(int StId, int v, int tl, int tr, int id, int val) {
    if (tl == tr)
        st[StId][v] = (st[StId][v] + val)%Mod;
    else {
        int tm = (tl + tr)/2;
        if (id <= tm)
            UpdateSt(StId, v*2+1, tl, tm, id, val);
        else
            UpdateSt(StId, v*2+2, tm+1, tr, id, val);
        st[StId][v] = st[StId][v*2+1] + st[StId][v*2+2];
        while (st[StId][v] >= Mod)
            st[StId][v] = st[StId][v] - Mod;
    }
}

int SumQuery(int StId, int v, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l))
        return 0;
    if ((l <= tl) && (tr <= r))
        return st[StId][v];
    int tm = (tl + tr)/2;
    int ans = SumQuery(StId, v*2+1, tl ,tm, l, r) + SumQuery(StId, v*2+2, tm+1, tr, l, r);
    while (ans >= Mod)
        ans -= Mod;
    return ans;
}

ll Solution() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=k; j++) {
            if (j == 1)
                UpdateSt(j, 0, 0, MaxAi, a[i], 1);
            else {
                ll tmp = SumQuery(j-1, 0, 0, MaxAi, 0, a[i]-1);
                UpdateSt(j, 0, 0, MaxAi, a[i], tmp);
            }
        }
    }
    return st[k][0];
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
