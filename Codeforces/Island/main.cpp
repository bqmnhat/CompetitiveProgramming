#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, m, diri[5] = {0, -1, 0, 1, 0}, dirj[5] = {0, 0, 1, 0, -1};
string s[51];
queue<pii> q;
bool vis[51][51];

void ReadData() {
    for (int i=0; i<n; i++)
        cin >> s[i];
}

bool Check(pii x) {
    return ((x.first >= 0) && (x.second >= 0) && (x.first < n) && (x.second < m) && (!vis[x.first][x.second]) && ((s[x.first][x.second] == 'L') || (s[x.first][x.second] == 'C')));
}

void BFS(pii src) {
    q.push(src);
    vis[src.first][src.second] = true;
    while (!q.empty()) {
        pii u = q.front();
        q.pop();
        for (int i=1; i<=4; i++) {
            pii v = pii(u.first + diri[i], u.second + dirj[i]);
            if (Check(v)) {
                vis[v.first][v.second] = true;
                q.push(v);
            }
        }
    }
}

int Solution() {
    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if ((s[i][j] == 'L') && (!vis[i][j])) {
                ans++;
                BFS(pii(i, j));
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    cout << Solution();
    return 0;
}
