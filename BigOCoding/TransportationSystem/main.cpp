#include <iostream>
#include <bits/stdc++.h>
#define INF 1000000001
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, double> pid;
typedef pair<double, int> pdi;
int t, n, r, path[1001];
double dist[1001];
pii cor[1001];
vector<pid> g[1001] ,mst[1001];
bool vis[1001];

void ReadData() {
    for (int i=0; i<n; i++)
        cin >> cor[i].first >> cor[i].second;
}

void MakeGraph() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i == j) continue;
            double w = sqrt((double(cor[j].first - cor[i].first) * double(cor[j].first - cor[i].first)) + (double(cor[j].second - cor[i].second) * double(cor[j].second - cor[i].second)));
            g[i].push_back(pid(j, w));
            g[j].push_back(pid(i, w));
        }
    }
}

void Init() {
    for (int i=0; i<=n; i++) {
        vis[i] = false;
        g[i].clear();
        mst[i].clear();
        dist[i] = INF;
    }
}

void Prim() {
    priority_queue<pdi, vector<pdi>, greater<pdi>> pq;
    pq.push(pdi(0, 0));
    dist[0] = 0;
    while (!pq.empty()) {
        pdi tmp = pq.top();
        pq.pop();
        int u = tmp.second;
        if (vis[u]) continue;
        vis[u] = true;
        for (pid i: g[u]) {
            int v = i.first;
            double w = i.second;
            if ((!vis[v]) && (dist[v] > w)) {
                dist[v] = w;
                path[v] = u;
                pq.push(pdi(dist[v], v));
            }
        }
    }
    for (int i=1; i<n; i++) {
        int u = path[i], v = i;
        mst[u].push_back(pid(v, dist[v]));
        mst[v].push_back(pid(u, dist[v]));
    }
}

void SolveTestCase() {
    int state = 1;
    double road = 0, rail = 0;
    stack<int> stk;
    stk.push(0);
    for (int i=0; i<=n; i++)
        vis[i] = false;
    while (!stk.empty()) {
        int u = stk.top();
        stk.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto i: mst[u]) {
            int v = i.first;
            double w = i.second;
            //cout << u << '-' << v << ": " << w;
            if (!vis[v]) {
                if (w > r) {
                    state++;
                    rail += w;
                }
                else
                    road += w;
                stk.push(v);
            }
        }
    }
    cout << state << ' ' << round(road) << ' ' << round(rail) << '\n';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> r;
        Init();
        ReadData();
        MakeGraph();
        Prim();
        cout << "Case #" << i << ": ";
        SolveTestCase();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
