#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m,par[100001];
vector<int> g[100001];
bool visited[100001], visited2[100001], InInput[100001];

void ReadGraph() {
    int u,v;
    for (int i=1; i<=m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        InInput[u] = true;
    }
}

void Reset() {
    for (int i=1; i<=100000; i++) {
        g[i].clear();
        visited[i] = visited2[i] = false;
        par[i] = 0;
    }
}

void DetectGraph(int u, bool &CycleFound) {
    if (!visited[u]) {
        visited[u] = true;
        visited2[u] = true;
        for (auto v: g[u]) {
            par[v]++;
            if (!visited[v]) {
                DetectGraph(v,CycleFound);
                if (CycleFound)
                    return;
            }
            else if (visited2[v]) {
                CycleFound = true;
                return;
            }
        }
    }
    visited2[u] = false;
    return;
}

void SolveTestCase() {
    for (int i=1; i<=100000; i++) {
        if (InInput[i]) {
            bool CycleFound = false;
            DetectGraph(i, CycleFound);
            if (CycleFound) {
                cout << '0';
                return;
            }
        }
    }
    for (int i=1; i<=100000; i++) {
        if (par[i] > 1) {
            cout << '0';
            return;
        }
    }
    cout << '1';
}

void Solve() {
    for (int i=1; i<=3; i++) {
        cin >> n >> m;
        Reset();
        ReadGraph();
        SolveTestCase();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
