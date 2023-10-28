#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m,zero = 0;
struct DSU {
    public:
        int parent[101], rd[101];
        void MakeSet(int v) {
            if (parent[v] == 0) {
                parent[v] = v;
                rd[v] = 0;
            }
        }
        int FindSet(int v) {
            if (parent[v] == 0)
                return -1;
            if (parent[v] == v)
                return v;
            return (parent[v] = FindSet(parent[v]));
        }
        void UnionSet(int u, int v) {
            u = FindSet(u);
            v = FindSet(v);
            if (u != v) {
                if (rd[u] < rd[v])
                    swap(u,v);
                parent[v] = u;
                if (rd[u] == rd[v])
                    rd[u]++;
            }
        }
} dsu;

void ReadData() {
    for (int i=1; i<=n; i++) {
        int k, prex;
        cin >> k;
        if (k == 0) zero++;
        for (int j=1; j<=k; j++) {
            int x;
            cin >> x;
            if (j == 1) {
                if (dsu.FindSet(x) == -1)
                    dsu.MakeSet(x);
                prex = x;
            }
            else {
                dsu.MakeSet(x);
                dsu.UnionSet(x, prex);
                prex = x;
            }
        }
    }
}

int Solution() {
    bool mark[101];
    int ans = 0;
    for (int i=1; i<=100; i++)
        mark[i] = false;
    for (int i=1; i<=m; i++) {
        int tmp = dsu.FindSet(i);
        if ((tmp != -1) && (mark[tmp] == false)) {
            ans++;
            mark[tmp] = true;
        }
    }
    if (ans == 0)
        ans++;
    return ((ans-1) + zero);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    cout << Solution();
    return 0;
}
