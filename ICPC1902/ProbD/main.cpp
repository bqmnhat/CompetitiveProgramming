#include <bits/stdc++.h>
typedef long long i64;
#define MP(a,b) make_pair(a,b)

using namespace std;

// (u,v) = weight
map<int, map<int,i64>> graph1;
map<int, map<int,i64>> graph2;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        graph1[u][v] = graph1[v][u] = w;
        graph2[u][v] = graph2[v][u] = w;
    }

    vector<i64> dist(n, -1);
    // (timeSoFar, curNode)
    set<pair<i64,int>> pq; pq.insert(MP(0,0));
    while (!pq.empty()) {
        i64 timeSoFar = (*pq.begin()).first;
        int curNode = (*pq.begin()).second;
        pq.erase(pq.begin());
        if (dist[curNode] != -1) continue;
        dist[curNode] = timeSoFar;

        vector<int> die1;
        for (auto e1 : graph1[curNode]) {
            vector<int> die2;
            int neibor1 = e1.first;
            i64 w1 = graph1[curNode][neibor1];
            die1.push_back(neibor1);

            for (auto e2 : graph2[neibor1]) {
                int neibor2 = e2.first;
                if (dist[neibor2] != -1)
                    continue;
                i64 w2 = graph2[neibor1][neibor2];
                die2.push_back(neibor2);
                i64 totalCost = (w1 + w2) * (w1 + w2) + timeSoFar;
                pq.insert(MP(totalCost, neibor2));
            }

            // erase landing node
            for (auto byebye : die2) {
                graph2[neibor1].erase(byebye);
            }
        }

        // erase middle node
        for (auto byebye : die1) {
            graph1[curNode].erase(byebye);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << dist[i] << ' ';
    }
}
