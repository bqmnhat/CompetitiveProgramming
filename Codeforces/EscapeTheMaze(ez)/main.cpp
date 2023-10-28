#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, t, k, x[200001], mark[200001];
vector<int> g[200001];
queue<int> q;

void Init() {
    for (int i=0; i<=n; i++)
        mark[i] = -1;
    for (int i=0; i<=n; i++) {
        while (!g[i].empty())
            g[i].pop_back();
    }
}

void ReadData() {
    for (int i=1; i<=k; i++) {
        cin >> x[i];
        mark[x[i]] = 0;
        q.push(x[i]);
    }
    int u,v;
    for (int i=1; i<n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void MarkRooms() {
    mark[1] = 1;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: g[u]) {
            if (mark[v] == -1) {
                mark[v] = mark[u];
                q.push(v);
            }
        }
    }
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> k;
        Init();
        ReadData();
        MarkRooms();
        bool CanWin = false;
        for (int i = 2; i<=n; i++) {
            if ((g[i].size() == 1) && (mark[i] == 1)) {
                CanWin = true;
                break;
            }
        }
        if (CanWin)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
