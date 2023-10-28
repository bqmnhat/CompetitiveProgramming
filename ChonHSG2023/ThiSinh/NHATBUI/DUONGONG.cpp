#include <iostream>
#include <bits/stdc++.h>
#define MaxNSub1 10
#define MaxNSub23 10000
#define MaxN 100000
using namespace std;
typedef pair<int, int> pii;
int n, k, deg[MaxN+5], CycleOrder[MaxN+5], trace[MaxN+5], visCycle[MaxN+5];
bool vis[MaxN+5], InCycle[MaxN+5];
vector<int> g[MaxN+5], cycle, stk;
vector<pii> Edges;

void ReadData() {
    for (int i=1; i<=n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        Edges.push_back(pii(u, v));
    }
}

//Solution Sub 1: Marking and Testing

void DFSTest(int u, int prohibU, int prohibV) {
    vis[u] = true;
    for (int v: g[u]) {
        if (((v == prohibU) && (u == prohibV)) ||
        ((u == prohibU) && (v == prohibV)))
            continue;
        deg[u]++;
        if (!vis[v])
            DFSTest(v, prohibU, prohibV);
    }
}

int SolutionSub1() {
    int ans = 0;
    for (pii tmpe: Edges) {
        bool Exist = false;
        for (int i=1; i<=n; i++) {
            for (int t=1; t<=n; t++) {
                vis[t] = false;
                deg[t] = 0;
            }
            DFSTest(i, tmpe.first, tmpe.second);
            bool good = (deg[i] <= k);
            for (int j=1; j<=n; j++) {
                if (i == j)
                    continue;
                if ((!vis[j]) || (deg[j] > k+1))
                    good = false;
            }
            Exist |= good;
        }
        if (Exist)
            ans++;
    }
    return ans;
}

// Other Subs

pii DFSFindCycle(int u, int p) {
    visCycle[u] = 1;
    pii ans = pii(-1, -1);
    stk.push_back(u);
    for (int v: g[u]) {
        if (v == p)
            continue;
        if (visCycle[v] == 0) {
            ans = DFSFindCycle(v, u);
            if (ans.second != -1)
                return ans;
        }
        if (visCycle[v] == 1)
            return pii(u, v);
    }
    stk.pop_back();
    visCycle[u] = 2;
    return ans;
}

void FindCycle() {
    pii CycleFirstEdge;
    for (int i=1; i<=n; i++) {
        if (visCycle[i] != 2)
            CycleFirstEdge = DFSFindCycle(i, -1);
        if (CycleFirstEdge.second != -1)
            break;
    }
    while (stk.back() != CycleFirstEdge.second) {
        int tmp = stk.back();
        cycle.push_back(tmp);
        InCycle[tmp] = true;
        stk.pop_back();
    }
    cycle.push_back(CycleFirstEdge.second);
}

int Solution() {
    int cntKPlus1 = 0, cntKPlus1NotInCycle = 0;
    for (int i=1; i<=n; i++) {
        if (g[i].size() > k + 1)
            cntKPlus1++;
        if ((!InCycle[i]) && (g[i].size() > k))
            cntKPlus1NotInCycle++;
    }
    if (cntKPlus1NotInCycle > 1)
        return 0;
    if (cntKPlus1 > 2)
        return 0;
    int ans = 0;
    for (int i=0; i<cycle.size()-2; i++) {
        int Dec = 0;
        if ((g[i].size()-1 <= k+1)  && (g[i].size() > k+1))
            Dec++;
        if ((g[i+1].size()-1 <= k+1)  && (g[i+1].size() > k+1))
            Dec++;
        if ((cntKPlus1 - Dec) <= 2)
            ans++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("DUONGONG.INP", "r", stdin);
    freopen("DUONGONG.OUT", "w", stdout);
    cin >> n >> k;
    ReadData();
    if ((k <= n) && (n <= 50))
        cout << SolutionSub1();
    else {
        FindCycle();
        cout << Solution();
    }
    return 0;
}
