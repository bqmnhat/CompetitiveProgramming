#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> IPair;
int n,m, a[201][201], dist[201][201], di[5] = {0,-1,0,1,0}, dj[5] = {0,0,1,0,-1};
bool visited[201][201];
queue <IPair> q;

void ReadData() {
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin >> a[i][j];
}

bool Check(int i, int j) {
    return ((i <= n) && (i >= 1) && (j >= 1) && (j <= m));
}

bool ShorterDist(IPair v, IPair u) { //New shorter path from v => u
    return (dist[u.first][u.second] > dist[v.first][v.second] + a[u.first][u.second]);
}

void BFS() {
    for (int i=1; i<=n; i++) {
        q.push(make_pair(i,1));
        dist[i][1] = a[i][1];
        visited[i][1] = true;
    }
    while (!q.empty()) {
        IPair v = q.front();
        q.pop();
        if (v.second == m)
            continue;
        for (int i=1; i<=4; i++) {
            IPair u;
            u.first = v.first + di[i];
            u.second = v.second + dj[i];
            if (((ShorterDist(v,u)) || (!visited[u.first][u.second])) && (Check(u.first, u.second))) {
                q.push(u);
                visited[u.first][u.second] = true;
                dist[u.first][u.second] = min(dist[u.first][u.second], dist[v.first][v.second] + a[u.first][u.second]);
            }
        }
    }
}

int ShortestSolution() {
    int ans = 1e9;
    for (int i=1; i<=n; i++) {
        if (dist[i][m] < ans)
            ans = dist[i][m];
    }
    return ans;
}

int Solution() {
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            dist[i][j] = 1e9;
    BFS();
    return ShortestSolution();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("FUNFAIR.INP", "r", stdin);
    freopen("FUNFAIR.OUT", "w", stdout);
    cin >> n >> m;
    ReadData();
    cout << Solution();
    return 0;
}
