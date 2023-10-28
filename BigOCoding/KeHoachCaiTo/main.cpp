#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, m, num[200001], low[200001], counter = 0, sub[200001], CCCnt = 0;
vector<int> graph[200001], CCSize;
vector<pii> bridges;

void ReadGraph() {
    for (int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void DFSBridge(int u, int p) {
    counter++;
    low[u] = num[u] = counter;
    for (int v: graph[u]) {
        if (v == p)
            continue;
        if (num[v] > 0)
            low[u] = min(low[u], num[v]);
        else {
            DFSBridge(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > num[u])
                bridges.push_back(pii(u, v));
        }
    }
}

void InitNumAndLow() {
    for (int i=1; i<=n; i++)
        num[i] = low[i] = 0;
}

void DFSSub(int u) {
    CCSize[CCCnt]++;
    num[u] = 1;
    sub[u] = 1;
    for (int v: graph[u]) {
        if (!num[v]) {
            DFSSub(v);
            sub[u] += sub[v];
        }
    }
}

long long Solution() {
    CCSize.push_back(0);
    long long ans = 0;
    InitNumAndLow();
    for (int i=1; i<=n; i++) {
        if (!num[i]) {
            CCCnt++;
            CCSize.push_back(0);
            DFSSub(i);
        }
    }
    if (CCCnt > 2)
        return 0;
    InitNumAndLow();
    for (int i=1; i<=n; i++) {
        if (!num[i]) {
            DFSBridge(i, -1);
        }
    }
    if (CCCnt == 2)
        ans = (m - bridges.size())*CCSize[1]*CCSize[2];
    else {
        ans = 1LL*(m-bridges.size())*(((1LL*n*(n-1))/2) - m);
        for (auto e : bridges)
            ans += 1LL*(n - sub[e.second])*sub[e.second] - 1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadGraph();
    cout << Solution();
    return 0;
}
