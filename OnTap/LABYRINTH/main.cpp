#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int m,n,dx[4] = {0,-1,0,1},dy[4] = {-1,0,1,0}, dir[1000001], ld = 0, xx, yy;
int a[1001][1001];
char b[4] = {'W', 'N', 'E', 'S'};
bool visited[1001][1001];

bool check(int x, int y) {
    return ((x<=m) && (x>=1) && (y<=n) && (y>=1));
}

void ReadData() {
    char c;
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            cin >> c;
            if (c == '*') {
                xx = i;
                yy = j;
            }
            if (c == '#')
                a[i][j] = 1;
        }
    }
}

bool WayOut(int x, int y) {
    visited[x][y] = true;
    bool ans = false;
    if ((x==1) || (x==m) || (y==1) || (y==n)) {
        return true;
    }
    for (int i=0; i<4; i++) {
        int u = x + dx[i], v = y + dy[i];
        if ((!visited[u][v]) && (a[u][v] == 0) && (check(u,v))) {
            bool tmp = WayOut(u,v);
            if (tmp == true)
                ans = tmp;
            if (ans == true) {
                ld++;
                dir[ld] = i;
                return ans;
            }
        }
    }
    return ans;
}

void Solve() {
    WayOut(xx,yy);
    for (int i=ld; i>=1; i--) {
        cout << b[dir[i]];
    }
}

int main()
{
    freopen("LABYRINTH.INP", "r", stdin);
    freopen("LABYRINTH.OUT", "w", stdout);
    cin >> m >> n;
    ReadData();
    Solve();
    return 0;
}
