#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10000
#define MaxVertices 6000000
using namespace std;
typedef pair<int, int> pii;
struct cmd {
    int i, k, id;
    char j;
}a[MaxN+1];
int n, pos, cnt = 0, ans;
bool vis[MaxN+1];
vector<pii> g[MaxVertices+1];
const int base = 3000000;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i].i >> a[i].j >> a[i].k;
        a[i].id = i;
    }
    cin >> pos;
}

void MakeGraph() {
    for (int i=1; i<=n; i++) {
        if (a[i].j == 'L')
            g[a[i].i + base].push_back(pii(a[i].i - a[i].k + base, a[i].id));
        else
            g[a[i].i + base].push_back(pii(a[i].i + a[i].k + base, a[i].id));
    }
}

void DFS(int u) {
    if (cnt == n) {
        ans = u;
        return;
    }
    for (pii v: g[u]) {
        if (!vis[v.second]) {
            vis[v.second] = true;
            cnt++;
            DFS(v.first );
        }
    }
}

void Solve() {
    DFS(pos + base);
    ans -= base;
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    MakeGraph();
    Solve();
    return 0;
}
