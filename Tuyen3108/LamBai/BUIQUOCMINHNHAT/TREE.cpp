#include <iostream>
#include <bits/stdc++.h>
#define MaxN 300000
using namespace std;
/*struct Query {
    char cmd;
    int u, val k;
} Q;*/
int n, q, Val[MaxN+1], tin[MaxN+1], tout[MaxN+1], h[MaxN+1], counter = 0, par[MaxN+1];
vector<int> g[MaxN+1];
priority_queue<int> pq;

void ReadData() {
    int pi;
    for (int i=2; i<=n; i++) {
        cin >> pi;
        g[i].push_back(pi);
        g[pi].push_back(i);
    }
    /*(string cmd;
    int u, val, k;
    for (int i=1; i<=q; i++) {
        cin >> Q[i].cmd;
        if (Q[i].cmd == "add")
            cin >> Q[i].u >> Q[u].val;
        else if (Q[i].cmd == "get")
            cin >> Q[i].u;
        else
            cin >> Q[i].u >> Q[i].k;
    }*/
}

void DFSPreprocess(int u, int p) {
    par[u] = p;
    for (int v: g[u])
        if (v != p)
            DFSPreprocess(v, u);
}

void DFSUpdate(int u, int p, int val, int Case) {
    if (Case == 0)
        Val[u] += val;
    else
        Val[u] -= val;
    for (int v: g[u])
        if (v != p)
            DFSUpdate(v, u, val, 1 - Case);
}

void DFSGetAllNum(int u, int p, int k) {
    pq.push(Val[u]);
    for (int v: g[u])
        if (v != p)
            DFSGetAllNum(v, u, k);
}

void SolveSub1() {
    DFSPreprocess(1, -1);
    string cmd;
    int u, val, k;
    for (int i=1; i<=q; i++) {
        cin >> cmd;
        if (cmd == "add") {
            cin >> u >> val;
            DFSUpdate(u, par[u], val, 0);
        }
        if (cmd == "get") {
            cin >> u;
            cout << Val[u] << ' ';
        }
        if (cmd == "pos") {
            cin >> u >> k;
            while (!pq.empty())
                pq.pop();
            DFSGetAllNum(u, par[u], k);
            if (pq.size() < k)
                cout << "0 ";
            else {
                for (int i=1; i<k; i++)
                    pq.pop();
                cout << pq.top() << ' ';
            }
        }
    }
}

void SolveSub2() {
    for (int i=1; i<=q; i++)
        cout << "0\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("TREE.INP", "r", stdin);
    freopen("TREE.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cin >> q;
    if ((n <= 8000) && (q <= 8000))
        SolveSub1();
    else
        SolveSub2();
    return 0;
}
