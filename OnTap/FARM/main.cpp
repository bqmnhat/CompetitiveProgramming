#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int m,n,dx[4] = {0,-1,0,1}, dy[4] = {-1,0,1,0};
char a[1001][1001];
bool visited[1001][1001];

bool check(int x, int y) {
    return ((x<=m) && (x>=1) && (y<=n) && (y>=1));
}

void ReadData() {
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            cin >> a[i][j];
        }
    }
}

void FoxVsChick(int x, int y, int& f, int &c) {
    visited[x][y] = true;
    if (a[x][y] == 'c')
        c++;
    else if (a[x][y] == 'f')
        f++;
    for (int i=0; i<4; i++) {
        int u = x+dx[i], v = y+dy[i];
        if ((a[u][v] != '#') && (!visited[u][v]) && (check(u,v))) {
            FoxVsChick(u,v,f,c);
        }
    }
}

void Solve() {
    int ansf = 0, ansc = 0;
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            if ((!visited[i][j]) && (a[i][j] != '#')) {
                int f = 0,c = 0;
                FoxVsChick(i,j,f,c);
                if (c>f)
                    ansc += c;
                else
                    ansf += f;
            }
        }
    }
    cout << ansf << " " << ansc;
}

int main()
{
    freopen("FARM.INP", "r", stdin);
    freopen("FARM.OUT", "w", stdout);
    cin >> m >> n;
    ReadData();
    Solve();
    return 0;
}
