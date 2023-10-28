#include <iostream>
#include <bits/stdc++.h>
#define MaxN 20
using namespace std;
typedef pair<int, int> pii;
string s[MaxN+1];
int t, n, m, di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
bool vis[MaxN+1][MaxN+1], AlCnt[MaxN+1][MaxN+1];

void ReadData() {
    for (int i=0; i<n; i++)
        cin >> s[i];
}

bool IsOnEdge(int x, int y) {
    return ((x == 0) || (x == n-1) || (y == 0) || (y == m-1));
}

bool InBoard(int x, int y) {
    return ((x >= 0) && (x < n) && (y >= 0) && (y < m) && (s[x][y] != '#'));
}

int DFS(pii u, pii st) {
    int ans = 0;
    if ((IsOnEdge(u.first, u.second)) && (u != st))
        return 1;
    for (int i=0; i<4; i++) {
        int NewX = u.first + di[i], NewY = u.second + dj[i];
        if ((!vis[NewX][NewY]) && (InBoard(NewX, NewY))) {
            vis[NewX][NewY] = true;
            ans += DFS(pii(NewX, NewY), st);
        }
    }
    return ans;
}

void SolveTestCase() {
    int cnt = 0;
    bool ReachChable = false;
    memset(AlCnt, false, sizeof(AlCnt));
    for (int i=0; i<m; i++) {
        if (s[0][i] == '.') {
            memset(vis, false, sizeof(vis));
            if (!AlCnt[0][i])
                cnt++;
            AlCnt[0][i] = true;
            if ((!ReachChable) && (DFS(pii(0, i), pii(0, i)) == 1))
                ReachChable = true;
        }
        if (s[n-1][i] == '.') {
            memset(vis, false, sizeof(vis));
            if (!AlCnt[n-1][i])
                cnt++;
            AlCnt[n-1][i] = true;
            if ((!ReachChable) && (DFS(pii(n-1, i), pii(n-1, i)) == 1))
                ReachChable = true;
        }
        if (cnt > 2) {
            cout << "invalid\n";
            return;
        }
    }
    for (int i=0; i<n; i++) {
        if (s[i][0] == '.') {
            memset(vis, false, sizeof(vis));
            if (!AlCnt[i][0])
                cnt++;
            AlCnt[i][0] = true;
            if ((!ReachChable) && (DFS(pii(i, 0), pii(i, 0)) == 1))
                ReachChable = true;
        }
        if (s[i][m-1] == '.') {
            memset(vis, false, sizeof(vis));
            if (!AlCnt[i][m-1])
                cnt++;
            AlCnt[i][m-1] = true;
            if ((!ReachChable) && (DFS(pii(i, m-1), pii(i, m-1)) == 1))
                ReachChable = true;
        }
        if (cnt > 2) {
            cout << "invalid\n";
            return;
        }
    }
    if (!ReachChable)
        cout << "invalid\n";
    else
        cout << "valid\n";
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> m;
        ReadData();
        SolveTestCase();
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
