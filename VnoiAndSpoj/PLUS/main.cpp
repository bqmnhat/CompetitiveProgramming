#include <iostream>
#include <bits/stdc++.h>
#define MaxN 15
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 7;
int n, m;
ll a[MaxN+5][MaxN+5], pref[MaxN+5][MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin >> a[i][j];
}

void MakePref() {
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            pref[i][j] = a[i][j] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
}

ll GetSumBox(int i1, int j1, int i2, int j2) {
    if ((i1 < 1) || (j1 < 1) || (i2 < 1) || (j2 < 1) || (i1 > n) || (j1 > m) || (i2 > n) || (j2 > m))
        return 0;
    if ((i1 > i2) || (j1 > j2))
        return 0;
    return (pref[i2][j2] - pref[i1-1][j2] - pref[i2][j1-1] + pref[i1-1][j1-1]);
}

ll GetSumCross(int i, int j, int l) {
    return (GetSumBox(i-l+1, j-l+1, i+l-1, j+l-1) - GetSumBox(i+1, j+1, i+l-1, j+l-1)
            - GetSumBox(i-1, j+l-1, i-l+1, j+1) - GetSumBox(i-l+1, j-l+1, i-1, j-1)
            - GetSumBox(i+1, j-l+1, i+l-1, j-1));
}

bool CheckCollapse(int i1, int j1, int l1, int i2, int j2, int l2) {
    int deltaI = abs(i1 - i2) + 1, deltaJ = abs(j1 - j2) + 1;
    int x1 = max(deltaI, deltaJ), x2 = max(deltaI, deltaJ);
    return ((l1 >= x1) && (l2 >= x2));
}

bool CheckValidCross(int i1, int j1, int l1) {
    return (((i1 - l1 + 1) >= 1) && ((j1 - l1 + 1) >= 1) && ((i1 + l1 - 1) <= n) && (j1 + l1 - 1 <= m));
}

ll Solution() {
    ll ans = -1e18;
    for (int i1=1; i1<=n; i1++) {
        for (int j1=1; j1<=m; j1++) {
            for (int l1=1; l1<=max(n, m); l1++) {
                if (!CheckValidCross(i1, j1, l1))
                    continue;
                for (int i2=1; i2<=n; i2++) {
                    for (int j2=1; j2<=m; j2++) {
                        for (int l2=1; l2<=max(n, m); l2++) {
                            if (!CheckValidCross(i2, j2, l2))
                                continue;
                            if (CheckCollapse(i1, j1, l1, i2, j2, l2))
                                continue;
                            ll Cross1 = GetSumCross(i1, j1, l1);
                            ll Cross2 = GetSumCross(i2, j2, l2);
                            ans = max(ans, Cross1 + Cross2);
                        }
                    }
                }
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    MakePref();
    cout << Solution();
    return 0;
}
