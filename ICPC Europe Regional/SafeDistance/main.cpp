#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct DSU {
    public:
        int parent[1000001];
        void make_set(int v) {
            parent[v] = v;
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
            if (a != b)
                parent[b] = a;
        }
} dsu;
int X,Y,n;
double x[1006], y[1006];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> x[i] >> y[i];
    y[n+1] = 0;
    y[n+2] = Y;
    x[n+3] = 0;
    x[n+4] = X;
}

void InitDSU() {
    for (int i=1; i<=n+4; i++)
        dsu.make_set(i);
}

bool CheckOverlap(double dis) {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n+4; j++) {
            if (i == j)
                continue;
            if ((j == n+1) || (j == n+2))
                x[j] = x[i];
            else if ((j == n+3) || (j == n+4))
                y[j] = y[i];
            double xDif = x[j] - x[i], yDif = y[j] - y[i];
            double d = sqrt((xDif*xDif) + (yDif*yDif));
            if (((j <= n) && (d < 2*dis)) || ((j > n) && (d < dis)))
                dsu.union_set(i,j);
        }
    }
    if (((dsu.FindSet(n+1) == dsu.FindSet(n+2)) || (dsu.FindSet(n+3) == dsu.FindSet(n+4)) || (dsu.FindSet(n+1) == dsu.FindSet(n+3))) || (dsu.FindSet(n+2) == dsu.FindSet(n+4)))
        return false;
    return true;
}

double Solution() {
    double lo = 0, hi = 1000000, ans;
    while (lo < hi) {
        if (hi - lo < 1e-6)
            break;
        InitDSU();
        double m = (lo + hi)/2.00;
        if (CheckOverlap(m))
            lo = m;
        else
            hi = m;
    }
    return lo;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> X >> Y >> n;
    ReadData();
    cout << fixed << setprecision(6) << Solution();
    return 0;
}
