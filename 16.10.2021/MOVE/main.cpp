#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, A, B, t[201], Ans[201], la = 0, trace[201];
vector<int> g[201];

void addEdge(int u, int v, bool directed)  {
    g[u].push_back(v);
    if (!directed) {
        g[v].push_back(u);
    }
}

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> t[i];
    int u, v;
    while (cin >> u >> v)
        addEdge(u,v,false);
}

void Init() {
    for (int i=1; i<=n; i++)
        trace[i] = 0;
}

bool CanReachB(int u, int dt) {
    if (u != A) {
        int ChenhLech = abs(t[u] - t[trace[u]]);
        if (ChenhLech > dt) {
            trace[u] = 0;
            return false;
        }
    }
    if (u == B)
        return true;
    for (auto v: g[u]) {
        if (trace[v] == 0) {
            trace[v] = u;
            if (CanReachB(v,dt))
                return true;
        }
    }
    return false;
}

void StoreAns() {
    la = 0;
    int i = B;
    while (i != -1) {
        la++;
        Ans[la] = i;
        i = trace[i];
    }
}

int BinSearchDt() {
    int lo = 0, hi = 20000, ans = -1;
    while (lo <= hi) {
        int m = (lo + hi)/2;
        Init();
        trace[A] = -1;
        if (CanReachB(A,m)) {
            ans = m;
            StoreAns();
            hi = m - 1;
        }
        else
            lo = m + 1;
    }
    return ans;
}

void PrintAns() {
    for (int i=la; i>=1; i--)
        cout << Ans[i] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("MOVE.INP", "r", stdin);
    freopen("MOVE.OUT", "w", stdout);
    cin >> n >> A >> B;
    if ((A > 200) || (B > 200) || (A < 1) || (B < 1))
        cout << "-1";
    else {
        ReadData();
        int tmp = BinSearchDt();
        if (tmp == -1)
            cout << "-1";
        else {
            cout << tmp << '\n';
            PrintAns();
        }
    }
    return 0;
}
