#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0,-1,0,1}, dy[4] = {-1,0,1,0}, m, n, a[101][101];
bool visited[101][101];

void ReadData() {
    char c;
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            cin >> c;
            if (c == '#')
                a[i][j] = 1;
        }
    }
}

bool check(int x, int y) {
    return ((x>=1) && (x<=m) && (y>=1) && (y<=n));
}

void DFS(int x, int y) {
    visited[x][y] = true;
    for (int i=0; i<4; i++) {
        int u = x + dx[i], v = y + dy[i];
        if ((a[u][v] == 1) && (!visited[u][v]) && (check(u,v)))
            DFS(u,v);
    }
}

int PaperCut() {
    int ans = 0;
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
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
    freopen("REMSQR.INP", "r", stdin);
    freopen("REMSQR.OUT", "w", stdout);
    cin >> m >> n;
    ReadData();
    cout << PaperCut();
    return 0;
}
