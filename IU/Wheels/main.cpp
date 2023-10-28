#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
typedef pair<int, int> pii;
struct Wheel {
    int x, y, r;
} a[MaxN+1];
int t, n;
bool IsClockWise[MaxN+1];
pii Ratio[MaxN+1];
vector<int> gr[MaxN+1];
bool vis[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i].x >> a[i].y >> a[i].r;
}

bool IsTouched(Wheel a, Wheel b) {
    double Dist = sqrt(1.0*1LL*(1LL*abs(a.x - b.x)*abs(a.x - b.x)) + 1LL*(1LL*abs(a.y - b.y)*abs(a.y - b.y)));
    double SumR = a.r + b.r;
    return (Dist == SumR);
}

void MakeGraph() {
    for (int i=1; i<=n; i++)
        gr[i].clear();
    for (int i=2; i<=n; i++) {
        for (int j=1; j<i; j++) {
            if (IsTouched(a[i], a[j])) {
                gr[i].push_back(j);
                gr[j].push_back(i);
            }
        }
    }
}

void DFS(int u, int p) {
    vis[u] = true;
    if ((u != 1) && (Ratio[p].first != -1)) {
        IsClockWise[u] = !IsClockWise[p];
        Ratio[u].first = Ratio[p].first * a[p].r;
        Ratio[u].second = Ratio[p].second * a[u].r;
        int GCD = __gcd(Ratio[u].first, Ratio[u].second);
        Ratio[u].first = Ratio[u].first/GCD;
        Ratio[u].second = Ratio[u].second/GCD;
    }
    for (auto v: gr[u]) {
        if (v == p)
            continue;
        if (!vis[v])
            DFS(v, u);
    }
}

void PrintAns() {
    for (int i=1; i<=n; i++) {
        if (Ratio[i].first == -1) {
            cout << "not moving" << '\n';
            continue;
        }
        cout << Ratio[i].first;
        if (Ratio[i].second != 1)
            cout << '/' << Ratio[i].second;
        cout << ' ';
        if (IsClockWise[i])
            cout << "clockwise";
        else
            cout << "counterclockwise";
        cout << '\n';
    }
}

void SolveTestCase() {
    for (int i=1; i<=n; i++) {

        IsClockWise[i] = vis[i] = false;
        Ratio[i].first = Ratio[i].second = -1;
    }
    IsClockWise[1] = true;
    Ratio[1] = pii(1,1);
    MakeGraph();
    DFS(1, -1);
    PrintAns();
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        SolveTestCase();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("WHEELS.INP", "r", stdin);
    freopen("WHEELS.OUT", "w", stdout);
    cin >> t;
    Solve();
    return 0;
}
