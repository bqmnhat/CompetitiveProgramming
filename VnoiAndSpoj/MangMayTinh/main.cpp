#include <iostream>
#include <bits/stdc++.h>
#define MaxN 2000
using namespace std;
int n, m, low[MaxN+1], num[MaxN+1], counter = 0, InDeg[MaxN+1], OutDeg[MaxN+1], InWhichSCC[MaxN+1];
bool found[MaxN+1];
vector<int> g[MaxN+1];
vector<vector<int>> SCC;
stack<int> stk;

void ReadGraph() {
    int u, v;
    for (int i=1; i<=m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
    }
}

void DFS(int u) {
    counter++;
    num[u] = low[u] = counter;
    stk.push(u);
    for (int v: g[u]) {
        if (!found[v]) {
            if (!num[v]) {
                DFS(v);
                low[u] = min(low[u], low[v]);
            }
            else
                low[u] = min(low[u], num[v]);
        }
    }
    if (low[u] == num[u]) {
        int v;
        SCC.push_back({});
        int curid = SCC.size()-1;
        do {
            v = stk.top();
            stk.pop();
            found[v] = true;
            SCC[curid].push_back(v);
            InWhichSCC[v] = curid;
        } while (v != u);
    }
}

void Tarjan() {
    SCC.push_back({});
    for (int i=1; i<=n; i++)
        if (!num[i])
            DFS(i);
}

void Solve() {
    Tarjan();
    int SCCSize = SCC.size() - 1, NoInID = -1, NoOutID = -1;
    for (int i=1; i<=SCCSize; i++) {
        for (int u: SCC[i]) {
            for(int v: g[u]) {
                OutDeg[i]++;
                InDeg[InWhichSCC[v]]++;
            }
        }
    }
    for (int i=1; i<=SCCSize; i++) {
        if (InDeg[i] == 0) {
            if (NoInID == -1)
                NoInID = i;
            else {
                cout << "NO";
                return;
            }
        }
        if (OutDeg[i] == 0) {
            if (NoOutID == -1)
                NoOutID = i;
            else {
                cout << "NO";
                return;
            }
        }
    }
    if ((NoInID != -1) && (NoOutID != -1)) {
        int t = 0;
        while (SCC[NoOutID][t] == SCC[NoInID][0])
            t++;
        cout << "YES\n" << SCC[NoOutID][t] << ' ' << SCC[NoInID][0];
    }
    else if (NoInID != -1){
        int t = 0;
        NoOutID = (NoInID + 1)%SCCSize;
        if (NoOutID == 0)
            NoOutID = SCCSize;
        while (NoOutID == NoInID) {
            NoOutID = (NoOutID+1)%SCCSize;
            if (NoOutID == 0)
                NoOutID = SCCSize;
        }
        while (SCC[NoOutID][t] == SCC[NoInID][0])
            t++;
        cout << "YES\n" << SCC[NoOutID][t] << ' ' << SCC[NoInID][0];
    }
    else if (NoOutID != -1) {
        int t = 0;
        NoInID = (NoOutID + 1)%SCCSize;
        if (NoInID == 0)
            NoInID = SCCSize;
        while (NoOutID == NoInID) {
            NoInID = (NoInID+1)%SCCSize;
            if (NoInID == 0)
                NoInID = SCCSize;
        }
        while (SCC[NoInID][t] == SCC[NoOutID][0])
            t++;
        cout << "YES\n" << SCC[NoOutID][0] << ' ' << SCC[NoInID][t];
    }
    else cout << "NO";
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
