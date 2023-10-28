#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int n, m, num[MaxN+1], low[MaxN+1], SCCCnt = 0, counter = 0, InSCC[MaxN+1], MinInSCC[MaxN+1], cost[MaxN+1], MOD = 1e9+7;
vector<int> graph[MaxN+1], NewGraph[MaxN+1];
stack<int> st;
map<int, int> NumInSCC[MaxN+1];

void ReadData() {
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> cost[i];
    cin >> m;
    for (int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
}

void DFS(int u) {
    counter++;
    low[u] = num[u] = counter;
    st.push(u);
    for (auto v: graph[u]) {
        if (!InSCC[v]) {
            if (num[v] > 0)
                low[u] = min(low[u], num[v]);
            else {
                DFS(v);
                low[u] = min(low[u], low[v]);
            }
        }
    }
    if (num[u] == low[u]) {
        int v;
        SCCCnt++;
        do {
            v = st.top();
            st.pop();
            NewGraph[SCCCnt].push_back(v);
            InSCC[v] = SCCCnt;
            MinInSCC[SCCCnt] = min(MinInSCC[SCCCnt], cost[v]);
            NumInSCC[SCCCnt][cost[v]]++;
            low[v] = num[v] = INT_MAX;
        } while (v != u);
    }
}

void Tarjan() {
    counter = SCCCnt = 0;
    for (int i=1; i<=n; i++) {
        low[i] = num[i] = InSCC[i] = 0;
        MinInSCC[i] = 1e9;
    }
    for (int i=1; i<=n; i++)
        if (!num[i])
            DFS(i);
}

void Solve() {
    Tarjan();
    long long MIN = 0, NumOfMIN = 1;
    for (int i=1; i<=SCCCnt; i++) {
        MIN += 1LL*MinInSCC[i];
        NumOfMIN = ((NumOfMIN%MOD)*(1LL*NumInSCC[i][MinInSCC[i]])%MOD)%MOD;
    }
    cout << MIN << ' ' << NumOfMIN;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ReadData();
    Solve();
    return 0;
}
