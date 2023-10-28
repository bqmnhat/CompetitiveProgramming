#include <iostream>
#include <bits/stdc++.h>
#define MaxN 5000
using namespace std;
typedef pair<int, int> pii;
int t, n, a[MaxN+1][MaxN+1], x, y, dist[MaxN+1][MaxN+1], xpos1, xpos2, ypos1, ypos2, diri[4] = {-1, 0, 1, 0}, dirj[4] = {0, 1, 0, -1};
bool vis[MaxN+1][MaxN+1];

void BuildRing(int& st, int y1, int x1, int y2, int x2) {
    for (int i=x1; i<=x2; i++) {
        st++;
        a[y1][i] = st;
        if (st == x) {
            xpos1 = y1;
            xpos2 = i;
        }
        if (st == y) {
            ypos1 = y1;
            ypos2 = i;
        }
    }
    for (int i=y1; i<=y2; i++) {
        if (a[i][x2] != 0)
            continue;
        st++;
        a[i][x2] = st;
        if (st == x) {
            xpos1 = i;
            xpos2 = x2;
        }
        if (st == y) {
            ypos1 = i;
            ypos2 = x2;
        }
    }
    for (int i=x2; i>=x1; i--) {
        if (a[y2][i] != 0)
            continue;
        st++;
        a[y2][i] = st;
        if (st == x) {
            xpos1 = y2;
            xpos2 = i;
        }
        if (st == y) {
            ypos1 = y2;
            ypos2 = i;
        }
    }
    for (int i=y2; i>=y1; i--) {
        if (a[i][x1] != 0)
            continue;
        st++;
        a[i][x1] = st;
        if (st == x) {
            xpos1 = i;
            xpos2 = x1;
        }
        if (st == y) {
            ypos1 = i;
            ypos2 = x1;
        }
    }
}

void BuildBoard() {
    int st = 0;
    for (int i=1; n-i+1 > n/2; i++)
        BuildRing(st, i, i, n-i+1, n-i+1);
}

bool Check(int Prex, int Prey, int x, int y) {
    return ((x <= n) && (x >= 1) && (y <= n) && (y >= 1) && (a[Prex][Prey] > 0) && (a[x][y] > 0) && (__gcd(a[Prex][Prey], a[x][y]) == 1) && (!vis[x][y]));
}

int BFS(int xpos1, int xpos2, int ypos1, int ypos2) {
    queue<pii> q;
    q.push(pii(xpos1, xpos2));
    vis[xpos1][xpos2] = true;
    dist[xpos1][xpos2] = 0;
    while (!q.empty()) {
        int Corx = q.front().first, Cory = q.front().second;
        q.pop();
        if ((Corx == ypos1) && (Cory == ypos2))
            return dist[Corx][Cory];
        for (int i=0; i<=3; i++) {
            int NewCorx = Corx + diri[i], NewCory = Cory + dirj[i];
            if (Check(Corx,Cory, NewCorx, NewCory)) {
                vis[NewCorx][NewCory] = true;
                dist[NewCorx][NewCory] = dist[Corx][Cory] + 1;
                q.push(pii(NewCorx, NewCory));
            }
        }
    }
    return -1;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> x >> y;
        memset(dist, 0, sizeof(dist));
        memset(a, 0, sizeof(a));
        memset(vis, false, sizeof(vis));
        BuildBoard();
        cout << BFS(xpos1, xpos2, ypos1, ypos2) << '\n';
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
