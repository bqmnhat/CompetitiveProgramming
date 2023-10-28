#include <iostream>
#include <bits/stdc++.h>
#define MaxN 30000
using namespace std;
typedef pair<int, int> pii;
int n, m, low[MaxN+1], num[MaxN+1], counter = 0, ans = 1;
vector<int> g[MaxN+1];
stack<pii> stk;

void ReadGraph() {
    int u, v;
    for (int i=1; i<=m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void DFS(int u, int p) {
    counter++;
    low[u] = num[u] = counter;
    int children = 0;
    for (int v: g[u]) {
        if (v == p)
            continue;
        if (!num[v]) {
            children++;
            stk.push(pii(u, v));
            DFS(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= num[u]) {
                int cnt = 1;
                pii tmp;
                do {
                    tmp = stk.top();
                    stk.pop();
                    cnt++;
                } while (tmp != pii(u, v));
                ans = max(ans, cnt);
            }
        } else
            low[u] = min(low[u], num[v]);
    }
}

void FindAllS() {
    for (int i=1; i<=n; i++)
        if (!num[i])
            DFS(i, -1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadGraph();
    FindAllS();
    cout << ans;
    return 0;
}
