#include <iostream>
#include <bits/stdc++.h>
#define MaxN 20
using namespace std;
typedef pair<int, int> pii;
int m, n, diri[4] = {-1, 0, 1, 0}, dirj[4] = {0, 1, 0, -1};
string s[MaxN+1];
bool vis[MaxN+1][MaxN+1];

void ReadData() {
    for (int i=0; i<m; i++)
        cin >> s[i];
}

bool Check(int x, int y, char Type) {
    return ((x >= 0) && (x < m) && (!vis[x][y]) && (s[x][y] == Type));
}

int BFS(int srcx, int srcy, char Type) {
    int ans = 1;
    queue<pii> q;
    q.push(pii(srcx, srcy));
    while (!q.empty()) {
        pii Cur = q.front();
        q.pop();
        for (int i=0; i<=3; i++) {
            int NextX = Cur.first + diri[i], NextY = (Cur.second + dirj[i] + n)%n;
            if (Check(NextX, NextY, Type)) {
                vis[NextX][NextY] = true;
                ans++;
                q.push(pii(NextX, NextY));
            }
        }
    }
    return ans;
}

void Solve() {
    while (cin >> m >> n) {
        ReadData();
        memset(vis, false, sizeof(vis));
        int X, Y, ans = 0;
        cin >> X >> Y;
        vis[X][Y] = true;
        BFS(X, Y, s[X][Y]);
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if ((!vis[i][j]) && (s[i][j] == s[X][Y])) {
                    vis[i][j] = true;
                    ans = max(ans, BFS(i, j, s[X][Y]));
                }
            }
        }
        cout << ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("CONTINENTS.INP", "r", stdin);
    //freopen("CONTINENTS.OUT", "w", stdout);
    Solve();
    return 0;
}
