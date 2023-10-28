#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int n, m;
vector<int> g[MaxN+5];
unordered_map<int, int> deg[MaxN+5];

void ReadData() {
    int u, v;
    for (int i=1; i<=m; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u][v]++;
        deg[v][u]++;
    }
}

void FindEulerian(int u, vector<int>& ans) {
    while(deg[u].size() > 0) {
        auto tmp = (*deg[u].begin());
        int v = (tmp.first);
        if (deg[u][v] > 0) {
            deg[u][v]--;
            deg[v][u]--;
            if (deg[u][v] == 0) {
                deg[u].erase(deg[u].find(v));
                deg[v].erase(deg[v].find(u));
            }
            FindEulerian(v, ans);
        }
    }
    ans.push_back(u);
}

void Solve() {
    for (int i=1; i<=n; i++) {
        if (g[i].size()&1) {
            cout << "IMPOSSIBLE";
            return;
        }
    }
    vector<int> ans;
    ans.clear();
    FindEulerian(1, ans);
    if (ans.size() != m+1) {
        cout << "IMPOSSIBLE";
        return;
    }
    for (int u: ans)
        printf("%d ", u);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    scanf("%d%d", &n, &m);
    ReadData();
    Solve();
    return 0;
}
