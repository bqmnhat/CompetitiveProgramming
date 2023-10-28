#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef pair<int, int> pii;
int n, m, low[MaxN+1], num[MaxN+1], counter = 0, InWhichC[MaxN+1];
bool vis[MaxN+1], vis2[MaxN+1];
vector<int> g[MaxN+1], NewGraph[MaxN+1], GOfC[MaxN+1];
vector<vector<int>> C;
vector<pii> ForSort;
map<pii, bool> IsBridge;
stack<int> stk;

void ReadData() {
    int u, v;
    for (int i=1; i<=m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void DFS(int u, int p) {
    counter++;
    num[u] = low[u] = counter;
    for (int v: g[u]) {
        if (v == p)
            continue;
        if (!num[v]) {
            DFS(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= num[u])
                IsBridge[pii(u, v)] = IsBridge[pii(v, u)] = true;
        }
        else
            low[u] = min(low[u], num[v]);
    }
}

void FindAllBridges() {
    for (int i=1; i<=n; i++)
        if (!num[i])
            DFS(i, -1);
}

void MakeNewGraph() {
    for (int i=1; i<=n; i++)
        for (int v: g[i])
            if (IsBridge.find(pii(i, v)) == IsBridge.end())
                NewGraph[i].push_back(v);
}

void DFSCntCntr(int u) {
    vis[u] = true;
    stk.push(u);
    for (int v: NewGraph[u])
        if (!vis[v])
            DFSCntCntr(v);
}

void CountCountries() {
    C.push_back({});
    for (int i=1; i<=n; i++) {
        if (!vis[i]) {
            DFSCntCntr(i);
            C.push_back({});
            int curid = C.size()-1;
            while (!stk.empty()) {
                int v = stk.top();
                stk.pop();
                C[curid].push_back(v);
                InWhichC[v] = curid;
            }
        }
    }
    for (auto x: IsBridge) {
        pii tmp = x.first;
        GOfC[InWhichC[tmp.first]].push_back(InWhichC[tmp.second]);
        GOfC[InWhichC[tmp.second]].push_back(InWhichC[tmp.first]);
    }
}

/*int DFS(int u, int Super, int &cnt) {
    vis2[u] = true;
    cnt++;
    int ans = Super;
    for (int v: GOfC[u])
        if (!vis2[v])
            ans += DFS(v, 1-Super, cnt);
    return ans;
}*/

int Solution() {
    int CSize = C.size()-1;
    for (int i=1; i<=CSize; i++)
        ForSort.push_back(pii(GOfC[i].size(), i));
    sort(ForSort.begin(), ForSort.end(), greater<pii>());
    int ans = 0, cnt = 0;
    for (pii tmp: ForSort) {
        ans++;
        int u = tmp.second;
        if (!vis2[u]) {
            vis2[u] = true;
            cnt++;
        }
        for (auto v: GOfC[u]) {
            if (!vis2[v]) {
                vis2[v] = true;
                cnt++;
            }
        }
        if (cnt == CSize)
            break;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    FindAllBridges();
    MakeNewGraph();
    CountCountries();
    cout << Solution();
    return 0;
}
