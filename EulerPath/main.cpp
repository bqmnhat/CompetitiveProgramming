#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
int n, m;
vector<int> g[MaxN+5], deg[MaxN+5];

void ReadData() {
    int u, v;
    for (int i=1; i<=m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        deg[u].push_back(1);
        g[v].push_back(u);
        deg[v].push_back(1);
    }
}

void FindEulerPath() {
    //<Check lien thong>
    int v1 = -1, v2 = -1;
    bool bad = false;
    for (int i=1; i<=n; i++) {
        if (deg[i].size()&1) {
            if (v1 == -1)
                v1 = i;
            else if (v2 == -1)
                v2 = i;
            else
                bad = true;
        }
    }

    stack<int> stk;
    stk.push(1);
    vector<int> res;
    while (!stk.empty()) {
        int u = stk.top();
        bool flag = true;
        for (int i=0; i<g[u].size(); i++) {
            if (deg[u][i] > 0) {
                deg[u][i]--;
                stk.push(g[u][i]);
                flag = false;
                break;
            }
        }
        if (flag) {
            res.push_back(u);
            stk.pop();
        }
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
