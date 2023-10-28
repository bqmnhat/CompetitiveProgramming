#include <iostream>
#include <bits/stdc++.h>
#define MaxN 2000
#define NIL 0
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = INT_MAX;
class BipGraph
{
    int m, n;
    list<int> *adj;
    int *pairU, *pairV, *dist;

public:
    BipGraph(int m, int n);
    void addEdge(int u, int v);
    void Init();
    bool bfs();
    bool dfs(int u);
    int hopcroftKarp();
};

void BipGraph::Init() {
    adj = new list<int>[this->m + 1];
}

int BipGraph::hopcroftKarp() {
    pairU = new int[m+1];
    pairV = new int[n+1];
    dist = new int[m+1];
    for (int u=0; u<=m; u++)
        pairU[u] = NIL;
    for (int v=0; v<=n; v++)
        pairV[v] = NIL;
    int result = 0;
    while (bfs()) {
        for (int u=1; u<=m; u++)
            if (pairU[u]==NIL && dfs(u))
                result++;
    }
    return result;
}

bool BipGraph::bfs() {
    queue<int> Q;
    for (int u=1; u<=m; u++) {
        if (pairU[u]==NIL) {
            dist[u] = 0;
            Q.push(u);
        }
        else dist[u] = INF;
    }
    dist[NIL] = INF;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        if (dist[u] < dist[NIL]) {
            list<int>::iterator i;
            for (i=adj[u].begin(); i!=adj[u].end(); i++) {
                int v = *i;
                if (dist[pairV[v]] == INF) {
                    dist[pairV[v]] = dist[u] + 1;
                    Q.push(pairV[v]);
                }
            }
        }
    }
    return (dist[NIL] != INF);
}

bool BipGraph::dfs(int u) {
    if (u != NIL) {
        list<int>::iterator i;
        for (i=adj[u].begin(); i!=adj[u].end(); ++i) {
            int v = *i;
            if (dist[pairV[v]] == dist[u]+1) {
                if (dfs(pairV[v]) == true) {
                    pairV[v] = u;
                    pairU[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

BipGraph::BipGraph(int m, int n)
{
    this->m = m;
    this->n = n;
    adj = new list<int>[m+1];
}

void BipGraph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

pii a[MaxN+1];
int n, MatchR[MaxN+1], diri[4] = {0, -1, 0, 1}, dirj[4] = {-1, 0, 1, 0};
bool vis[MaxN+1];
map<pii, int> maID;
BipGraph g(MaxN+1, MaxN+1);

void ReadData() {
    maID.clear();
    for (int i=1; i<=n; i++) {
        cin >> a[i].first >> a[i].second;
        maID[a[i]] = i;
    }
}

void MakeG() {
    for (int i=1; i<=n; i++) {
        if ((a[i].first + a[i].second)&1)
            continue;
        int NxtX, NxtY;
        for (int t=0; t<4; t++) {
            NxtX = a[i].first + diri[t];
            NxtY = a[i].second + dirj[t];
            pii NxtP = pii(NxtX, NxtY);
            if (maID.find(NxtP) != maID.end()) {
                int NxtID = maID[NxtP];
                g.addEdge(i, NxtID);
            }
        }
    }
}

void Solve() {
    while (cin >> n) {
        ReadData();
        g.Init();
        MakeG();
        int ans = n - g.hopcroftKarp();
        cout << ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
