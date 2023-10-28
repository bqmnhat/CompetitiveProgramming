#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
typedef pair<int, int> pii;
int n, m, trace[MaxN+1], status[MaxN+1], Prohibitu = -1, Prohibitv = -1;
vector<int> g[MaxN+1];
vector<pii> cycle, ans;
map<pii, int> cnt;

void ReadGraph() {
    int u,v;
    for (int i=1; i<=m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        cnt[pii(u, v)]++;
    }
}

bool FindCycle(int u, int mode) { // mode = 0 => Return 1 cycle; mode = 1 => Just check if exist at least one cycle
    status[u] = 1;
    for (int v: g[u]) {
        if ((u == Prohibitu) && (v == Prohibitv))
            continue;
        if (status[v] == 0) {
            trace[v] = u;
            if (FindCycle(v, mode))
                return true;
        }
        else if (status[v] == 1) {
            if (mode == 1)
                return true;
            int tmpu = u;
            cycle.push_back(pii(u, v));
            while (tmpu != v) {
                cycle.push_back(pii(trace[tmpu], tmpu));
                tmpu = trace[tmpu];
            }
            return true;
        }
    }
    status[u] = 2;
    return false;
}

void Solve() {
    for (int i=1; i<=n; i++)
        if ((status[i] == 0) && (FindCycle(i, 0)))
            break;
    if (cycle.size() == 0) {
        cout << "-1";
        return;
    }
    for (auto x: cycle) {
        Prohibitu = x.first;
        Prohibitv = x.second;
        memset(status, 0, sizeof(status));
        bool IsValid = true;
        if (cnt[x] > 1)
            continue;
        for (int i=1; i<=n; i++) {
            if ((status[i] == 0) && (FindCycle(i, 1))) {
                IsValid = false;
                break;
            }
        }
        if (IsValid)
            ans.push_back(x);
    }
    if (ans.size() == 0) {
        cout << "-1";
        return;
    }
    sort(ans.begin(), ans.end());
    cout << (int)ans.size() << '\n';
    for (auto x: ans)
        cout << x.first << ' ' << x.second << '\n';
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
