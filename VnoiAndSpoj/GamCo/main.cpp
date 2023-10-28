#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100
using namespace std;
typedef pair<int, int> pii;
int n, m, bx, by, cx, cy, dist[MaxN+5][MaxN+5];
int diri[4] = {0, -1, 0, 1}, dirj[4] = {-1, 0, 1, 0};
string s[MaxN+5];
bool vis[MaxN+5][MaxN+5];

void ReadData() {
    for (int i=0; i<n; i++)
        cin >> s[i];
}

void FindSpecialPos() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (s[i][j] == 'B') {
                bx = i;
                by = j;
            }
            if (s[i][j] == 'C') {
                cx = i;
                cy = j;
            }
        }
    }
}

bool Check(int x, int y) {
    return ((x >= 0) && (x < n) && (y >= 0) && (y < m));
}

int BFS(int srcx, int srcy, int finx, int finy) {
    queue<pii> q;
    q.push(pii(srcx, srcy));
    dist[srcx][srcy] = 0;
    vis[srcx][srcy] = true;
    while (!q.empty()) {
        pii tmp = q.front();
        q.pop();
        int x = tmp.first, y = tmp.second;
        for (int i=0; i<4; i++) {
            int NewX = x + diri[i], NewY = y + dirj[i];
            if ((Check(NewX, NewY)) && (!vis[NewX][NewY]) && (s[NewX][NewY] != '*')) {
                dist[NewX][NewY] = dist[x][y] + 1;
                vis[NewX][NewY] = true;
                q.push(pii(NewX, NewY));
            }
        }
    }
    return dist[finx][finy];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    FindSpecialPos();
    cout << BFS(bx, by, cx, cy);
    return 0;
}
