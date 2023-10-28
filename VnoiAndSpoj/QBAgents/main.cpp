#include <iostream>
#include <bits/stdc++.h>
#define MaxN 250
#define MaxM 40000
using namespace std;
const int INF = 1e9 + 7;
struct BFSNode {
    int u, v, turn;
};
int n, m, s, t;
vector<int> g[MaxN+4];
bool vis[MaxN+5][MaxN+5][2];
int dist[MaxN+5][MaxN+5][2];

void ReadData() {
    int u, v;
    for (int i=1; i<=m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
    }
}

int BFS() {
    queue<BFSNode> q;
    dist[s][t][0] = 0;
    vis[s][t][0] = true;
    q.push({s, t, 0});
    int ans = INF;
    while (!q.empty()) {
        BFSNode tmp = q.front();
        q.pop();
        if ((tmp.u == tmp.v) && (tmp.turn == 0))
            ans = min(ans, dist[tmp.u][tmp.v][0]/2);
        if (tmp.turn == 0) {
            for (int v: g[tmp.v]) {
                BFSNode NewNode = {tmp.u, v, 1 - tmp.turn};
                if (!vis[NewNode.u][NewNode.v][NewNode.turn]){
                    dist[NewNode.u][NewNode.v][NewNode.turn] = dist[tmp.u][tmp.v][tmp.turn] + 1;
                    vis[NewNode.u][NewNode.v][NewNode.turn] = true;
                    q.push(NewNode);
                }
            }
        }
        if (tmp.turn == 1) {
            for (int v: g[tmp.u]) {
                BFSNode NewNode = {v, tmp.v, 1 - tmp.turn};
                if (!vis[NewNode.u][NewNode.v][NewNode.turn]) {
                    dist[NewNode.u][NewNode.v][NewNode.turn] = dist[tmp.u][tmp.v][tmp.turn] + 1;
                    vis[NewNode.u][NewNode.v][NewNode.turn] = true;
                    q.push(NewNode);
                }
            }
        }
    }
    return ans;
}

int Solution() {
    int ans = BFS();
    if (ans >= INF)
        return -1;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s >> t;
    ReadData();
    cout << Solution();
    return 0;
}
