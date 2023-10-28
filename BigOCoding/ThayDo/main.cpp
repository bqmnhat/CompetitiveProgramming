#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, n, a[10001];
struct DSU {
    public:
        int parent[1000001], rank_depth[1000001];
        void make_set(int v) {
            parent[v] = v;
            rank_depth[v] = 0;
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
} dsu;

void SolveTestCase() {
    for (int i=1; i<=n; i++) {
        dsu.make_set(i);
        cin >> a[i];
    }
    for (int i=1; i<=n; i++) {
        int m;
        cin >> m;
        for (int j=1; j<=m; j++) {
            int x;
            cin >> x;
            dsu.union_set(x, i);
        }
    }
    for (int i=1; i<=n; i++) {
        if (dsu.FindSet(a[i]) != dsu.FindSet(i)) {
            cout << "Pas bon";
            return;
        }
    }
    cout << "Bon travail";
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        SolveTestCase();
        cout << '\n';
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
