#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int discTime[10001], low[10001], n, m, SCC = 0;
bool visited[10001];
vector<int> g[10001];
stack<int> st;

void addedge(int u, int v) {
    g[u].push_back(v);
}

void DFSSCC(int u, int &time) {
    time++;
    discTime[u] = low[u] = time;
    st.push(u);
    visited[u] = true;
    for (auto v: g[u]) {
        if (discTime[v] == -1) {
            DFSSCC(v, time);
            low[u] = min(low[u], low[v]);
        }
        else if (visited[v])
            low[u] = min(low[u], discTime[v]);
    }
    if (low[u] == discTime[u]) {
        SCC++;
        int x = 0;
        while (st.top() != u) {
            x = st.top();
            visited[x] = false;
            st.pop();
        }
        visited[u] = false;
        st.pop();
    }
}

void Solve() {
    int time = 0;
    for (int i=1; i<=n; i++) {
        discTime[i] = -1;
        low[i] = -1;
    }
    for (int u=1; u<=n; u++)
        if (discTime[u] == -1)
            DFSSCC(u,time);
    cout << SCC;
}

int main()
{
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v;
        addedge(u,v);
    }
    Solve();
    return 0;
}
