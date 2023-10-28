#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MaxN 100000
#define Inf 1000000007
typedef pair<int,int> iPair;
int n, m, pre[MaxN+1];
list<iPair> a[MaxN+1];

void LoadGraph() {
    int u,v,w;
    for (int i=1; i<=m; i++) {
        cin >> u >> v >> w;
        a[u].push_back(make_pair(v,w));
        a[v].push_back(make_pair(u,w));
    }
}

void ShortestPath() {
    priority_queue <iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> d(n+1,Inf);
    d[1] = 0;
    pq.push(make_pair(0,1)); // 1 or source
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        list<iPair>::iterator i;
        for (i = a[u].begin(); i!= a[u].end(); i++) {
            int v = (*i).first, w = (*i).second;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pre[v] = u;
                pq.push(make_pair(d[v],v));
            }
        }
    }
    for (int j=1; j<=n; j++)
        cout << d[j] << '\n';
    cout << d[n];
}

int main()
{
    cin >> n >> m;
    LoadGraph();
    ShortestPath();
    return 0;
}
