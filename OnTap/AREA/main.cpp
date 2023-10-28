#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0,-1,0,1}, dy[4] = {-1,0,1,0}, a[1001][1001],m,n;
bool visited[1001][1001];

void ReadData() {
    char c;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> c;
            if (c == '*')
                a[i][j] = 1;
        }
    }
}

bool Check(int x, int y) {
    return ((x>=1) && (x <= n) && (y>=1) && (y <= m));
}

void DFS(int x, int y)  {
    visited[x][y] = true;
    for (int i=0; i<4; i++) {
        int u = x + dx[i], v = y + dy[i];
        if ((a[u][v] == 1) && (Check(u,v)) && (!visited[u][v])) {
            DFS(u,v);
        }
    }
}

int GrassArea() {
    int ans = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if ((!visited[i][j]) && (a[i][j] == 1)) {
                ans++;
                DFS(i,j);
            }
        }
    }
    return ans;
}

int main()
{
    freopen("AREA.INP", "r", stdin);
    freopen("AREA.OUT", "w", stdout);
    cin >> n >> m;
    ReadData();
    cout << GrassArea();
    return 0;
}
