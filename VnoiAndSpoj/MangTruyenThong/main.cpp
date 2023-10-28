#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100
using namespace std;
typedef long long ll;
bool InBetween[MaxN+1], vis[MaxN+1];
int n, k, a, b, d[MaxN+1][MaxN+1], dToInBetween[MaxN+1], par[MaxN+1];
vector<int> g[MaxN+1];

void ReadData() {
    int u , v;
    for (int i=1; i<n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void BFS(int src) {
    queue<int> q;
    d[src][src] = 0;
    par[src] = -1;
    q.push(src);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: g[u]) {
            if (v != par[u]) {
                d[src][v] = d[src][u] + 1;
                par[v] = u;
                q.push(v);
            }
        }
    }
}

void MakeD() {
    for (int i=1; i<=n; i++)
        BFS(i);
}

ll SolutionForSub1() {
    ll ans = 0;
    for (int i=1; i<=n; i++)
        for (int j=i+1; j<=n; j++)
            if ((d[i][j] >= a) && (d[i][j] <= b))
                ans++;
    return ans;
}

void DFSFindInBetweenNodes(int u, int v, int t) {// subtree root u
    if ((u == v) || (u == t))
        InBetween[u] = true;
    for (int x: g[u]) {
        if (x == par[u])
            continue;
        par[x] = u;
        DFSFindInBetweenNodes(x, v, t);
        InBetween[u] |= InBetween[x];
    }
}

ll SolutionForSub2() {
    ll ans = 0;
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            for (int t=j+1; t<=n; t++) {
                int len = 0;
                par[i] = -1;
                memset(InBetween, false, sizeof(InBetween));
                DFSFindInBetweenNodes(i, j, t);
                for (int l=1; l<=n; l++)
                    if (InBetween[l])
                        len++;
                len--;
                if ((len >= a) && (len <= b))
                    ans++;
            }
        }
    }
    return ans;
}

void BFSToInBetween() {
    queue<int> q;
    for (int i=1; i<=n; i++) {
        if (InBetween[i]) {
            dToInBetween[i] = 0;
            vis[i] = true;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: g[u]) {
            if (!vis[v]) {
                dToInBetween[v] = dToInBetween[u] + 1;
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

ll SolutionForSub3() {
    ll ans = 0;
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            for (int t=j+1; t<=n; t++) {
                int len = 0;
                par[i] = -1;
                memset(InBetween, false, sizeof(InBetween));
                DFSFindInBetweenNodes(i, j, t);
                for (int l=1; l<=n; l++)
                    if (InBetween[l])
                        len++;
                len--;
                memset(vis, false, sizeof(vis));
                BFSToInBetween();
                for (int l=1; l<=n; l++)
                    if ((l != i) && (l != j) && (l != t) && (len + dToInBetween[l] >= a) && (len + dToInBetween[l] <= b))
                        ans++;
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k >> a >> b;
    ReadData();
    MakeD();
    if (n <= 100) {
        if (k == 2)
            cout << SolutionForSub1();
        else if (k == 3)
            cout << SolutionForSub2();
        else
            cout << SolutionForSub3();
    }
    return 0;
}
