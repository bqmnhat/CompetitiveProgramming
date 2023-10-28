#include<iostream>
#include <bits/stdc++.h>
#define MaxN 250
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii, int> piii;
int n,m,s,t,dp[MaxN+1][MaxN+1][2];
vector<int> g[MaxN+1];
queue<piii> q;
const int inf = 1e9 + 7;

void ReadGraph() {
    int u,v;
    for (int i=1; i<=m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
    }
}

void InitDP() {
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            dp[i][j][0] = dp[i][j][1] = inf;
}

int Solution() {
    q.push(piii(pii(s,t), 0));
    dp[s][t][0] = 0;
    while (!q.empty()) {
        piii tmp = q.front();
        q.pop();
        int u1 = tmp.first.first, u2 = tmp.first.second, last = tmp.second;
        if (last == 0) {
            for (int v: g[u1]) {
                if (dp[v][u2][1-last] == inf) {
                    dp[v][u2][1-last] = dp[u1][u2][last] + 1;
                    q.push(piii(pii(v, u2), 1-last));
                }
            }
        } else {
            for (int v: g[u2]) {
                if (dp[u1][v][1-last] == inf) {
                    dp[u1][v][1-last] = dp[u1][u2][last] + 1;
                    q.push(piii(pii(u1, v), 1-last));
                }
            }
        }
    }
    int ans = inf;
    for (int i=1; i <= n; i++)
        ans = min(ans, dp[i][i][0]);
    if (ans == inf)
        return -1;
    return ans/2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s >> t;
    ReadGraph();
    InitDP();
    cout << Solution();
    return 0;
}
