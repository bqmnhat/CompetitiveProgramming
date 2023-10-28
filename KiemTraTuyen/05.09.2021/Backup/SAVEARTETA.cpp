#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MaxN 100
int n, x, h[MaxN+1], s[MaxN+1], k[MaxN+1];
long long f[101][100001], sl[101][100001], t[101];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> h[i];
    for (int i=1; i<=n; i++)
        cin >> s[i];
    for (int i=1; i<=n; i++)
        cin >> k[i];
    for (int i=1; i<=n; i++)
        t[i] = min(x/h[i], k[i]);
}

long long MaxVal() {
    long long ans = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=x; j++) {
            if ((j < h[i]) || (sl[i][j-h[i]] == t[i]))
                f[i][j] = f[i-1][j];
            else
                f[i][j] = max(f[i-1][j], f[i][j-h[i]] + s[i]);
            if (f[i][j] == f[i][j-h[i]] + s[i])
                sl[i][j] = sl[i][j-h[i]] + 1;
        }
    }
    for (int i=1; i<=x; i++)
        if ((f[n][i] > ans) && (sl[n][i] <= t[n]))
            ans = f[n][i];
    return ans;
}

int main()
{
    freopen("SAVEARTETA.INP", "r", stdin);
    freopen("SAVEARTETA.OUT", "w", stdout);
    cin >> n >> x;
    ReadData();
    cout << MaxVal();
    return 0;
}
