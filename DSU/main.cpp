#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct DSU {
    public:
        int parent[1000001], rank_depth[1000001];
        void make_set(int v) {
            if (parent[v] == 0) {
                parent[v] = v;
                rank_depth[v] = 0;
            }
        }
        int FindSet(int a) {
            if (parent[a] == 0)
                return -1;
            if (parent[a] == a)
                return a;
            return (parent[a] = FindSet(parent[a]));
        }
        void union_set(int a, int b) {
            a = FindSet(a);
            b = FindSet(b);
            if (a != b) {
                if (rank_depth[a] < rank_depth[b])
                    swap(a,b);
                parent[b] = a;
                if (rank_depth[a] == rank_depth[b])
                    rank_depth[a]++;
            }
        }
} g;
int q;

void Solve() {
    for (int i=1; i<=q; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "ADD") {
            int u,v;
            cin >> u >> v;
            g.make_set(v);
            g.make_set(u);
            g.union_set(u,v);
        }
        else {
            int a,b;
            cin >> a >> b;
            a = g.FindSet(a);
            b = g.FindSet(b);
            if ((a != -1) && (b != -1) && (a == b))
                cout << "In The Same CC" << '\n';
            else
                cout << "Not In The Same CC" << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> q;
    Solve();
    return 0;
}
