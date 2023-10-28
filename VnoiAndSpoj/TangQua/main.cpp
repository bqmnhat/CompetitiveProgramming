#include <iostream>
#include <bits/stdc++.h>
#define MaxN 2000
using namespace std;
typedef long long ll;
int n, d, dp[MaxN+1][MaxN+1], idOf[MaxN+1], PrefMax[4*MaxN+1], a[MaxN+1];

void ReadData() {
    n = n*2;
    for (int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
        idOf[a[i]] = i;
    }
}

void UpdateSt(int v, int tl, int tr, int id, int val) {
    if (tl == tr)
        PrefMax[v] = max(PrefMax[v], val);
    else {
        int tm = ((tl + tr) >> 1);
        if (id <= tm)
            UpdateSt(v*2, tl, tm, id, val);
        else
            UpdateSt(v*2+1, tm+1, tr, id, val);
        PrefMax[v] = max(PrefMax[v*2], PrefMax[v*2+1]);
    }
}

int GetMax(int v, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l))
        return 0;
    if ((l <= tl) && (tr <= r))
        return PrefMax[v];
    int tm = ((tl + tr) >> 1);
    return max(GetMax(v*2, tl, tm, l, r), GetMax(v*2+1, tm+1, tr, l, r));
}

int Solution() {
    int ans = 0;
    for (int x=1; x<n; x++) {
        for (int i=1; i<=x; i++) {
            int lb = max((-1)*d, -a[i]), ub = min(d, n - a[i]);
            for (int j=lb; j<=ub; j++) {
                if (idOf[a[i] + j] > x) {
                    dp[i][idOf[a[i] + j]] = GetMax(1, 1, n, 1, idOf[a[i] + j] - 1) + 1;
                    ans = max(ans, dp[i][idOf[a[i] + j]]);
                }
            }
            for (int j = lb; j<=ub; j++)
                if (idOf[a[i] + j] > x)
                    UpdateSt(1, 1, n, idOf[a[i] + j], dp[i][idOf[a[i] + j]]);
        }
        for (int i=1; i<=4*n; i++)
            PrefMax[i] = 0;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    scanf("%d %d", &n, &d);
    ReadData();
    printf("%d", Solution());
    return 0;
}
