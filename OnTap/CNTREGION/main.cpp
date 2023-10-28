#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0,-1,0,1}, dy[4] = {-1,0,1,0}, n, m, a[1001][1001];
bool visited[1001][1001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> a[i][j];
        }
    }
}

bool Check(int x, int y) {
    return ((x<=n) && (x>=1) && (y>=1) && (y<=m));
}

int DFS(int x, int y) {
    visited[x][y] = true;
    int ans = 1;
    for (int i=0; i<4; i++) {
        int u = x + dx[i], v = y + dy[i], val = a[x][y];
        if ((Check(u,v)) && (a[u][v] == val) && (!visited[u][v])) {
            ans += DFS(u,v);
        }
    }
    return ans;
}

void CountRegion() {
    int ans = 0;
    int maxsize = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (!visited[i][j]) {
                ans++;
                int Size = DFS(i,j);
                if (Size > maxsize)
                    maxsize = Size;
            }
        }
    }
    cout << ans << '\n' << maxsize;
}

int main()
{
    freopen("CNTREGION.INP", "r", stdin);
    freopen("CNTREGION.OUT", "w", stdout);
    cin >> n >> m;
    ReadData();
    CountRegion();
    return 0;
}
