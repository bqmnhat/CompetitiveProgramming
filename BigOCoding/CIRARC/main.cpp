#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, m;
vector<int> g[20001];
bool visited[1001], visited2[1001];
stack<pii> stk;
map<pii, int> tk;

void ReadGraph() {
    int u,v;
    for (int i=1; i<=m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
    }
}

int DetectCycle(int u) {
    if (!visited[u]) {
        visited[u] = true;
        visited2[u] = true;
        for (auto v: g[u]) {
            stk.push(pii(u,v));
            if (!visited[v]) {
                return DetectCycle(v);
            }
            else if (visited2[v]) {
                return v;
            }
        }
    }
    visited2[u] = false;
    return -1;
}

void Solve() {
    int NumOfCycle = 0;
    for (int i=1; i<=n; i++) {
        bool CycleFound = false;
        int tmp = DetectCycle(i, CycleFound);
        if (tmp != -1) {
            NumOfCycle++;
            while (!stk.empty()) {
                tk[stk.top()]++;
                stk.pop();
            }
        }
        while (!stk.empty())
            stk.pop();
    }
    int ans = 0;
    for (auto i: tk)
        if (i.second == NumOfCycle)
            ans++;
    if (ans == 0) {
        cout << "-1";
        return;
    }
    cout << ans << '\n';
    for (auto i: tk)
        if (i.second == NumOfCycle)
            cout << i.first.first << ' ' << i.first.second << '\n';
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
