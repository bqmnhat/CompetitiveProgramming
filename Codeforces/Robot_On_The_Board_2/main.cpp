#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, m, dist[2001][2001], t, di[256], dj[256];
bool visited[2001][2001], found = false;
string dir[2001];
stack <pair<int,int>> stk;

void MakeDiDj() {
    di['L'] = di['R'] = 0;
    di['U'] = -1;
    di['D'] = 1;
    dj['U'] = dj['D'] = 0;
    dj['L'] = -1;
    dj['R'] = 1;
}

void Init() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            visited[i][j] = false;
            dist[i][j] = 0;
        }
    }
}

bool Check(int x, int y) {
    return ((x >= 1) && (x <= n) && (y >= 1) && (y <= m));
}

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> dir[i];
        dir[i] = " " + dir[i];
    }
}

int DFS(int x, int y) {
    if (!Check(x,y))
        return 0;
    stk.push(make_pair(x,y));
    if (visited[x][y]) {
        found = true;
        return 0;
    }
    visited[x][y] = true;
    if (dist[x][y] == 0)
        dist[x][y] = DFS(x+di[dir[x][y]], y+dj[dir[x][y]]) + 1;
    return dist[x][y];
}

void Solve() {
    int ans = 0, MaxI, MaxJ;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            found = false;
            if (dist[i][j] == 0) {
                dist[i][j] = DFS(i,j);
            }
            if (found) {
                pair<int,int> p, edcycle;
                p = edcycle = stk.top();
                int val = dist[edcycle.first][edcycle.second];
                do {
                    visited[p.first][p.second] = false;
                    stk.pop();
                    dist[p.first][p.second] = val;
                    p = stk.top();
                } while (p != edcycle);
            }
            pair<int,int> p;
            while (!stk.empty()) {
                p = stk.top();
                visited[p.first][p.second] = false;
                stk.pop();
            }
            if (dist[i][j] > ans) {
                ans = dist[i][j];
                MaxI = i;
                MaxJ = j;
            }
        }
    }
    cout << MaxI << " " << MaxJ << " " << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    MakeDiDj();
    for (int i=1; i<=t; i++) {
        cin >> n >> m;
        Init();
        ReadData();
        Solve();
    }
    return 0;
}
