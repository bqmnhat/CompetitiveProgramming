#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct DSU {
    public:
        char parent[256];
        void make_set(char v) {
            if (parent[v] == 0)
                parent[v] = v;
        }
        char FindSet(char a) {
            if (parent[a] == 0)
                return -1;
            if (parent[a] == a)
                return a;
            return (parent[a] = FindSet(parent[a]));
        }
        void union_set(char a, char b) {
            a = FindSet(a);
            b = FindSet(b);
            if (a != b) {
                if (a > b)
                    swap(a,b);
                parent[b] = a;
            }
        }
} dsu;
string A,B,C;

void Solve() {
    for (int i=0; i<A.length(); i++)
        dsu.make_set(A[i]);
    for (int i=0; i<B.length(); i++) {
        dsu.make_set(B[i]);
        dsu.union_set(B[i], A[i]);
    }
    for (int i=0; i<C.length(); i++) {
        if (dsu.FindSet(C[i]) != -1)
            C[i] = dsu.FindSet(C[i]);
    }
    cout << C;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> A >> B >> C;
    Solve();
    return 0;
}
