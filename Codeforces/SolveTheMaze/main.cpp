#include <iostream>
#include <bits/stdc++.h>
#define MaxN 50
using namespace std;
typedef pair<int, int> pii;
int t, n, m, di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1}, cntB;
string a[MaxN+5];
bool vis[MaxN+5][MaxN+5];
vector<pii> Gpos, Bpos;

void ReadData() {
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] == 'B')
                Bpos.push_back(pii(i, j));
            if (a[i][j] == 'G')
                Gpos.push_back(pii(i, j));
        }
    }
}

bool IsValid(int x, int y) {
    return ((x >= 0) && (y >= 0) && (x < n) && (y < m) && (a[x][y] != '#'));
}

void BFS(pii src) {
    queue<pii> q;
    q.push(src);
    memset(vis, false, sizeof(vis));
    if (a[src.first][src.second] == '#')
        return;
    vis[src.first][src.second] = true;
    while (!q.empty()) {
        pii tmp = q.front();
        q.pop();
        int x = tmp.first, y = tmp.second;
        for (int i=0; i<4; i++) {
            int NewX = x + di[i], NewY = y + dj[i];
            if ((IsValid(NewX, NewY)) && (!vis[NewX][NewY])) {
                vis[NewX][NewY] = true;
                q.push(pii(NewX, NewY));
            }
        }
    }
}

bool Solution() {
    for (pii tmp: Bpos) {
        for (int i=0; i<4; i++) {
            int x = tmp.first + di[i], y = tmp.second + dj[i];
            if ((IsValid(x, y)) && (a[x][y] == 'G'))
                return false;
            if ((IsValid(x, y)) && (a[x][y] == '.'))
                a[x][y] = '#';
        }
    }
    BFS(pii(n-1, m-1));
    for (pii tmp: Gpos)
        if (!vis[tmp.first][tmp.second])
            return false;
    return true;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        Gpos.clear();
        Bpos.clear();
        cin >> n >> m;
        ReadData();
        if (Solution())
            cout << "Yes";
        else
            cout << "No";
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
