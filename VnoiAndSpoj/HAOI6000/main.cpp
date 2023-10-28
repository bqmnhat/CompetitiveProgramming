#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
int m, n, a[MaxN+1][MaxN+1], diri[4] = {1, 0, -1, 0}, dirj[4] = {0, 1, 0, -1}, RToL[4] = {3, 2, 1, 0}, LToR[4] = {1, 0, 3, 2}, ans;
const int inf = 1e9 + 7;
map<int, int> ma;

void ReadData() {
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            cin >> a[i][j];
}

bool Check(int x, int y) {
    return ((x >= 1) && (x <= m+1) && (y >= 1) && (y <= n));
}

int DFS(int x, int y, int dir) {
    if (x == m+1)
        return 0;
    if (a[x][y] == 0)
        dir = LToR[dir];
    else
        dir = RToL[dir];
    int NewX = x + diri[dir], NewY = y + dirj[dir];
    if (Check(NewX, NewY))
        return DFS(NewX, NewY, dir) + 1;
    else
        return inf;
}

void Solve() {
    ans = inf+1;
    for (int i=1; i<=n; i++) {
        int tmp = DFS(1, i, 0);
        ma[tmp]++;
        ans = min(ans, tmp);
    }
    if (ans >= inf) {
        cout << "0 0";
        return;
    }
    cout << ans << ' ' << ma[ans];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    ReadData();
    Solve();
    return 0;
}
