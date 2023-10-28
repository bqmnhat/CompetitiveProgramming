#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
int n, m, k, CCCount = 0, InWhichCC[MaxN+1][MaxN+1], CCPaintings[MaxN*MaxN+1], diri[4] = {-1, 0, 1, 0}, dirj[4] = {0, 1, 0, -1}, Paintings[MaxN+1][MaxN+1];
bool vis[MaxN+1][MaxN+1];
string s[MaxN];

void ReadData() {
    for (int i = 0; i<n; i++)
        cin >> s[i];
}

void PaintingsCnt() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (s[i][j] != '.')
                continue;
            if ((i > 0) && (s[i-1][j] == '*'))
                Paintings[i][j]++;
            if ((j > 0) && (s[i][j-1] == '*'))
                Paintings[i][j]++;
            if ((i < n-1) && (s[i+1][j] == '*'))
                Paintings[i][j]++;
            if ((j < m-1) && (s[i][j+1] == '*'))
                Paintings[i][j]++;
        }
    }
}

bool Check(int x, int y) {
    return ((x >= 0) && (x < n) && (y >= 0) && (y < m) && (s[x][y] == '.') && (!vis[x][y]));
}

void DFS(int x, int y) {
    CCPaintings[CCCount] += Paintings[x][y];
    InWhichCC[x][y] = CCCount;
    for (int i=0; i<=3; i++) {
        int NewX = x + diri[i], NewY = y + dirj[i];
        if (Check(NewX, NewY)) {
            vis[NewX][NewY] = true;
            DFS(NewX, NewY);
        }
    }
}

void FindAllCC() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if ((!vis[i][j]) && (s[i][j] == '.')) {
                CCCount++;
                vis[i][j] = true;
                DFS(i, j);
            }
        }
    }
}

void Solve() {
    for (int i=1; i<=k; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        cout << CCPaintings[InWhichCC[x][y]] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    ReadData();
    PaintingsCnt();
    FindAllCC();
    Solve();
    return 0;
}
