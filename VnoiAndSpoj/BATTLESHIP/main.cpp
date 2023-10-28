#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
int n, m, InWhichCC[MaxN+1], CCCnt = 0, Special[MaxN+1];
bool vis[MaxN+1];
vector<int> g[MaxN+1];

void ReadData() {
    for (int i=1; i<=m; i++)
        cin >> Special[i];
}

void Connect(int p) {
    int halfway = n/2;
    if (p <= halfway) {
        int pt1 = 1, pt2 = n;
        while (pt1 <= p-1) {
            g[pt1].push_back(pt2);
            g[pt2].push_back(pt1);
            pt1++;
            pt2--;
        }
        pt1 = p+1;
        pt2 = n - p + 1;
        while (pt1 <= pt2) {
            g[pt1].push_back(pt2);
            g[pt2].push_back(pt1);
            pt1++;
            pt2--;
        }
    }
    else {
        int pt1 = 1, pt2 = n;
        while (pt1 <= n - p) {
            g[pt1].push_back(pt2);
            g[pt2].push_back(pt1);
            pt1++;
            pt2--;
        }
        pt1 = n - p + 1;
        pt2 = p - 1;
        while (pt1 <= pt2) {
            g[pt1].push_back(pt2);
            g[pt2].push_back(pt1);
            pt1++;
            pt2--;
        }
    }
}

void MakeGraphSub1() {
    for (int i=1; i<=m; i++)
        Connect(Special[i]);
}

void MakeGraphSub2() {
    sort(Special + 1, Special + 1 + m);
    Connect(Special[1]);
    Connect(Special[m/2]);
    Connect(Special[m/2+1]);
    Connect(Special[m]);
}

void DFSCC(int u) {
    InWhichCC[u] = CCCnt;
    for (int v: g[u]) {
        if (!vis[v]) {
            vis[v] = true;
            DFSCC(v);
        }
    }
}

void Solve() {
    for (int i=1; i<=n; i++) {
        if (!vis[i]) {
            CCCnt++;
            vis[i] = true;
            DFSCC(i);
        }
        cout << InWhichCC[i] << ' ';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    if (m <= 2000)
        MakeGraphSub1();
    else
        MakeGraphSub2();
    Solve();
    return 0;
}
