#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, m, trace[100001], Ans[100001], la = 0;
vector<int> g[100001];
bool visited[100001], visited2[100001];
map<pair<int,int>, int> EdgeMap;

void ReadGraph() {
    int u, v;
    for (int i=1; i<=m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        EdgeMap[make_pair(u,v)] = i;
    }
}

void PrintGraph(int beg) {
    int i = trace[beg];
    la++;
    Ans[la] = (*EdgeMap.find(make_pair(i, beg))).second;
    while (i != beg) {
        la++;
        Ans[la] = (*EdgeMap.find(make_pair(trace[i],i))).second;
        i = trace[i];
    }
    cout << "YES" << '\n';
    for (int i=la; i>=1; i--)
        cout << Ans[i] << ' ';
}

void DetectGraph(int u, bool &CycleFound) {
    if (!visited[u]) {
        visited[u] = true;
        visited2[u] = true;
        for (auto v: g[u]) {
            if (!visited[v]) {
                trace[v] = u;
                DetectGraph(v,CycleFound);
                if (CycleFound)
                    return;
            }
            else if (visited2[v]) {
                trace[v] = u;
                PrintGraph(v);
                CycleFound = true;
                return;
            }
        }
    }
    visited2[u] = false;
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CIRCUIT.INP", "r", stdin);
    freopen("CIRCUIT.OUT", "w", stdout);
    cin >> n >> m;
    ReadGraph();
    bool CycleFound = false;
    for (int i=1; i<=n; i++) {
        CycleFound = false;
        DetectGraph(i, CycleFound);
        if (CycleFound)
            return 0;
    }
    cout << "NO";
    return 0;
}
