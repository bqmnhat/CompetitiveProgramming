#include <iostream>
#include <bits/stdc++.h>
#define INF 1000000001
using namespace std;
typedef pair<int, int> pii;
int s,c,dist[401], stid;
map<string, int> m;
vector<pii> g[401];
bool vis[401];
string st;

void ReadData() {
    for (int i=0; i<s; i++) {
        string s;
        cin >> s;
        m[s] = i;
    }
    for (int i=1; i<=c; i++) {
        string s1, s2;
        int w;
        cin >> s1 >> s2 >> w;
        int u = m[s1], v = m[s2];
        g[u].push_back(pii(v, w));
        g[v].push_back(pii(u, w));
    }
    cin >> st;
    stid = m[st];
}

void Init() {
    m.clear();
    for (int i=0; i<=s; i++) {
        g[i].clear();
        vis[i] = false;
        dist[i] = INF;
    }
}

void SolveTestCase() {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(pii(0, stid));
    dist[stid] = 0;
    while (!pq.empty()) {
        pii tmp = pq.top();
        pq.pop();
        int u = tmp.second;
        if (vis[u]) continue;
        vis[u] = true;
        for (auto i: g[u]) {
            int v = i.first, w = i.second;
            if ((!vis[v]) && (dist[v] > w)) {
                dist[v] = w;
                pq.push(pii(dist[v], v));
            }
        }
    }
    bool Impossible = false;
    int ans = 0;
    for (int i=0; i<s; i++) {
        if (vis[i] == false) {
            Impossible = true;
            break;
        }
        ans += dist[i];
    }
    if (Impossible)
        cout << "Impossible";
    else
        cout << ans;
    cout << '\n';
}

void Solve() {
    cin >> s >> c;
    while ((s != 0) || (c != 0)) {
        Init();
        ReadData();
        SolveTestCase();
        cin >> s >> c;
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
