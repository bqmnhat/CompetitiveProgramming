#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, m, t, discTime[30001], low[30001], Ans = 1;
bool visited[30001];
vector<int> g[30001];
stack<pair<int,int>> stk;
map<int, bool> Map;

void addEdge(int u, int v)
{
    g[u].push_back(v);
    g[v].push_back(u);
}

void DFSFindCutVertex(int u, int& time, int parent) {
    int children = 0;
    time++;
    discTime[u] = low[u] = time;
    for (auto v: g[u]) {
        if (v == parent) continue;
        if (discTime[v] == -1) {
            children++;
            stk.push(make_pair(u,v));
            DFSFindCutVertex(v, time, u);
            low[u] = min(low[u], low[v]);
            if (((discTime[u] == 1) && (children > 1)) || ((discTime[u] > 1) && (low[v] >= discTime[u]))) {
                int tmp = 0;
                while ((stk.top().first != u) || (stk.top().second != v)) {
                    if (!visited[stk.top().first]) {
                        tmp++;
                        visited[stk.top().first] = true;
                    }
                    if (!visited[stk.top().second]) {
                        tmp++;
                        visited[stk.top().second] = true;
                    }
                    stk.pop();
                }
                if (!visited[stk.top().first]) {
                    tmp++;
                    visited[stk.top().first] = true;
                }
                if (!visited[stk.top().second]) {
                    tmp++;
                    visited[stk.top().second] = true;
                }
                stk.pop();
                visited[u] = false;
                Ans = max(Ans, tmp);
            }
        }
        else if (v != parent) {
            low[u] = min(low[u], discTime[v]);
            if ((discTime[v] < discTime[u]) && (discTime[v] == -1))
                stk.push(make_pair(u,v));
        }
    }
}

void Solve()
{
    int time = 0;
    for (int i=1; i<=30001; i++) {
        discTime[i] = -1;
        low[i] = -1;
    }
    for (int u = 1; u <= n; u++)
        if (discTime[u] == -1) {
            DFSFindCutVertex(u, time, -1);
            bool Find = false;
            int tmp = 0;
            while (!stk.empty()) {
                Find = true;
                if (!visited[stk.top().first]) {
                    tmp++;
                    visited[stk.top().first] = true;
                }
                if (!visited[stk.top().second]) {
                    tmp++;
                    visited[stk.top().second] = true;
                }
                stk.pop();
            }
            if (Find)
                Ans = max(Ans, tmp);
        }
    cout << Ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int u,v;
        cin >> u >> v;
        addEdge(u,v);
    }
    Solve();
    return 0;
}
