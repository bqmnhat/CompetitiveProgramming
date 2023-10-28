#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int n, m, num[MaxN+1], low[MaxN+1], InWhichSCC[MaxN+1], SCCCnt = 0, counter = 0, Outdeg[MaxN+1];
bool found[MaxN+1];
vector<int> g[MaxN+1], InSCC[MaxN+1];
stack<int> stk;

void ReadData() {
    int u, v;
    for (int i=1; i<=m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
    }
}

void DFS(int u) {
    counter++;
    low[u] = num[u] = counter;
    stk.push(u);
    for (int v: g[u]) {
        if (!found[v]) {
            if (num[v])
                low[u] = min(low[u], num[v]);
            else {
                DFS(v);
                low[u] = min(low[u], low[v]);
            }
        }
    }
    if (low[u] == num[u]) {
        int v;
        SCCCnt++;
        do {
            v = stk.top();
            stk.pop();
            InWhichSCC[v] = SCCCnt;
            InSCC[SCCCnt].push_back(v);
            low[v] = num[v] = INT_MAX;
            found[v] = true;
        } while (v != u);
    }
}

void Tarjan() {
    for (int i=1; i<=n; i++)
        if (!num[i])
            DFS(i);
    for (int i=1; i<=n; i++) {
        if (InWhichSCC[i] == 0) {
            SCCCnt++;
            InWhichSCC[i] = SCCCnt;
            InSCC[SCCCnt].push_back(i);
        }
    }
}

void Solve() {
    Tarjan();
    for (int u=1; u<=n; u++)
        for (int v: g[u])
            if (InWhichSCC[u] != InWhichSCC[v])
                Outdeg[InWhichSCC[u]]++;
    int CapSCC = -1;
    for (int i=1; i<=SCCCnt; i++) {
        if (Outdeg[i] == 0) {
            CapSCC = i;
            break;
        }
    }
    if (CapSCC == -1) {
        cout << "0";
        return;
    }
    sort(InSCC[CapSCC].begin(), InSCC[CapSCC].end());
    int NumOfCapCity = InSCC[CapSCC].size();
    cout << NumOfCapCity << '\n';
    for (int x: InSCC[CapSCC])
        cout << x << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    Solve();
    return 0;
}
