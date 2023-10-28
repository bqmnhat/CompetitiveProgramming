#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, m, counter = 0, low[100001], num[100001], SCCCnt = 0, InSCC[100001], OutDeg[100001];
vector<int> graph[100001], NewGraph[100001];
stack<int> st;

void ReadGraph() {
    for (int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
}

void DFS(int u) {
    counter++;
    num[u] = low[u] = counter;
    st.push(u);
    for (auto v: graph[u]) {
        if (InSCC[v] == 0) {
            if (num[v] > 0)
                low[u] = min(low[u], num[v]);
            else {
                DFS(v);
                low[u] = min(low[u], low[v]);
            }
        }
    }
    if (low[u] == num[u]) {
        SCCCnt++;
        int v;
        do {
            v = st.top();
            st.pop();
            NewGraph[SCCCnt].push_back(v);
            low[v] = num[v] = INT_MAX;
            InSCC[v] = SCCCnt;
        } while (v != u);
    }
}

void Tarjan() {
    counter = 0;
    SCCCnt = 0;
    for (int i=1; i<=n; i++) {
        low[i] = num[i] = 0;
        InSCC[i] = 0;
    }
    st = stack<int>();
    for (int i=1; i<=n; i++) {
        if (!num[i])
            DFS(i);
    }
}

void Solve() {
    Tarjan();
    int cnt = 0, CapVertex;
    for (int i=1; i<=n; i++)
        for (auto v: graph[i])
            if (InSCC[v] != InSCC[i])
                OutDeg[InSCC[i]]++;
    for (int i=1; i<=SCCCnt; i++) {
        if (OutDeg[i] == 0) {
            cnt++;
            CapVertex = i;
        }
    }
    if (cnt > 1) {
        cout << "0";
        return;
    }
    int NumOfCap = (int)NewGraph[CapVertex].size();
    cout << NumOfCap << '\n';
    sort(NewGraph[CapVertex].begin(), NewGraph[CapVertex].end());
    for (auto u: NewGraph[CapVertex])
        cout << u << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadGraph();
    Solve();
    return 0;
}
