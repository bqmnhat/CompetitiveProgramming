#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10000
using namespace std;
int n, m, counter, num[MaxN+5], low[MaxN+5], SCCCnt = 0;
bool found[MaxN+5];
vector<int> g[MaxN+5], stk;

void ReadData() {
    int u, v;
    for (int i=1; i<=m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
    }
}

void DFSSCC(int u) {
    num[u] = low[u] = ++counter;
    stk.push_back(u);
    for (int v: g[u]) {
        if (!found[v]) {
            if (num[v] > 0)
                low[u] = min(low[u], num[v]);
            else {
                DFSSCC(v);
                low[u] = min(low[u], low[v]);
            }
        }
    }
    if (num[u] == low[u]) {
        SCCCnt++;
        int v;
        do {
            v = stk.back();
            stk.pop_back();
            found[v] = true;
        } while (v != u);
    }
}

void Solve() {
    for (int i=1; i<=n; i++)
        if (!num[i])
            DFSSCC(i);
    for (int i=1; i<=n; i++)
        if (!found[i])
            SCCCnt++;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    Solve();
    cout << SCCCnt;
    return 0;
}
