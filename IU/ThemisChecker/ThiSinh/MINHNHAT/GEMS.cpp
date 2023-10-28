#include <iostream>
#include <bits/stdc++.h>
#define MaxN 20000000
using namespace std;
typedef long long ll;
int t, ans = 0, MaxGem[MaxN+1], nxt[MaxN+1], color[MaxN+1];
ll a, b, c, n;
bool vis1[MaxN+1], vis2[MaxN+1];
stack<int> stk1, stk2;

void MakeGraph() {
    for (ll i=0; i<n; i++) {
        ll Nxt = ((a*(i*i))%n+(b*i)%n+c%n)%n;
        nxt[i] = Nxt;
        MaxGem[i] = 1;
        vis1[i] = vis2[i] = false;
    }
}

void DFSCycle(int u, int col) {
    vis2[u] = true;
    stk1.push(u);
    color[u] = col;
    int v = nxt[u];
    if (!vis2[v])
        DFSCycle(v, col);
    else {
        int tmp, cnt = 0;
        if (color[v] != col)
            return;
        do {
            tmp = stk1.top();
            stk1.pop();
            stk2.push(tmp);
            cnt++;
        } while((!stk1.empty()) && (tmp != v));
        if (tmp != v)
            return;
        while (!stk2.empty()) {
            MaxGem[stk2.top()] = cnt;
            vis1[stk2.top()] = true;
            stk2.pop();
        }
    }
}

void DFS(int u) {
    if (vis1[u])
        return;
    vis1[u] = true;
    int v = nxt[u];
    DFS(v);
    MaxGem[u] += MaxGem[v];
}

int Solution() {
    ans = 0;
    for (int i=0; i<n; i++)
        if (!vis2[i])
            DFSCycle(i, i);
    for (int i=0; i<n; i++) {
        DFS(i);
        ans = max(ans, MaxGem[i]);
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> a >> b >> c >> n;
        MakeGraph();
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("GEMS.INP", "r", stdin);
    freopen("GEMS.OUT", "w", stdout);
    cin >> t;
    Solve();
    return 0;
}
