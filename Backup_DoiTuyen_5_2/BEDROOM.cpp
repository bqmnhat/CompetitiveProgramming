#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, diri[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dirj[8] = {0, 1, 1, 1, 0, -1, -1, -1};
bool vis[2*MaxN+5][2*MaxN+5];
pii a[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i].first >> a[i].second;
        a[i].first += MaxN;
        a[i].second += MaxN;
        int x, y;
        cin >> x >> y;
    }
}

bool Check(pii src) {
    int x = src.first - MaxN, y = src.second - MaxN;
    return ((x >= -200) && (x <= 200) && (y >= -200) && (y <= 200));
}

ll BFS(pii src) {
    queue<pii> q;
    ll dist[2*MaxN+5][2*MaxN+5];
    for (int i=0; i<=2*MaxN; i++)
        for (int j=0; j<=2*MaxN; j++)
            dist[i][j] = 1e9;
    memset(vis, false, sizeof(vis));
    q.push(src);
    dist[src.first][src.second] = 0;
    vis[src.first][src.second] = true;
    while (!q.empty()) {
        pii u = q.front();
        q.pop();
        int x = u.first, y = u.second;
        for (int i=0; i<8; i++) {
            int NewX = x + diri[i], NewY = y + dirj[i];
            if ((Check(pii(NewX, NewY))) && (!vis[NewX][NewY])) {
                vis[NewX][NewY] = true;
                q.push(pii(NewX, NewY));
                dist[NewX][NewY] = dist[x][y] + 1;
            }
        }
    }
    ll ans = 0;
    for (int i=1; i<=n; i++)
        ans += dist[a[i].first][a[i].second];
    return ans;
}

ll Solution() {
    ll ans = 1e18;
    for (int i=0; i<=2*MaxN; i++)
        for (int j=0; j<=2*MaxN; j++)
            ans = min(ans, BFS(pii(i, j)));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("BEDROOM.INP", "r", stdin);
    freopen("BEDROOM.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
