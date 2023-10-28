#include <iostream>
#include <bits/stdc++.h>
#define MaxN 500000
#define MaxM 1000000
using namespace std;
typedef pair<int, int> pii;
int n, m;
set<pii> Edges;
unordered_set<int> Vertices;
vector<int> tmp;
vector<vector<int>> Sizes;
queue<int> q;

void ReadData() {
    for (int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v;
        Edges.insert(pii(min(u, v), max(u, v)));
    }
}

void BFS(int src) {
    q.push(src);
    Vertices.erase(Vertices.begin());
    Sizes.push_back({});
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        Sizes.back().push_back(u);
        tmp.clear();
        for (int v: Vertices) {
            auto ItFoundEdge = Edges.find(pii(min(u, v), max(u, v)));
            if (ItFoundEdge == Edges.end())
                tmp.push_back(v);
        }
        for (int v: tmp) {
            Vertices.erase(Vertices.find(v));
            q.push(v);
        }
    }
}

void Solve() {
    for (int i=1; i<=n; i++)
        Vertices.insert(i);
    while (!Vertices.empty())
        BFS((*Vertices.begin()));
    cout << Sizes.size() << '\n';
    for (int i=0; i<Sizes.size(); i++) {
        cout << Sizes[i].size() << ' ';
        for (int x: Sizes[i])
            cout << x << ' ';
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    Solve();
    return 0;
}
