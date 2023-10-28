#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
int n, m, degIn[MaxN+5];
unordered_map<int, int> g[MaxN+5];

void ReadData() {
    int u, v;
    for (int i=1; i<=m; i++) {
        cin >> u >> v;
        g[u][v]++;
        degIn[v]++;
    }
}

void FindEulerian(int u, vector<int>& ans) {
    while (g[u].size() > 0) {
        auto tmp = (*g[u].begin());
        int v = tmp.first;
        g[u][v]--;
        if (g[u][v] == 0)
            g[u].erase(g[u].find(v));
        FindEulerian(v, ans);
    }
    ans.push_back(u);
}

void Solve() {
    vector<int> ans;
    if (((int)g[1].size() - degIn[1] != 1) || (degIn[n] - (int)g[n].size() != 1)) {
        cout << "IMPOSSIBLE";
        return;
    }
    for (int i=2; i<=n-1; i++) {
        if ((int)g[i].size() - degIn[i] == 1) {
            cout << "IMPOSSIBLE";
            return;
        }
    }
    FindEulerian(1, ans);
    if (ans.size() != m+1) {
        cout << "IMPOSSIBLE";
        return;
    }
    /*for (int i=0; i<ans.size(); i++) {
        if (((ans[i] == 1) && (ans[i+1] == n))
        || ((ans[i] == n) && (ans[i+1] == 1))) {
            for (int j=0; j<=i; j++)
                ans.push_back(ans[j]);
            ans.erase(ans.begin(), ans.begin()+i+1);
            break;
        }
    }*/
    if (ans[0] == n)
        reverse(ans.begin(), ans.end());
    for (int x: ans)
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
