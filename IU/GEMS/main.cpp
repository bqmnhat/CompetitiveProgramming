#include <iostream>
#include <bits/stdc++.h>
#define MaxN 17000000
using namespace std;
typedef long long ll;
int t, ans = 0, MaxGem[MaxN+1], nxt[MaxN+1], color[MaxN+1], CntVis, CntVisMain;
ll a, b, c, n;
bool vis[MaxN+1], visMain[MaxN+1];
stack<int> stkCycle2, stk, stkCycle;

void MakeGraph() {
    for (ll i=0LL; i<n; i++) {
        ll Nxt = ((a*(i*i))+(b*i)+c)%n;
        nxt[i] = Nxt;
        MaxGem[i] = 1;
        vis[i] = visMain[i] = false;
    }
}

void DFSCycle(int src, int col) {
    stk.push(src);
    stkCycle.push(src);
    while (!stk.empty()) {
        CntVis++;
        int u = stk.top();
        stk.pop();
        vis[u] = true;
        color[u] = col;
        stkCycle.push(u);
        int v = nxt[u];
        if (!vis[v])
            stk.push(v);
        else if (color[v] == col) {
            int tmp, cnt = 0;
            do {
                tmp = stkCycle.top();
                stkCycle.pop();
                stkCycle2.push(tmp);
                cnt++;
            } while (tmp != v);
            while (!stkCycle2.empty()) {
                int tmp = stkCycle2.top();
                visMain[tmp] = true;
                MaxGem[tmp] = cnt;
                stkCycle2.pop();
            }
        }
    }
    while (!stkCycle.empty())
        stkCycle.pop();
}

void DFS(int u) {
    if (visMain[u]) {
        CntVisMain++;
        return;
    }
    visMain[u] = true;
    int v = nxt[u];
    DFS(v);
    MaxGem[u] += MaxGem[v];
}

int Solution() {
    ans = 0;
    CntVis = CntVisMain = 0;
    for (int i=0; i<n; i++) {
        if (!vis[i])
            DFSCycle(i, i);
        if (CntVis == n)
            break;
    }
    for (int i=0; i<n; i++) {
        DFS(i);
        if (CntVisMain == n)
            break;
    }
    for (int i=0; i<n; i++)
        ans = max(ans, MaxGem[i]);
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        scanf("%d%d%d%d", &a, &b, &c, &n);
        MakeGraph();
        printf("%ld\n", Solution());
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.tie(0);
    scanf("%d", &t);
    Solve();
    return 0;
}
